#include "EthernetInterface.h"
#include "LCD_DISCO_F746NG.h"
#include "MbedJSONValue.h"
#include "client.h"
#include "lightsensor.h"
#include "mbed.h"
#include "mbed_trace.h"
#include "sound.h"
#include "temperature.h"
#include <cmath>

// Network interface
EthernetInterface net;
temperature temp = temperature();
SoundSensor soundSensor = SoundSensor();
LightSensor lightSensor = LightSensor();
DigitalOut blueLamp(D4);

int previousTemp = 0;

void threadTemp() {
  printf("temperature thread started\n");
  while (1) {
    temp.runSensor();
  }
}
void threadSound() {
  printf("sound thread started\n");
  while (1) {
    soundSensor.runSensor();
  }
}
void threadLight() {
  printf("light thread started\n");
  while (1) {
    lightSensor.runSensor();
  }
}
void sendTempData(TCPSocket *socket) {
  MbedJSONValue data;
  int sendingTemp = round(temp.getTemp());
  if (previousTemp != sendingTemp && previousTemp != 0) {
    std::string s;
    data["type"] = "temp";
    data["value"] = sendingTemp;
    data["room"] = "Z29A";
    data["building"] = "MU8";
    data["mbed_controller_id"] = "f746g@1";

    // serialize it into a JSON string
    s = data.serialize();
    // Send json.
    int scount = socket->send(s.c_str(), s.length());
    printf("sent data \n");

    previousTemp = sendingTemp;
    ThisThread::sleep_for(2s);
  } else {
    previousTemp = sendingTemp;
  }
}
void sendSoundData(TCPSocket *socket) {
  MbedJSONValue data;
  std::string s;
  data["type"] = "sound";
  data["value"] = soundSensor.getSoundValue();
  data["room"] = "Z29A";
  data["building"] = "MU8";
  data["mbed_controller_id"] = "f746g@1";

  // serialize it into a JSON string
  s = data.serialize();
  // Send json.
  int scount = socket->send(s.c_str(), s.length());
  printf("sent data \n");

  ThisThread::sleep_for(2s);
}
void sendLightData(TCPSocket *socket) {
  MbedJSONValue data;
  std::string s;
  data["type"] = "light";
  data["value"] = lightSensor.getLightValue();
  data["room"] = "Z29A";
  data["building"] = "MU8";
  data["mbed_controller_id"] = "f746g@1";

  // serialize it into a JSON string
  s = data.serialize();
  // Send json.
  int scount = socket->send(s.c_str(), s.length());
  printf("sent data \n");

  ThisThread::sleep_for(2s);
}

int main() {

  bool isConnected;
  LCD_DISCO_F746NG lcd;
  Thread tempthread;
  Thread soundThread;
  Thread lightThread;
  
  char text[30];
  SocketAddress a;
  net.get_ip_address(&a);
  net.connect();
  printf("mbed controller \n");

  // Open a socket on the network interface
  printf("connecting to socket server \n");

  TCPClient *tempClient = new TCPClient(&net, a);
  TCPClient *lightClient = new TCPClient(&net, a);
  TCPClient *soundClient = new TCPClient(&net, a);
  if(tempClient->getStatus() < 0 && lightClient->getStatus() < 0 && soundClient->getStatus() < 0){
      printf("could not connect");
      isConnected = false;
      return -1;
  }else{
      isConnected = true;
      blueLamp.write(1);

  }
  printf("starting temp thread... \n");
  tempthread.start(threadTemp);
  printf("starting sound thread... \n");
  soundThread.start(threadSound);
  printf("starting light thread... \n");
  lightThread.start(threadLight);

  while (isConnected) {
    sendTempData(tempClient->getSocket());
    sendSoundData(soundClient->getSocket());
    sendLightData(lightClient->getSocket());
  }
}

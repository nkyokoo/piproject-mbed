#include "EthernetInterface.h"
#include "LCD_DISCO_F746NG.h"
#include "MbedJSONValue.h"
#include "mbed.h"
#include "mbed_trace.h"
#include "temperature.h"


// Network interface
EthernetInterface net;
temperature temp = temperature();

void threadtemp() { temp.runSensor(); }
int main(void) {

  nsapi_size_or_error_t result;
  LCD_DISCO_F746NG lcd;
  Thread thread;
  char text[30];
  result = net.connect();
  printf("%d", result);

  // Show the network address
  SocketAddress a;
  net.get_ip_address(&a);
  printf("IP address: %s\n", a.get_ip_address() ? a.get_ip_address() : "None");
  sprintf(text, "IP: %s", a.get_ip_address() ? a.get_ip_address() : "None");
  lcd.DisplayStringAt(0, LINE(6), (uint8_t *)text, CENTER_MODE);

  // Open a socket on the network interface
  TCPSocket socket;
  socket.open(&net);
  a.set_ip_address("192.168.1.15");
  a.set_port(2080);
  result = socket.connect(a);
  if (result < 0) {
    printf("Error! socket->open() returned: %d\n", result);
    return result;
  }

  thread.start(threadtemp);

  // fill the object
  MbedJSONValue data;
  std::string s;
  data["type"] = "temp";
  data["value"] = temp.getTemp();
  char id[30];
  sprintf(id, "f746g@%s", a.get_ip_address());
  data["mbed_controller_id"] = id;

  // serialize it into a JSON string
  s = data.serialize();
  // Send json.
  int scount = socket.send(s.c_str(), s.length());
  printf("sent data");
}

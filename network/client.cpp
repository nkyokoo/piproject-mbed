#include "client.h"
#include "mbed.h"
#include "EthernetInterface.h"


TCPClient::TCPClient(EthernetInterface* net, SocketAddress a){
  socket.open(net);
  a.set_ip_address("192.168.1.12");
  a.set_port(2080);
  status = socket.connect(a);
}
void TCPClient::closeClient(){
  socket.close();
}
nsapi_size_or_error_t TCPClient::getStatus(){
    return status;
}
TCPSocket* TCPClient::getSocket(){
    return &socket;
}
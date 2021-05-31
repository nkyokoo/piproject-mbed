#include "client.h"
#include "mbed.h"
#include "EthernetInterface.h"


TCPClient::TCPClient(EthernetInterface* net, SocketAddress a){
  socket.open(net); // open a socket on network card
  a.set_ip_address("10.130.17.49"); // set socket address ip
  a.set_port(2080); // set port
  status = socket.connect(a); // connect socket with socket address and set return to status
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
#include "EthernetInterface.h"
#include "mbed.h"


class TCPClient {

public:
  TCPClient(EthernetInterface *net, SocketAddress a);

  void closeClient();

  TCPSocket *getSocket();

  nsapi_size_or_error_t getStatus();

private:
  TCPSocket socket;
  nsapi_size_or_error_t status;
};

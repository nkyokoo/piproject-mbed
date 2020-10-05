#include "EthernetInterface.h"
#include "mbed.h"


class TCPClient {

public:
/*
* constructor 
* creates socket connection on new object 
*
*
 */
  TCPClient(EthernetInterface *net, SocketAddress a);
/*
* closes connection
*
*
 */
  void closeClient();
/*
*   get status 
*   
*   @return TCPSocket*
*
 */
  TCPSocket* getSocket();
/*
*   get status 
*   
*   @return nsapi_size_or_error_t
*
 */
  nsapi_size_or_error_t getStatus();

private:
  TCPSocket socket;
  nsapi_size_or_error_t status;
};

#include "mbed.h"

// Network interface
NetworkInterface *net;

// Socket demo
int main() {
    int remaining;
    int rcount;
    char *p;
    char buffer[256];
    nsapi_size_or_error_t result;

    // Bring up the ethernet interface
    printf("Mbed OS Socket example\n");

#ifdef MBED_MAJOR_VERSION
    printf("Mbed OS version: %d.%d.%d\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
#endif

    net = NetworkInterface::get_default_instance();

    if (!net) {
        printf("Error! No network inteface found.\n");
        return 0;
    }

    result = net->connect();
    if (result != 0) {
        printf("Error! net->connect() returned: %d\n", result);
        return result;
    }

    // Show the network address
    SocketAddress a;
    net->get_ip_address(&a);
    printf("IP address: %s\n", a.get_ip_address() ? a.get_ip_address() : "None");
    net->get_netmask(&a);
    printf("Netmask: %s\n", a.get_ip_address() ? a.get_ip_address() : "None");
    net->get_gateway(&a);
    printf("Gateway: %s\n", a.get_ip_address() ? a.get_ip_address() : "None");

    // Open a socket on the network interface, and create a TCP connection to ifconfig.io
    TCPSocket socket;
    // Send a simple http request

    result = socket.open(net);


    socket.send("s",10);



 
}
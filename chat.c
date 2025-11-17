#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
    int sock_fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_addr={
        .sin_family=AF_INET,
        .sin_port=htons(9999),
        .sin_addr.s_addr=inet_addr("127.0.0.1")
    };

}
#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
    int server_fd=socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server_addr={
        .sin_family=AF_INET,
        .sin_port=htons(9999),
        .sin_addr.s_addr=inet_addr("127.0.0.1")
    };
    bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    listen(server_fd,10);
    printf("Currently waiting for the connection");
    int client_fd=accept(server_fd,NULL,NULL);
    printf("Client has connected");
    struct pollfd fds[2]={
        {.fd=STDIN_FILENO,.events=POLLIN},
        {.fd=client_fd,.events=POLLIN}
    };
    for(;;){
        char buffer[1024];
        poll(fds,2,-1);
        if(fds[0].revents & POLLIN){
            ssize_t bytes=read(STDIN_FILENO,buffer,sizeof(buffer)-1);
            if(bytes>0){
                send(client_fd,buffer,bytes,0);

            }
            
        }
    }



}
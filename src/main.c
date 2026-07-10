#include <stdio.h>
#include <sys/socket.h>   // socket(), bind(), listen(), accept()
#include <netinet/in.h>   // sockaddr_in, htons(), htonl(), INADDR_ANY
#include <arpa/inet.h>    // inet_ntoa(), inet_pton() тощо
#include <unistd.h>       // close(), read(), write()
#include <string.h>        // якщо використовуєш strlen(), memset() тощо

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;   // слухати на всіх інтерфейсах
    addr.sin_port = htons(7777);          // ОБОВ'ЯЗКОВО htons для порту
    
    int opt = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    
    listen(sockfd, 5);

    return 0;
}
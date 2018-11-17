/*
 * tcpclient.c - A simple TCP client
 * usage: tcpclient <host> <port>
 * Shamelessly stolen from https://www.cs.cmu.edu/afs/cs/academic/class/15213-f99/www/class26/tcpclient.c
 * and re-written by Z.C.T.
 * on 11.04.2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

/*
 * error - wrapper for perror
 */
void error(char *msg) {
    
    char buff[BUFSIZE];
    sprintf(buff, "#ERR >> %s ", msg);
    perror(buff);
    exit(0);
}

int main(int argc, char **argv) {
    
    int sockfd, portno, n;
    char *hostname;
    char buf[BUFSIZE];

    struct sockaddr_in serveraddr;
    struct hostent *server;
    
    // check command line arguments
    if (argc != 3) {
        fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }
    hostname = argv[1];
    portno = atoi(argv[2]);
    
    // socket: create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)  {
        error("can not create socket");
    }
    
    // gethostbyname: get the server's DNS entry
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERR : no such host as %s...\n", hostname);
        exit(0);
    }
    
    // build the server's Internet address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);
    
    // connect: create a connection with the server
    if (connect(sockfd, &serveraddr, sizeof(serveraddr)) < 0)
        error("can not connect");
    
    // get message line from the user
    printf("Please enter msg: ");
    bzero(buf, BUFSIZE);
    fgets(buf, BUFSIZE, stdin);
    
    //send the message line to the server
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
        error("can not send");
    
    // print the server's reply
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0)
        error("can not read");

    printf("Echo from server: %s", buf);
    close(sockfd);
    
    return 0;
}

#include "tcpserver.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int tcpServerStart(unsigned int port, unsigned int bufSize, int (*cb)(char *msg))
{
  int listenfd = 0, connfd = 0;
  struct sockaddr_in serv_addr;

  char msg[bufSize];
  char sendBuff[bufSize];
  char recvBuff[bufSize];

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(port);

  bind(listenfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

  listen(listenfd, 10);

  while(1)
  {
    connfd = accept(listenfd, (struct sockaddr*)NULL, NULL);

    bzero(recvBuff, bufSize);
    strcpy(msg, recvBuff);

    (*cb)(msg);

    close(connfd);
  }
}

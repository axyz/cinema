#ifndef TCPSERVER_H
#define TCPSERVER_H

int tcpServerStart(unsigned int port, unsigned int bufSize, int (*cb)(char *msg));

#endif

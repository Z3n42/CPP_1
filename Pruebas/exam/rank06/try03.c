#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

fd_set allfds;
fd_set readfds;
fd_set writefds;
int maxfd = 0;
int clientid = 0;
int clientFd[65536];
char *msg[65536];
char writebuff[1024];
char readbuff[1024];

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal_error(){

    write(2, "Fatal error\n", 12);
    exit(1);
}

void toSend(int connfd, char *writebuff){

    for(int fd = 0; fd <= maxfd; fd++){
        if(FD_ISSET(fd, &writefds) && fd != connfd)
            send(fd, writebuff, strlen(writebuff), 0);
    }
}

int main (int argc, char **argv){
    
    if(argc != 2){
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    int sockfd, connfd;

	// socket create and verification 
    FD_ZERO(&allfds);
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1)
        fatal_error(); 
    FD_SET(sockfd, &allfds);
	struct sockaddr_in servaddr; 
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

    // Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
        fatal_error();
	if (listen(sockfd, 10) != 0)
        fatal_error();
    
    maxfd = sockfd;
    while(1){
        writefds = readfds = allfds;
        if(select(maxfd+1, &readfds, &writefds, NULL, NULL) < 0)
            fatal_error();
        for(int fd = 0; fd <= maxfd; fd++){
            if(!FD_ISSET(fd, &readfds))
                continue;
            if(fd == sockfd){
                socklen_t len = sizeof(servaddr);
                connfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
                if(connfd >= 0){
                    if(connfd > maxfd)
                        maxfd = connfd;      
                    clientFd[connfd] = clientid++;
                    msg[connfd] = NULL;
                    FD_SET(connfd, &allfds);
                    sprintf(writebuff, "server: client %d just arrived\n", clientFd[connfd]);
                    toSend(connfd, writebuff);
                    break;
                }
                continue;
            }
            ssize_t bytesread = recv(fd, readbuff, 1024, 0);
            if(bytesread <=0){
                sprintf(writebuff, "server: client %d just left\n", clientFd[fd]);
                toSend(fd, writebuff);
                free(msg[fd]);
                msg[fd] = NULL;
                FD_CLR(fd, &allfds);
                close(fd);
                break;
            }
            readbuff[bytesread] = 0;
            msg[fd] = str_join(msg[fd], readbuff);
            char *tmp;
            while (extract_message(&msg[fd], &tmp)){
               sprintf(writebuff, "client %d: ", clientFd[fd]);
               toSend(fd, writebuff);
               toSend(fd, tmp);
               free(tmp);
               tmp = NULL;
            }
        }
    }
    return(0);
}
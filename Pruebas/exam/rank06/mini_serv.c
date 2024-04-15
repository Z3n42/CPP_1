#include <unistd.h>
#include <stdlib.h>
// #include <errno.h>
#include <string.h>
#include <stdio.h>
// #include <unistd.h>
// #include <netdb.h>
// #include <sys/socket.h>
#include <netinet/in.h>

fd_set fds;
fd_set readSet;
fd_set writeSet;
int maxFd = 0;
int clientId = 0;
int clientsFd[65536];
char *msg[65536];
char rbuff[1025];
char wbuff[1025];

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

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
	char *newbuf;
	int len;

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
    write(2, "Fatal Error\n", 12);
    exit(1);
}

void toSend(int origin, char *msg)
{
	for (int fd = 0; fd <= maxFd; fd++){
		if (FD_ISSET(fd, &writeSet) && fd != origin)
			send(fd, msg, strlen(msg), 0);
	}
}

int main(int argc, char* argv[]){

    if (argc != 2){
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

	int sockfd, connfd;
	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd < 0) 
		fatal_error(); 
	FD_ZERO(&fds);
	FD_SET(sockfd, &fds);
	struct sockaddr_in servaddr; 
	bzero(&servaddr, sizeof(servaddr)); 

    // assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); 

    // Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) == -1) 
		fatal_error(); 
    if (listen(sockfd, 10) != 0)
		fatal_error(); 

	maxFd = sockfd;
    while(1){
		writeSet = readSet = fds;
        if (select(maxFd + 1, &readSet, &writeSet, NULL, NULL) < 0)
            fatal_error(); 
        for (int fd = 0; fd <= maxFd; fd++){
            if(!FD_ISSET(fd, &readSet))
                continue;
            if(fd == sockfd){
                socklen_t addr_len = sizeof(servaddr);
                connfd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
                if (connfd >= 0){
					if (connfd > maxFd)
						maxFd = connfd;
					clientsFd[connfd] = clientId++;
					msg[connfd] = NULL;
					FD_SET(connfd, &fds);
					sprintf(wbuff, "server: client %d just arrived\n", clientsFd[connfd]);
					toSend(connfd, wbuff);
					break;
				}
				else{
					fatal_error();
					continue;
				}
			}
			ssize_t bytesRead = recv(fd, rbuff, sizeof(rbuff), 0);
			if(bytesRead <= 0){
				sprintf(wbuff, "server: client %d just left\n", clientsFd[connfd]);
				toSend(fd, wbuff);
				free(msg[fd]);
				msg[fd] = NULL;
				FD_CLR(fd, &fds);
				close(fd);
				break;
			}
			rbuff[bytesRead] = 0;
			msg[fd] = str_join(msg[fd], rbuff);
			char *tmp;
			while (extract_message(&(msg[fd]), &tmp)){
				sprintf(wbuff, "client %d: ", clientsFd[connfd]);
				toSend(fd, wbuff);
				toSend(fd, tmp);
				free(tmp);
				tmp = NULL;
			}	
		}
	}
return (0);
}
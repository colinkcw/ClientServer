#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>


char *get_ip(char *host);
char *build_get_query(char *host, char *page);

 

#define PAGE "/"
#define PORT 80
#define USERAGENT "HTMLGET 1.0"
 
int main(int argc, char **argv)
{
  struct sockaddr_in *remote;
  int sock;
  int tmpres;
  char *ip;
  char *get;
  char buf[BUFSIZ+1];
  char *host;
  char *page;
 

  char name[] = "localhost"; 
  host = name;
  char pagname[] = "a4/default.aspx?sqlstatement=select%20*%20from%20student"; 
  page = pagname;
  if((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0){
    perror("Can't create TCP socket");
    exit(1);
  }

  ip = get_ip(host);
  // allocate meomory for the structure, remote is a pointer to the struct
  remote = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
  remote->sin_family = AF_INET;
  //convert IPv4 and IPv6 addresses from text to binary form
  inet_pton(AF_INET, ip, (void *)(&(remote->sin_addr.s_addr)));

  remote->sin_port = htons(PORT);
 // connect the socket
  if(connect(sock, (struct sockaddr *)remote, sizeof(struct sockaddr)) < 0){
    perror("Could not connect");
    exit(1);
  }
  get = build_get_query(host, page);
 
  //Send the query to the server

  send(sock, get, strlen(get), 0);

  memset(buf, 0, sizeof(buf));
  int htmlstart = 0;
  char * htmlcontent;
  
  while((tmpres = recv(sock, buf, BUFSIZ, 0)) > 0){
    if(htmlstart == 0)
    {
      /* Under certain conditions this will not work.
      * If the \r\n\r\n part is splitted into two messages
      * it will fail to detect the beginning of HTML content
      */
      htmlcontent = strstr(buf, "\r\n\r\n");
      if(htmlcontent != NULL){
        htmlstart = 1;
        htmlcontent += 4;
      }
    }else{
      htmlcontent = buf;
    }
    if(htmlstart){
      fprintf(stdout, htmlcontent);
    }
 
    memset(buf, 0, tmpres);
  }
  if(tmpres < 0)
  {
    perror("Error receiving data");
  }
  free(get);
  free(remote);
  free(ip);
  close(sock);
  return 0;
}
 
 

 
 
char *get_ip(char *host)
{
  struct hostent *hent;
  int iplen = 15; //127.000.000.001
  char *ip = (char *)malloc(iplen+1);
  memset(ip, 0, iplen+1);
 hent = gethostbyname(host)

  inet_ntop(AF_INET, (void *)hent->h_addr_list[0], ip, iplen)

  return ip;
}
 
char *build_get_query(char *host, char *page)
{
  char *query;
  char *getpage = page;
  char *tpl = "GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
  // -5 is to consider the %s %s %s in tpl and the ending \0
  query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
  sprintf(query, tpl, getpage, host, USERAGENT);
  return query;
}
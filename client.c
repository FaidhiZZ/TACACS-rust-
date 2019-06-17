#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 3333
#define ADDRESS "192.168.0.107"

int main()
{
  int sock;
  struct sockaddr_in client;
  char send_data[100];
  char send_pass[100];

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock == -1){
    printf("Socket creation failed\n");
    exit(1);
  }

  memset(&client, 0, sizeof(client));
  client.sin_family = AF_INET;
  client.sin_addr.s_addr = inet_addr(ADDRESS);
  client.sin_port = htons(PORT);

  if(connect(sock, (struct sockaddr*)&client, sizeof(client)) == -1){
    perror("Connection failed");
    exit(1);
  }
  else{
    printf("Connected successfully\n\n");
  }

  memset(send_data, 0, sizeof(send_data));
  printf("Enter username: ");
  scanf("%s",send_data);
  strcat(send_data,"\n");
  send(sock, send_data, strlen(send_data),0);

  memset(send_data, 0, sizeof(send_data));
  printf("Enter username: ");
  scanf("%s",send_data);
  strcat(send_data,"\n");
  send(sock, send_data, strlen(send_data),0);

  close(sock);
  return 0;
}

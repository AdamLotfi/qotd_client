#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>


int main(int argc, char *argv[]){

 int sockPelanggan ,port = 8080, status, countsend, countrecv;
 struct sockaddr_in pelayan;
 char message[2000] , terima[2000] , temp;

 sockPelanggan = socket(AF_INET, SOCK_STREAM, 0);

  if(sockPelanggan < 0){
   printf("bala bala.. socket x jadi\n");
  }
  else{
  printf("socket setel.. Next..\n");
  }

 pelayan.sin_family = AF_INET;
 pelayan.sin_addr.s_addr = inet_addr("192.168.56.102");
 pelayan.sin_port = htons(port);

 status = connect(sockPelanggan, (struct sockaddr *)&pelayan, sizeof(pelayan));

  if(status == -1){
   printf("Aduu...xleh connect lak \n");
   perror("ERROR");
  }
  else{
   printf("Bek ah.. leh connect!!  \n");
  }

 while(strncmp(terima , "berhenti", 8) != 0){

  printf("Dari Pelanggan: ");
  scanf("%c", &temp);
  scanf("%[^\n]", message);


  countsend = send(sockPelanggan, message, strlen(message), 0);

  memset(terima,0,1000);


  if(countsend < 0){
   printf("message sangkut\n");
   return 1;
  }

 countrecv = recv(sockPelanggan, terima, 2000, 0);

  if (countrecv < 0){
   printf("xleh recieve la pulak..hmm... \n");
  }

 printf("Kata-kata dari pelayan: ");
 puts(terima);


 }

close(sockPelanggan);
}

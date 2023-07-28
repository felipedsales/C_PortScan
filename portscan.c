#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
//
int main (int argc, char *argv[]){
	int meusocket;
	int conecta;
	
	int porta;
	int inicio= 0;
	int final= 65535;
	char *destino;
	destino= argv[1];

	struct sockaddr_in alvo;
	
	for(porta=inicio;porta<final;porta++){
	
	meusocket = socket(AF_INET,SOCK_STREAM,0);//Estrutura para usar o socket
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(porta); //Recebe a Porta
	alvo.sin_addr.s_addr = inet_addr(destino);//Recebe o Endereço IP

	conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);//Estrutura do Connect

	if (conecta == 0){
		printf("Porta %d - status [ABERTA] \n",porta);
		close(meusocket);//Encerra a conexão
		close(conecta);//Encerra a conexão
	}else{
		close(meusocket);
		close(conecta);
	}
	}
}

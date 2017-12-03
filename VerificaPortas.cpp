#include <stdio.h>
#include <netdb.h>

void verifica_porta(char ip[],int porta)
{
	int m_socket;
	int conecta;
	
	struct sockaddr_in alvo;
	m_socket = socket(AF_INET, SOCK_STREAM, 0); // Tipo de Endereço AF_IFNET (Internet Protocol v4 addresses)
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(porta);
    alvo.sin_addr.s_addr = inet_addr(ip);
    
    conecta = connect(m_socket, (struct sockaddr *)&alvo,sizeof alvo);
	
	if(conecta == 0)
	{
		printf("IP: %s Porta: %d | Porta Aberta\n",ip,porta);
		close(m_socket);
		close(conecta);	
	}	else
	{
		printf("IP: %s Porta: %d | Porta Fechada\n",ip,porta);	
			close(m_socket);
		close(conecta);	
}
}

void ler_arquivo()
{
		FILE *file;
	
	file = fopen("table.txt","r");
	
	char ip[40];
	int porta;
	while(fscanf(file,"%s %d\n", ip,porta)!= EOF)
	{
		
		verifica_porta(ip,porta);
	}
	
}

int main(){
	
printf("\t-= By Rafael Faustini =-\n");
printf("Modelo do .txt\n");
printf("\t IP PORTA\n");

	
	

	}

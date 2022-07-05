#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	/*
	four stages on client socket
	1.creation
	2. connect
	3. receive
	4. close
	*/
	//creation of socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	//connect
	int connection_status = connect(network_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (connection_status == -1)
	{
		printf("There was an error making a connection to the remote socket");
	}

	//receiving data from server
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response, 0));
	printf("The server sent the data %s", server_response);

	//close the socket
	close(network_socket);
	return 0;
}
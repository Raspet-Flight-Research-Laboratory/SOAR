#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <iomanip>
#include "rfrl.hpp"


#pragma comment(lib,"Ws2_32.lib")


/***********************************************************************************************************************************
*
* Author: Nathaniel Childers			Date: 07/16/2024
*
* Purpose: This code file and its associated .hpp implement a rfrl development library. The initial purpose of this library is to
* build a library for establishing simple socket connections on the localhost. 
*
***********************************************************************************************************************************/


namespace rfrl {

	// *****************************************************************************************************************************
	// Define a function to handle errors thrown by winsock functions
	int err(const int retVal, const std::string msg) {

		// Check for a 0 (success), if not found, print the error and exit
		if (retVal != 0) {
			std::cout << msg << " ERRNO: " << WSAGetLastError() << std::endl;
			WSACleanup();
			exit(EXIT_FAILURE);
		}

		return retVal;
	}


	// *****************************************************************************************************************************
	// Define a function to check if a socket is valid <- ALMOST A CARBON COPY OF ERR(...)
	long long unsigned int socketErr(const SOCKET socketVal, const std::string msg) {

		// Check the socket against INVALID_SOCKET
		if (socketVal == INVALID_SOCKET || socketVal == SOCKET_ERROR) {
			std::cout << msg << " ERRNO: " << WSAGetLastError() << std::endl;
			closesocket(socketVal);
			WSACleanup();
			exit(EXIT_FAILURE);
		}

		return socketVal;
	}


	// *****************************************************************************************************************************
    // Define a function to start up WSA
    void startProtocol() {

		WSADATA wsaData;
        err(WSAStartup(MAKEWORD(2, 2), &wsaData), "* ERROR * Failed to start WSA");
    }


	// *****************************************************************************************************************************
	// Define a function to build a TCP server socket
	SOCKET buildTCPServerSocket(const unsigned short int port) {

		// Address structure for building sockets
		struct sockaddr_in* serverAddr = new struct sockaddr_in;


		// Create a socket for accepting data
		SOCKET listenSocket = INVALID_SOCKET;
		listenSocket = socketErr(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), "* ERROR * Failed to create listening socket."); // Using IPV4 and TCP protocols


		// Assign the sockaddr structure's members
		serverAddr->sin_family = AF_INET; // IPV4
		InetPton(AF_INET, __TEXT("127.0.0.1"), &serverAddr->sin_addr.s_addr); // Localhost
		serverAddr->sin_port = htons(port);

		// Bind the listening socket
		err(bind(listenSocket, (sockaddr*)serverAddr, sizeof(struct sockaddr_in)), "* ERROR * Failed to bind the socket.");


		// Listen with the newly bound socket and accepts a connection if one is found (CREATES A NEW SOCKET)
		SOCKET sendSocketDesc = INVALID_SOCKET;
		err(listen(listenSocket, 1), "* ERROR * Failed to listen with the server socket.");
		sendSocketDesc = socketErr(accept(listenSocket, nullptr, nullptr), "* ERROR * Failed to create accepting socket.");
		std::cout << "Accepted socket No. " << sendSocketDesc << std::endl;
		closesocket(listenSocket); // No longer needed.


		// Delete the heap memory and clean up
		delete serverAddr;
		return sendSocketDesc;
	}


	// *****************************************************************************************************************************
	// Define a function to build a TCP client socket
	SOCKET buildTCPClientSocket(const unsigned short int port) {

		// Address structure for building sockets
		struct sockaddr_in* clientAddr = new struct sockaddr_in;


		// Create a socket for accepting data
		SOCKET sendSocketDesc = INVALID_SOCKET;
		sendSocketDesc = socketErr(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), "* ERROR * Failed to create client socket."); // Using IPV4 and TCP protocols


		// Assign the sockaddr structure's members
		clientAddr->sin_family = AF_INET; // IPV4
		InetPton(AF_INET, __TEXT("127.0.0.1"), &clientAddr->sin_addr.s_addr); // Localhost
		clientAddr->sin_port = htons(port);


		// Try to connect to the server
		err(connect(sendSocketDesc, (sockaddr*)clientAddr, sizeof(struct sockaddr_in)), "* ERROR * Failed to connect to the server");
		std::cout << "Connected..." << std::endl;

		// Delete the heap memory and clean up
		delete clientAddr;
		return sendSocketDesc;
	}


	// *****************************************************************************************************************************
	// Define a function to read data from a client socket
	void serverRead(const SOCKET clientSocketDesc) {

		char buffer[4096]; // Buffer for reding from the client
		memset(buffer, '\0', 4096); // Initialize the memory to \0


		// Loop and read until the client is done sending data
		while (socketErr(recv(clientSocketDesc, buffer, 4096, 0), "* ERROR * Failed to recieve data from client.") > 0) {
			std::cout << buffer << std::endl;
		}
	}


	// *****************************************************************************************************************************
	// Define a function to write data to a server socket
	void clientWrite(const SOCKET clientSocketDesc) {

		char buffer[4096]; // Buffer for reding from the client
		memset(buffer, '\0', 4096); // Initialize the memory to \0

		
		// Send some test data
		for (int i = 0; i < 10; ++i) {
			socketErr(send(clientSocketDesc, "This is some test data", 23, 0), "* ERROR * Failed to send the data to the server.");
		}
	}
}
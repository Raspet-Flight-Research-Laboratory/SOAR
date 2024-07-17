#include <string>
#pragma once


// Definitions for rfrl.cpp
namespace rfrl {
	int err(const int retVal, const std::string msg);
	long long unsigned int socketErr(SOCKET socketVal, const std::string);
	SOCKET buildTCPServerSocket(const unsigned short int port);
	SOCKET buildTCPClientSocket(const unsigned short int port);
	void serverRead(const SOCKET serverSocketDesc);
	void clientWrite(const SOCKET clientSocketDesc);
    void startProtocol();
}
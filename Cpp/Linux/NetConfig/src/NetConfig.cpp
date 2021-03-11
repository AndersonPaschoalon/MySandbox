//============================================================================
// Name        : NetConfig.cpp
// Author      : Anderson Paschoalon
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//using namespace std;
//
//int main() {
//	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
//	return 0;
//}
#define _GNU_SOURCE
#include <ifaddrs.h>
#include <netpacket/packet.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define CHAR_BUFFER 120

int printLocalIfIp();
int getLocalIfIp(char* interface, char* ipaddr);
int getLocalIp(const char* interface, char* ipaddr);

int main(int argc, char *argv[]) {
	char ethernetIf[CHAR_BUFFER];
	char ipAddr[CHAR_BUFFER];
	int retVal = 0;

	retVal = getLocalIfIp(ethernetIf, ipAddr);
	if (retVal == 0) {
		printf("%s::%s\n", ethernetIf, ipAddr);
	} else {
		printf("Failed to retrieve IP and interface\n");
	}

	retVal = getLocalIp("enp3s0", ipAddr);
	if (retVal == 0) {
		printf("enp3s0::%s\n", ipAddr);
	} else {
		printf("Failed to retrieve IP and interface\n");
	}

	retVal = getLocalIp("veth0", ipAddr);
	if (retVal == 0) {
		printf("veth0::%s\n", ipAddr);
	} else {
		printf("Failed to retrieve IP and interface\n");
	}
	return (0);
}

int getLocalIfIp(char* interface, char* ipaddr) {
	struct ifaddrs *ifaddr, *ifa;
	int family, s;
	char host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		return (-1);
	}

	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {

		if (ifa->ifa_addr == NULL)
			continue;

		s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host,
		NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

		if ((strcmp(ifa->ifa_name, "lo") != 0)
				&& (ifa->ifa_addr->sa_family == AF_INET)) {
			if (s != 0) {
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				return (-2);
			}
			strcpy(interface, ifa->ifa_name);
			strcpy(ipaddr, host);
			break;
		}
	}

	freeifaddrs(ifaddr);
	return (0);
}

int getLocalIp(const char* interface, char* ipaddr) {
	struct ifaddrs *ifaddr, *ifa;
	int family, s;
	char host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		return (-1);
	}

	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {

		if (ifa->ifa_addr == NULL)
			continue;

		s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host,
		NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

		//if ((strcmp(ifa->ifa_name, "lo") != 0) && (ifa->ifa_addr->sa_family == AF_INET))
		if ((strcmp(ifa->ifa_name, interface) == 0)
				&& (ifa->ifa_addr->sa_family == AF_INET)) {

			if (s != 0) {
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				return (-2);
			}

			strcpy(ipaddr, host);
			break;
		}
	}

	freeifaddrs(ifaddr);
	return (0);
}

int printLocalIfIp() {
	struct ifaddrs *ifaddr, *ifa;
	int family, s;
	char host[NI_MAXHOST];

	if (getifaddrs(&ifaddr) == -1) {
		perror("getifaddrs");
		exit(EXIT_FAILURE);
	}

	unsigned int i = 0;
	for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {

		printf("i:%d\n", i);
		i++;

		if (ifa->ifa_addr == NULL)
			continue;

		s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host,
		NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

		// if((strcmp(ifa->ifa_name,"wlan0")==0)&&(ifa->ifa_addr->sa_family==AF_INET))
		if ((ifa->ifa_addr->sa_family == AF_INET)) {
			if (s != 0) {
				printf("getnameinfo() failed: %s\n", gai_strerror(s));
				exit(EXIT_FAILURE);
			}
			printf("\tInterface : <%s>\n", ifa->ifa_name);
			printf("\t  Address : <%s>\n", host);
		}
	}

	freeifaddrs(ifaddr);
	exit(EXIT_SUCCESS);
}

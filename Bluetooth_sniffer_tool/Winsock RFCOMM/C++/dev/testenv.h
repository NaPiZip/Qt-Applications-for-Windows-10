/*!
* \file testenv.h
*
* \author Nawin Piffel
* \date   12/16/2018
*
* This file is used in order to test the Bluetooth functionality of the WINSOCK 
* and Bluetootapi library. The first step consists of making sure the following
* tasks are achievable:
*	- Scanning for available Bluetooth devices
*	- Extracting device information
*	- Pairing with a device
*	- Sniffing traffic
*/
#ifndef TESTENV_HEADER
#define TESTENV_HEADER

#include <winsock2.h>

void WSALookupAvailableDevices(void);
void DiscoverDevices(void);
void DiscoverRadio(void);
bool GetActiveConnectionAddressInfo(const PCSADDR_INFO pcsAddrInfo);

void Playground(void);
#endif // !TESTENV_HEADER

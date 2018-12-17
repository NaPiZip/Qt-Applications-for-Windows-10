/*!
* \file testenv.cpp
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

#include "testenv.h"

#include <stdio.h>
#include <initguid.h>
#include <winsock2.h>
#include <ws2bth.h>
#include <strsafe.h>
#include <intsafe.h>
#include <bluetoothapis.h>


/*!
* \brief WSALookupAvailableDevices
*
* This function queries all available devices on the current machine, using the ws2bth API and prints
* the search results.
*
* \param[in]	None
* \param[out]	None
* \return		None
* \sa For detail see: https://docs.microsoft.com/en-us/windows/desktop/Bluetooth/bluetooth-and-wsalookupservicebegin-for-device-inquiry
* \note The function is not printing all available devices only the ones the local machine is paird with, no clue why.
* \warning		None
*/
void WSALookupAvailableDevices(void)
{
	WSAQUERYSET		wsaQuery{};
	LPWSAQUERYSET	pwsaResults{};
	HANDLE			hLookup{};
	
	CSADDR_INFO		*pAddrInfo{};
	SOCKADDR_BTH	*pBtSockRemote{}, 
					*pBtSockLocal{};

	char	buffer[4096] = {};
	int		nDevicesFound = 1;
	DWORD	swSize = sizeof(buffer);
	DWORD	flags = LUP_RETURN_ADDR | LUP_RETURN_NAME | LUP_RES_SERVICE | LUP_CONTAINERS | LUP_RETURN_BLOB | LUP_RETURN_TYPE;
	
	/*Preparing the query set*/
	wsaQuery.dwNameSpace = NS_BTH;
	wsaQuery.dwSize = sizeof(WSAQUERYSET);


	if (WSALookupServiceBegin(&wsaQuery, flags, &hLookup) == SOCKET_ERROR)
	{
		wprintf(L"Shit something went wrong! error: %d!\n", WSAGetLastError());
		return;
	}
	
	wprintf(L"*********************\n");
	wprintf(L"Winsock search started!\n");
	wprintf(L"*********************\n\n");


	/*Preparing the queryset return buffer*/
	pwsaResults = (LPWSAQUERYSET)buffer;
	pwsaResults->dwNameSpace = NS_BTH;
	pwsaResults->dwSize = sizeof(WSAQUERYSET);

	while (WSALookupServiceNext(hLookup, flags, &swSize, pwsaResults) == NO_ERROR)
	{
		pAddrInfo		= (CSADDR_INFO*)pwsaResults->lpcsaBuffer;
		pBtSockRemote	= (SOCKADDR_BTH*)(pwsaResults->lpcsaBuffer->RemoteAddr.lpSockaddr);
		pBtSockLocal	= (SOCKADDR_BTH*)(pwsaResults->lpcsaBuffer->LocalAddr.lpSockaddr);

		wprintf(L"Device #:%d\n", nDevicesFound);
		wprintf(L"Device name:%s\n", pwsaResults->lpszServiceInstanceName);
		wprintf(L"Device connected: %d\n", (pwsaResults->dwOutputFlags & BTHNS_RESULT_DEVICE_CONNECTED));
		wprintf(L"Device remembered: %d\n", (pwsaResults->dwOutputFlags & BTHNS_RESULT_DEVICE_REMEMBERED)>0);
		wprintf(L"Device authenticated: %d\n", (pwsaResults->dwOutputFlags & BTHNS_RESULT_DEVICE_AUTHENTICATED)>0);
		wprintf(L"Remote Bluetooth device is 0x%04x%08x, server channel = %d\n",
			GET_NAP(pBtSockRemote->btAddr), GET_SAP(pBtSockRemote->btAddr), pBtSockRemote->port);
		wprintf(L"Local Bluetooth device is 0x%04x%08x, server channel = %d\n",
			GET_NAP(pBtSockLocal->btAddr), GET_SAP(pBtSockLocal->btAddr), pBtSockLocal->port);

		nDevicesFound++;

	}
	WSALookupServiceEnd(hLookup);
	wprintf(L"\n");
}

/*!
* \brief DiscoverDevices
*
* This function queries all available devices on the current machine, using the bluetoothapis API and prints
* the search results.
*
* \param[in]	None
* \param[out]	None
* \return		None
* \sa For detail see: https://docs.microsoft.com/en-us/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstdevice
* \note The function is not printing all available devices only the ones the local machine is paird with, no clue why.
* \warning		None
*/
void DiscoverDevices(void)
{
	BLUETOOTH_DEVICE_SEARCH_PARAMS	btSearchParam{};
	BLUETOOTH_DEVICE_INFO			btDeviceInfo{};
	HBLUETOOTH_DEVICE_FIND			hBtDevice{};


	/*Setting search parameter for discovery*/
	btSearchParam.dwSize = sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS);
	btSearchParam.fIssueInquiry = TRUE;

	btSearchParam.fReturnAuthenticated	= TRUE;
	btSearchParam.fReturnUnknown		= TRUE;
	btSearchParam.fReturnConnected		= TRUE;	
	btSearchParam.fReturnRemembered		= FALSE;
	btSearchParam.cTimeoutMultiplier	= 2;


	btDeviceInfo.dwSize = sizeof(BLUETOOTH_DEVICE_INFO);

	hBtDevice = BluetoothFindFirstDevice(&btSearchParam, &btDeviceInfo);
	if (hBtDevice)
	{
		wprintf(L"*********************\n");
		wprintf(L"Bluetoothapi device search started!\n");
		wprintf(L"*********************\n\n");

		wprintf(L"Device name: %s\n", btDeviceInfo.szName);

		while(BluetoothFindNextDevice(hBtDevice, &btDeviceInfo))
		{
			wprintf(L"Device name: %s\n", btDeviceInfo.szName);
		}
		BluetoothFindDeviceClose(hBtDevice);
	}
	else
	{
		wprintf(L"Error finding first device %d\n", GetLastError());
	}
	wprintf(L"\n");
}

/*!
* \brief DiscoverRadio
*
* This function queries the first radio device found on the host and prints its name.
*
* \param[in]	None
* \param[out]	None
* \return		None
* \sa For detail see: https://docs.microsoft.com/en-us/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothfindfirstradio
* \note 
* \warning		None
*/
void DiscoverRadio(void)
{
	BLUETOOTH_FIND_RADIO_PARAMS		btSearchParam{ };
	HBLUETOOTH_RADIO_FIND			hFindRadio{};
	HANDLE							hFirstRadio{};


	btSearchParam.dwSize = sizeof(BLUETOOTH_FIND_RADIO_PARAMS);

	hFindRadio = BluetoothFindFirstRadio(&btSearchParam, &hFirstRadio);
	if (hFindRadio)
	{
		BLUETOOTH_RADIO_INFO btRadioInfo{};
		btRadioInfo.dwSize = sizeof(BLUETOOTH_RADIO_INFO);

		wprintf(L"*********************\n");
		wprintf(L"Bluetoothapi radio search started!\n");
		wprintf(L"*********************\n\n");

		if (BluetoothGetRadioInfo(hFirstRadio, &btRadioInfo) == ERROR_SUCCESS)
		{
			wprintf(L"Radio name: %s\n", btRadioInfo.szName);
			wprintf(L"Is this device discoverable? %d\n", BluetoothIsDiscoverable(hFirstRadio));
		}
		else
		{
			wprintf(L"Error finding first device %d\n", GetLastError());
		}

		BluetoothFindRadioClose(hFindRadio);
		CloseHandle(hFirstRadio);
		wprintf(L"\n");
	}
}
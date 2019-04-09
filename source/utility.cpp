#include "../include/utility.h"
#include "../include/imports.h"

void Sleep(unsigned int milliseconds) {
	sceKernelUsleep(milliseconds * 1000);
}

void ReadMemory(uint64_t address, void* buffer, int length) {
	memcpy(buffer, (void*)address, length);
}

void WriteMemory(uint64_t address, void* buffer, int length) {
	memcpy((void*)address, buffer, length);
}

void NOP(uint64_t address, size_t length) {
	unsigned char* nop_buffer = new unsigned char[length];
	memset(nop_buffer, 0x90, length);

	WriteMemory(address, nop_buffer, length);

	delete[] nop_buffer;
}

char byteArray[100];
char* ReadBytes(int address, int length)
{
	for (int i = 0; i < length; i++)
	{
		byteArray[i] = *(char*)(address + (i));
	}
	return byteArray;
}
char returnRead[100];
char* ReadString(int address)
{
	int strlength = 100;
	char* StrBytes = ReadBytes(address, strlength);
	for (int i = 0; i < strlength; i++)
	{
		if (StrBytes[i] != 0x00)
			returnRead[i] = StrBytes[i];
		else
			break;
	}
	return returnRead;
}

void printf(const char *fmt, ...) {
	char buffer[0x400] = { 0 };
	va_list args;
	va_start(args, fmt);
	vsprintf(buffer, fmt, args);

	int sock = sceNetSocket("PS4 Output", AF_INET, SOCK_STREAM, IPPROTO_TCP);

	struct sockaddr_in sockAddr = { 0 };
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = 29975;
	sockAddr.sin_addr.s_addr = 0x660A8C0; //IP Address

	sceNetConnect(sock, (struct sockaddr*)&sockAddr, sizeof(struct sockaddr_in));
	sceNetSend(sock, buffer, 0x400, 0);
	sceNetSocketClose(sock);

	va_end(args);
}//192.168.0.102
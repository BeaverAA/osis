#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <windows.h>
#include <tchar.h>
#include <iostream>

using namespace std;

void FindFileByClaster(TCHAR* volume, LONGLONG cluster) {
	HANDLE hDevice = CreateFile(volume, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
	
	if (hDevice == INVALID_HANDLE_VALUE) return;
	
	LOOKUP_STREAM_FROM_CLUSTER_INPUT input = { 0 };
	
	input.NumberOfClusters = 1;
	input.Cluster[0].QuadPart = cluster;
	
	BYTE output[5000] = {};
	DWORD dwRes = 0;
	LOOKUP_STREAM_FROM_CLUSTER_OUTPUT result = { 0 };
	BOOL bRes = DeviceIoControl((HANDLE)hDevice, FSCTL_LOOKUP_STREAM_FROM_CLUSTER, (LPVOID)&input, (DWORD)sizeof(input), (LPVOID)output, (DWORD)5000, (LPDWORD)&dwRes, NULL);
	
	if (bRes == FALSE) return;
	
	memcpy(&result, output, sizeof(LOOKUP_STREAM_FROM_CLUSTER_OUTPUT));

	if (result.NumberOfMatches == 0) {
		cout << "File not found\n";
		return;
	}

	BYTE* p = (BYTE*)output + result.Offset;
	LOOKUP_STREAM_FROM_CLUSTER_ENTRY* pentry = (LOOKUP_STREAM_FROM_CLUSTER_ENTRY*)p;
	wprintf(L"\nFile: %s\n", pentry->FileName);
}

int main() {
	LONGLONG inp = 0;
	printf_s("Enter cluster number:\n");
	scanf_s("%llu", &inp);

	FindFileByClaster((TCHAR*)L"\\\\.\\C:", inp);
	system("PAUSE");
}
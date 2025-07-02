// Default libs
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>	// Windows resourses API

// TODO: show process usage info 

// show main memory info
void printMemoryInfo();

int main(){		
	
	while(1){
		system("cls");
		printf("Memory RAM monitor\n");
		printf("--------------------\n");
		printMemoryInfo();
		printf("Press Ctr+C to exit...\n");
		Sleep(1000); // Update each 1 second				
	}
	return 0;
}

void printMemoryInfo(){
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	
	printf("\nTotal System Memory:\n");
	printf(" Total Physical Memory: %.2f MB\n", (float)memInfo.ullTotalPhys / (1024 * 1024));
	printf(" Physical Memory Available: %.2f MB\n", (float)memInfo.ullAvailPhys / (1024 * 1024));
	printf(" Memory In Use: %lu%%\n", memInfo.dwMemoryLoad);
}

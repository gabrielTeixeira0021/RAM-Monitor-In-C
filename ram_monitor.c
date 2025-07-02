#include <stdio.h>
#include <stdlib.h>
#include <windows.h>	
#include <psapi.h>

#define MB_CONVERSION 1048576.0f

// show process usage info 
void processUsage();

// show main memory info
void printMemoryInfo();

int main(){		
	printf("Memory RAM monitor\n");
	printf("--------------------\n");
	
	while(1){	
		system("cls");
		printMemoryInfo();
		printf("Press Ctr+C to exit...\n");
		Sleep(1000); // Update each 1 second				
	}
	return 0;
}

void processUsage(){
	PROCESS_MEMORY_COUNTERS_EX pmc;
	
	if(!GetProcessMemoryInfo(GetCurrentProcess(), 
	(PROCESS_MEMORY_COUNTERS*)&pmc, 
	sizeof(pmc))) {
		printf("ERROR getting process info!\n");
		return;
	}
	
	printf("Process Memory Usage:\n");
	printf(" Working Set: %.2f MB\n", (float)pmc.WorkingSetSize / MB_CONVERSION);
	printf(" Private Bytes: %.2f MB\n", (float)pmc.PrivateUsage / MB_CONVERSION);
}

void printMemoryInfo(){	
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	
	if(!GlobalMemoryStatusEx(&memInfo)) {
		printf("Error getting system memory info!\n");
		return;
	}
	
	
	printf("\nTotal System Memory:\n");
	printf(" Total Physical Memory: %.2f MB\n", (float)memInfo.ullTotalPhys / MB_CONVERSION);
	printf(" Physical Memory Available: %.2f MB\n", (float)memInfo.ullAvailPhys / MB_CONVERSION);
	printf(" Memory In Use: %lu%%\n", memInfo.dwMemoryLoad);
	
	// Shows process RAM memory usage
	processUsage();
}

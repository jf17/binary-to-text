#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// author : https://github.com/jf17

#define ERROR_FILE_OPEN -3

FILE *stream, *stream2;

void main() {
	 int max = 1024;
	int arr[1024];
	errno_t err;

	// Open for read (will fail if file "crt_fopen_s.c" does not exist)  
	err = fopen_s(&stream, "HV510.PAT", "rb");
	if (err == 0)
	{
		printf("The file 'HV510.PAT' was opened\n");
	}
	else
	{
		printf("The file 'HV510.PAT' was not opened\n");
	}

	for (int i = 0; i < max; i++){
	
		arr[i] = getc(stream);
	}

	

	// Close stream if it is not NULL   
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			printf("The file 'HV510.PAT' was closed\n");
		}
		else
		{
			printf("The file 'HV510.PAT' was not closed\n");
		}
	}
	int sadfsd = 0;


	// All other files are closed:  
	int numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall: %u\n", numclosed);
	_getch();
}
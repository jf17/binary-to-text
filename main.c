#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// author : https://github.com/jf17
#define ERROR_FILE_OPEN -3

FILE *stream, *stream2;

struct Map_int_char {
	int key;
	char value;
};


void main() {
	 int max = 1024;

	int arr[1024];
	char result[1024];

	errno_t err;

	// Open for read (will fail if file "HV510.BIN" does not exist)  
	err = fopen_s(&stream, "HV510.BIN", "rb");
	if (err == 0)
	{
		printf("The file 'HV510.BIN' was opened\n");



		for (int i = 0; i < max; i++) {

			arr[i] = getc(stream);
		}

		struct Map_int_char alphabet_array[47];
		alphabet_array[0].key = 240;
		alphabet_array[0].value = '0';

		alphabet_array[1].key = 241;
		alphabet_array[1].value = '1';

		alphabet_array[2].key = 242;
		alphabet_array[2].value = '2';

		alphabet_array[3].key = 243;
		alphabet_array[3].value = '3';

		alphabet_array[4].key = 244;
		alphabet_array[4].value = '4';

		alphabet_array[5].key = 245;
		alphabet_array[5].value = '5';

		alphabet_array[6].key = 246;
		alphabet_array[6].value = '6';

		alphabet_array[7].key = 247;
		alphabet_array[7].value = '7';

		alphabet_array[8].key = 248;
		alphabet_array[8].value = '8';

		alphabet_array[9].key = 249;
		alphabet_array[9].value = '9';


		for (int i = 0; i < max; i++) {

			for (int j = 0; j < 47; j++) {
				if (arr[i] == 0) { result[i] = '*'; }
				else if (arr[i] == alphabet_array[j].key) { result[i] = alphabet_array[j].value; }

			}
		}

	}
	else
	{
		printf("The file 'HV510.BIN' was not opened\n");
	}





	//==========================
	// WRITE 

	// Open for write   
	err = fopen_s(&stream2, "data2", "w+");
	if (err == 0)
	{
		printf("The file 'data2' was opened\n");
	}
	else
	{
		printf("The file 'data2' was not opened\n");
	}






	// Close stream if it is not NULL   
	if (stream)
	{
		err = fclose(stream);
		if (err == 0)
		{
			printf("The file 'HV510.BIN' was closed\n");
		}
		else
		{
			printf("The file 'HV510.BIN' was not closed\n");
		}
	}

	int sadfsd = 0; // stop debug 


	// All other files are closed:  
	int numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall: %u\n", numclosed);
	_getch();
}
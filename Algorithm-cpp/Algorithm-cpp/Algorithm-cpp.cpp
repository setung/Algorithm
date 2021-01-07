#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BRIGHT   "\x1b[1m"
#define clear() system("@cls||clear")


int main(int argc, char const* argv[]) {
	printf(ANSI_COLOR_BRIGHT);
	printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_BRIGHT "\n");
	printf(ANSI_COLOR_RESET);
	printf(ANSI_COLOR_BRIGHT);



#pragma region git tree
	int count = 1;
	// star
	printf("%31s", "\033[0;93m\u2721\n");
	printf("%30s", "\u2721 \u2606 \u2721\n");
	printf("%27s", "\u2721 \u2721\n");
	for (int i = 1; i < 8; i++) {
		for (int j = 21 - i; j > 0; j--) {
			printf(" ");
		}
		for (int k = i + i - 1; k > 0; k--) {
			if (count % 7 == 0)
				printf("\033[0;31m\u2b24");
			else if (count % 9 == 0)
				printf("\033[0;34m\e[5m*");
			else if (count % 11 == 0)
				printf("\033[0;97m\e[5m*");
			else
				printf("\033[0;32m*");
			count++;
		}
		printf("\n");
	}
	for (int i = 5; i < 15; i++) {
		for (int j = 21 - i; j > 0; j--) {
			printf(" ");
		}
		for (int k = i + i - 1; k > 0; k--) {
			if (count % 7 == 0)
				printf("\033[0;31m\u2b24");
			else if (count % 9 == 0)
				printf("\033[0;34m\e[5m*");
			else if (count % 11 == 0)
				printf("\033[0;97m\e[5m*");
			else
				printf("\033[0;32m*");
			count++;
		}
		printf("\n");
	}
	for (int i = 9; i < 22; i++) {
		for (int j = 21 - i; j > 0; j--) {
			printf(" ");
		}
		for (int k = i + i - 1; k > 0; k--) {
			if (count % 7 == 0)
				printf("\033[0;31m\u2b24");
			else if (count % 9 == 0)
				printf("\033[0;34m\e[5m*");
			else if (count % 11 == 0)
				printf("\033[0;97m\e[5m*");
			else
				printf("\033[0;32m*");
			count++;
		}
		printf("\n");
	}
	for (int i = 5; i > 0; i--) {
		for (int j = 17; j > 0; j--) {
			printf(" ");
		}
		for (int k = 7; k > 0; k--) {
			printf("\033[0;33m|\033[0m");
		}
		printf("\n");
	}
#pragma endregion
	
	//clear();

	return 0;
}
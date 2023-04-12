/* Lab Exercise 1
	Write a program to implement Horspool’s algorithm for String Matching and find
	the number of key comparisons in successful search and unsuccessful search
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* createTable(char*);
int strmatch(char*, char*);

int main() {
	char text[100], pat[100];
	int pos;

	printf("Enter the text string:\n");
	scanf(" %[^\n]s", text);

	printf("Enter the pattern string:\n");
	scanf(" %[^\n]s", pat);

	pos = strmatch(text, pat);

	if(pos < 0) {
		printf("Pattern not found in text...\n");
	}
	else {
		printf("Pattern found at position %d...\n", pos);
	}

	return 0;
}

int* createTable(char* str) {
	int* table = (int*) calloc(256, sizeof(int));
	int len = strlen(str);
	
	for(int i=0; i<256; i++) {
		table[i] = len;
	}

	for(int i=0; i<len-1; i++) {
		table[str[i]] = len-i-1;
	}

	return table;
}

int strmatch(char* text, char* pat) {
	int m = strlen(text);
	int n = strlen(pat);
	int opcount = 0;

	int* table = createTable(pat);

	int i = n-1;

	while(i<m) {
		int k = 0;

		while(++opcount && k<n && pat[n-1-k]==text[i-k]) {
			k++;
		}

		if(k == n) {
			printf("\nOperation Count: %d\n\n", opcount);
			return i-n+1;
		}
		else {
			i += table[text[i]];
		}
	} 

	printf("\nOperation Count: %d\n\n", opcount);
	return -1;
}

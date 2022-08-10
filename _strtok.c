#include "main.h"

/**
 * _strtok -  copies the string pointed to by src
 * @dest: char type string
 * @src: char type string
 * 
 */
char* _strtok(char* dest, char src)
{
	char* input = NULL;

	if (dest != NULL)
	input = dest;

	if (input == NULL)
	return NULL;

	char* result = new char[strlen(input) + 1];
	int i = 0;
 
	for (; input[i] != '\0'; i++) {
 
	if (input[i] != d)
		result[i] = input[i];
 
	else {
		result[i] = '\0';
		input = input + i + 1;
        	return result;
	}
    }
 
    result[i] = '\0';
    input = NULL;
 
    return result;
}
 
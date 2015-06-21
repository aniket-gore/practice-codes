#include<string.h>

bool palindrome (char *str) {
	char * start = str;
	char * end = str + strlen(str) - 1;
	while(*start == *end && start<end) {
		start++;
		end--;
	}
	if(*start != *end)
		return false;
	else
		return true;
}

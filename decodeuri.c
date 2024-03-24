#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	char* substr;
	char* sei; /* Substring ending index. */
	size_t rnum; /* Remaining number of elements. */
	
	substr = strstr(argv[1], "%20");
	while (substr != NULL) {
		sei = substr + 3;
		rnum = (argv[1] + strlen(argv[1])) - sei;
		memmove(substr+1, sei, rnum);
		substr[0] = ' ';
		memset(substr+1+rnum, '\0', 3);
		substr = strstr(argv[1], "%20");
	}
	printf("%s", argv[1]);
}

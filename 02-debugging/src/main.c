#include <spede/stdio.h>

/**
 * Returns the length of a NULL terminated string
 * @param str pointer to the string
 * @return value indicating the length of the string
 */
int strlen(char *str) {
    	int length =  0;
	while (str[length] != '\0')	// iterate through str while its value is not 0
	{
		length++;	// increment length value
	}
    	return length;		// altered return to length instead of 0
}

/**
 * Prints a string to the screen starting at 0, 0
 * @param str pointer to the string to print
 */
void puts(char *str) {
    if (!str) {		// change to !str from str (origional code with result in pprint NULL when str was not NULL
        printf("NULL pointer!\n");
        return;
    }

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        *((char *) (0xB8000 + (i * 2))) = str[i];
    }
}

/**
 * Main function
 */
void main(void) {
    char buf[128] = {0};
    int year = 2025;

    *((char *) 0xB8000) = 'W';

    printf("Hello, world!\n");
    printf("Welcome to %s!\n", OS_NAME);

    puts("Hello, World!\n");

    snprintf(buf, sizeof(buf), "welcome to %s!\n", OS_NAME);
    printf("The buffer size is %d bytes\n", strlen(buf));
    puts(buf);

    printf("CPE/CSC 159 for Spring/Fall %d will be fun!\n", year);
}

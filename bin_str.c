#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void string_printing(char *curr_char, char* str);
void bin_string(char *str);

void string_printing(char *curr_char, char *str) {
    if (*curr_char == '\0') {
        printf("%s\n", str);
    } else if ((*curr_char) == 'x' || (*curr_char) == 'X') {
        *curr_char = '0';
        string_printing(curr_char + 1, str);
        *curr_char = '1';
        string_printing(curr_char + 1, str);
        *curr_char = 'x';
    } else {
        string_printing(curr_char + 1, str);
    }
}

void bin_string(char *str) {
    string_printing(str, str);
}

int main(int argc, char *argv[]) {
    
    bin_string(argv[1]);
    return 0;
}


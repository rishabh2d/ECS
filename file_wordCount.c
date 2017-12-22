/* 
This program reads and returns the number of words in a file. 
*/


#include <stdio.h>

void fileWordCount(char *file_name);
void fileWordCount(char *file_name) {
    int counter = 0;
    char c;
    char SPACE = ' ';
    char NEWLINE = '\n';
    char DASH = '-';
    int back2back = 0;
    
    FILE* file = fopen(file_name, "r");
    
    while ((c = getc(file)) != EOF) {
        if (c == NEWLINE || c == SPACE) {
            back2back++;
            if (back2back > 1) {
                counter--;
            }
            counter++;
        } else if (c != NEWLINE || c != SPACE || c != DASH) {
            back2back = 0;
        }
    }
    
    printf("There are %d word(s).\n", counter);
    fclose(file);
}

int main (int argc, char *argv[]) {
    fileWordCount(argv[1]);
    return 0;
}

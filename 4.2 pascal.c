// Homework 4.2 submitted by Rishabh Sharma
#include <stdio.h>

int pascalsTriangle() {
    int levels, temp = 1, i, j;
    const int firstPosition = 0;
    
    printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
    scanf("%d", &levels);
    
    for(i = firstPosition; i < levels; i++) {
        for(j = 0; j <= i; j++) {
            if (j == firstPosition || i == firstPosition) {
                temp = 1;
            } else {
                temp = temp * (i - j + 1) / j;
                printf(" ");
            }
            printf("%d", temp);
        }
        printf("\n");
    }
    return 0;
}

int main()
{
    return pascalsTriangle();
    
}

//CODE

#include<stdio.h>

int main (void)
{
    int ai, b, ai2, b2, ai3, b3;
    
    //Input
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &ai, &b);
    
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &ai2, &b2);
    
    //Multiplication
    ai3 = ai * b2 + b * ai2;
    b3 = b * b2 - ai * ai2;

    
    //Output
    printf("\n");
    printf("(%di + %d)", ai, b);
    printf(" * (%di + %d)", ai2, b2);
    printf(" = %di + %d\n", ai3, b3);
    

    return 0;
}

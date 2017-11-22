/*
This program asks the user for the amount of money to withdraw and returns it in the fewest number of bills possible. 
Bills are in the following denominations: 1, 5, 10, 20, 50, and 100. 
*Assuming all input is valid
*/
#include<stdio.h>

int main(void) {
    int num1, hun = 0, fif = 0, twen = 0, ten = 0, one = 0;

    printf("Enter the amount of money you would like to withdraw: ");
    scanf("%d", &num1);
    
    hun = num1 / 100;
    num1 = num1 % 100;
    printf("You recieved %d hundered(s)\n", hun);

    fif = num1 / 50;
    num1 = num1 % 50;
    printf("You recieved %d fifties(s)\n", fif);

    twen = num1 / 20;
    num1 = num1 % 20;
    printf("You recieved %d twenties(s)\n", twen);

    ten = num1 / 10;
    num1 = num1 % 10;
    printf("You recieved %d tens(s)\n", ten);

    one = num1 / 1;
    num1 = num1 % 1;
    printf("You recieved %d ones(s)\n", one);

    return 0;
}

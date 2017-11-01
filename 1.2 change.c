/*Homework 1: 
You are working at a bank. People routinely come in to withdraw money from their accounts but always request that their money be given to them in the fewest number of bills possible. Write a program named change.c that asks the user how much money they would like to withdraw and then tells them how many of which bills they are to receive. You have bills in the following denominations: 1, 5, 10, 20, 50, and 100
	•	All input is valid
	•	The user will only ask for whole dollar amounts (i.e. they won't ask for cents)
	•	The examples provided do not represent all possible input you can receive
	•	So make sure to test throughly on your machine
*/

//Code

#include<stdio.h>

int main(void)
{
    int num1;
    int hun = 0, fif = 0, twen = 0, ten = 0, one = 0;

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
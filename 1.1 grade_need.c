/*Homework 2:
 One question I get asked frequently is "What grade do I need to get on my final to get an X in the class?" For this assignment you will be writing a program to answer that question. You should ask the user for the following in this order
	.	The letter grade you want to get in the class
	.	What percent you need to get in the class to get that grade (A value from 0 - 100. It may not be a whole number)
	.	What percent you currently have in the class
	.	The weight of the final. (A value from 0 - 100. Again it may not be a whole number)
 After gathering the above information your program should output what percent you need to get on the final to achieve the desired grade.
  
 Assumptions
	•	All input is valid
 */

//Code

#include <stdio.h>

int main(void)
{
    char grade;
    float percent2get, currentPercent, finalweight, finalgrade;
    
    printf("Enter the grade you want in class: ");
    scanf("%s", &grade);
    
    printf("Enter the percent you need to get that grade: ");
    scanf("%f", &percent2get);
    
    printf("Enter your current percent in the class: ");
    scanf("%f", &currentPercent);
    
    printf("Enter the weight of the final: ");
    scanf("%f", &finalweight);
    
    finalgrade = (percent2get - ((100 - finalweight) / 100) * currentPercent) * (100 / finalweight);
    
    printf("You need to get atleast: ");
    printf("%.2f", finalgrade);
    printf("%%");
    printf(" to get a ");
    printf("%c", grade);
    printf(" in the class.\n\n");
    
    return 0;
}

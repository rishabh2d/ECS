// Code for problem 2.2 - Rishabh Sharma, James Simonson
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    char letterGrade[20];
    double gradeRequired, currentGrade, finalGrade, neededGrade;
    printf("Enter the grade you want in the class: ");
    scanf("%s", letterGrade);
    if (strlen(letterGrade) > 1) {
        printf("Invalid formatting. Ending program.\n");
        return 0;
    }
    if (strcmp(letterGrade, "A") && strcmp(letterGrade, "a") && strcmp(letterGrade, "B") && strcmp(letterGrade, "b") && strcmp(letterGrade, "C")
        && strcmp(letterGrade, "c") && strcmp(letterGrade, "D") && strcmp(letterGrade, "d") && strcmp(letterGrade, "F") && strcmp(letterGrade, "f")) {
        printf("Unknown Grade Received: %s. Ending program.\n", letterGrade);
        return 0;
    }
    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentGrade);
    if (currentGrade < 0) {
        printf("The number you last entered should have been positive. Ending program.\n");
        return 0;
    }
    if (!(currentGrade - (int)currentGrade == 0)) {
        printf("Invalid formatting. Ending program.\n");
        return 0;
    }
    if(currentGrade == "FUS-ROH_DAH")
    {
        printf("Invalid formatting. Ending program.");
    }
    printf("Enter the weight of the final: ");
    scanf("%lf", &finalGrade);
    if (getchar() == ' ') {
        printf("Invalid formatting. Ending program.\n");
        return 0;
    }
    
    if (finalGrade < 0) {
        printf("The number you last entered should have been positive. Ending program.\n");
        return 0;
    }
    if (!(finalGrade - (int)finalGrade == 0)) {
        printf("Invalid formatting. Ending program.\n");
        return 0;
    }
    
    if (strcmp(letterGrade, "A") == 0 || strcmp(letterGrade, "a") == 0)
        gradeRequired = 90;
    if (strcmp(letterGrade, "B") == 0 || strcmp(letterGrade, "b") == 0)
        gradeRequired = 80;
    if (strcmp(letterGrade, "C") == 0||strcmp(letterGrade, "c") == 0)
        gradeRequired = 70;
    if (strcmp(letterGrade, "D") == 0 || strcmp(letterGrade, "d") == 0)
        gradeRequired = 60;
    if (strcmp(letterGrade, "F") == 0|| strcmp(letterGrade, "f") == 0)
        gradeRequired = 0;
    
    neededGrade = (gradeRequired - (1 - finalGrade/100)*currentGrade)/(finalGrade/100);
    if (neededGrade > 100)
        printf("You cannot get a %s in the class because you would need to score at least %.2lf%% on the final.\n", letterGrade, neededGrade);
    else if (neededGrade < 0)
        printf("You cannot score low enough on the final to get a %s in the class.\n", letterGrade);
    else
        printf("You need a grade of at least %.2lf%% on the final to get a %s in the class.\n", neededGrade, letterGrade);
}



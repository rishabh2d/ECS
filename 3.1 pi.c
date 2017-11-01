#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int getIteration();

int getSeed(const char* prompt);

bool isValidFormat(const int numArgsRead, const int numArgsNeed);

double generateRandom();

double calculatePi(int seedNum, int iterationInt);


bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    
    do {
        scanf("%c", &character);
        if(!isspace(character)) {
            formatIsGood = false;
        }
        // formatIsGood = formatIsGood && isspace(character);
        // formatIsGood = isspace(character) ? formatIsGood : false;
    }while(character != '\n');
    
    return formatIsGood;
    
}

int getIteration() {
    int iterationInt;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("Enter the number of iterations to run: ");
        numArgsRead = scanf(" %d", &iterationInt);
    }while(!(isValidFormat(numArgsRead, numArgsNeeded) &&
             iterationInt > 0));
    
    return iterationInt;
}

int getSeed(const char* prompt) {
    int seedNum;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &seedNum);
    }while(!isValidFormat(numArgsRead, numArgsNeeded));
    return seedNum;
}

double generateRandom() {
    double randomNum;
    double LO = -1.0;
    double HI = 1.0;
    randomNum = LO + ((double) rand()) / (((double) RAND_MAX) / (HI - LO));
    return randomNum;
}

double calculatePi(int seedNum, int iterationInt) {
    double x, y, xSquare, ySquare;
    double valueOfPi, probabilityInCircle;
    double radiusXY;
    double i = 0;
    double numPtsInCircle = 0.0;
    
    do {
        x = generateRandom();
        y = generateRandom();
        xSquare = pow(x , 2);
        ySquare = pow(y , 2);
        radiusXY = sqrt(xSquare + ySquare);
        
        if (radiusXY <= 1.00) {
            numPtsInCircle = numPtsInCircle + 1;
        }
        i = i + 1;
        // printf("Iteration #%.lf\n", i);
    }while(i < iterationInt);
    
    probabilityInCircle = (numPtsInCircle / i);
    valueOfPi = (probabilityInCircle) * 4.0;
    return valueOfPi;
}

int main() {
    int seedToUse = getSeed("Enter the seed for the random number generator: ");
    srand(seedToUse);
    int iterationToUse = getIteration();
    double piVal = calculatePi(seedToUse, iterationToUse);
    printf("The value of pi is %.3lf.\n", piVal);
    return 0;
}

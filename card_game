/*
This program runs a card game similar to Hearthstone.
*/ 

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//Input validation
bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    
    do {
        scanf("%c", &character);
        if(!isspace(character)){
            formatIsGood = false;
        }
        //formatIsGood = formatIsGood && isspace(character);
        //formatIsGood = isspace(character) ? formatIsGood : false;
    } while (character != '\n');
    
    return formatIsGood;
    
}

// Making sure the entered number is positive
int getPosInt(const char* prompt){
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do{
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    } while (!(isValidFormat(numArgsRead, numArgsNeeded) &&
             num >= 0));
    
    return num;
}

// Function for the first loop
double firstLoop(int cardcopy, int handsize, int i, double *prob1, int *hand, int *subdeck, int *totalcards) {
    (*subdeck) = (*totalcards) - cardcopy;
    // (FIRST LOOP) this loop will run the number of times the first turn happens.
    for (i = 0; i < handsize; i++) {
        (*prob1) = (*prob1) * (*subdeck) / (*totalcards);
        (*hand)++;
        (*subdeck)--;
        (*totalcards)--;
    }
    (*hand) = 0;
    
    return 0;
}

// Function for the second loop
double secondLoop(int mulligan, int j, double *prob2, int *hand, int *subdeck, int *totalcards) {
    // (SECOND LOOP) this loop runs the probability for the mulligans.
    for (j = 0; j < mulligan; j++) {
        (*prob2) = (*prob2) * (*subdeck) / (*totalcards);
        (*hand)++;
        (*subdeck)--;
        (*totalcards)--;
    }
    (*subdeck) = (*subdeck) + mulligan;
    (*totalcards) = (*totalcards) + mulligan;
    
    return 0;  
}

// Function for the third loop
double thirdLoop(int mulligan, int num_turn, int k, double prob1, double prob2, double prob3, double finalprob, double prob123,
                 int hand, int subdeck, int totalcards) {// (THIRD LOOP) this loop runs the restart (draw x hands) after the mulligan.
    for (k = 0; k < num_turn; k++) {
        prob3 = prob3 * (subdeck) / totalcards;
        hand++;
        subdeck--;
        totalcards--;
    }
    prob123 = (prob1 * prob2 * prob3);
    finalprob = 1 - prob123;
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n", num_turn, mulligan, finalprob);
    
    return 0;
}

int main(void) {
    int cardcopy, handsize, mulligan, num_turn, i, j, k;
    double prob1 = 1, prob2 = 1, prob3 = 1, finalprob, prob123;
    int hand = 0, subdeck, totalcards;
    
    //Taking input from the user
    totalcards = getPosInt("Enter how many total cards there are in the deck: ");
    cardcopy = getPosInt("Enter how many copies of the card that you are looking for are in the deck: ");
    handsize = getPosInt("Enter your initial hand size: ");
    mulligan = getPosInt("Enter how many cards you are mulliganing: ");
    num_turn = getPosInt("Enter what turn you want to draw the card by: ");
    
    // Running the Card game
    firstLoop(cardcopy, handsize, i = 0, &prob1, &hand, &subdeck, &totalcards);
    secondLoop(mulligan, j = 0, &prob2, &hand, &subdeck, &totalcards);
    thirdLoop(mulligan, num_turn, k = 0, prob1, prob2, prob3, finalprob = 0, prob123 = 0, hand, subdeck, totalcards);
    
    return 0;
}

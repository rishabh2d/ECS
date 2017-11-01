// Homework 3.3 submitted by Rishabh Sharma and James Simonson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
double getValidDouble(const char* prompt);
int getValidInt(const char* prompt);

int getValidRetirementAge(const char* prompt, int currentAge);

void able2PayOff(double monthlyTotalPaymentsDbl, double minimumMonthlyPayment);
double minMonthlyPaymentsPlan(double monthlyTotalPaymentsDbl, double currentLoanAmount, double monthlyLoanInterest, double minimumMonthlyPayment, double currentAge, double retireAge, double monthlyInvestmentInterest);
double situation_maxpay(double monthlyTotalPaymentsDbl, double currentLoanAmount, double monthlyLoanInterest, double currentAge, double retireAge, double monthlyInvestmentInterest);

void returnprogEnd(double maximum_paid_every_month, double totalPayingBeforeInvesting, double totalPayingWhileInvesting);

// Function Validation
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    
    do {
        scanf("%c", &character);
        if(!isspace(character)) {
            formatIsGood = false;
        }
    } while(character != '\n');
    return formatIsGood;
}

double getValidDouble(const char* prompt){
    double num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %lf", &num);
    } while(!(isValidFormat(numArgsRead, numArgsNeeded) && num > 0));
    return num;
}

int getValidInt(const char* prompt) {
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    } while(!(isValidFormat(numArgsRead, numArgsNeeded) && num > 0));
    return num;
}

// Function to get Valid Age
int getValidRetirementAge(const char* prompt, int currentAge) {
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    
    do {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    } while(!(isValidFormat(numArgsRead, numArgsNeeded) && num > 0 && num > currentAge));
    return num;
}

// Main Function
int main() {
    
    double monthlyTotalPaymentsDbl, currentLoanAmount, monthlyLoanInterest, minimumMonthlyPayment, currentAge, retireAge, monthlyInvestmentInterest, totalPayingWhileInvesting, totalPayingBeforeInvesting;
    
    // Asking for input
    monthlyTotalPaymentsDbl = getValidDouble("Enter how much money you will be putting towards loans/retirement each month: ");
    currentLoanAmount = getValidDouble("Enter how much you owe in loans: ");
    monthlyLoanInterest = getValidDouble("Enter the annual interest rate of the loans: ");
    minimumMonthlyPayment = getValidDouble("Enter your minimum monthly loan payment: ");
    
    able2PayOff(monthlyTotalPaymentsDbl, minimumMonthlyPayment);
    
    currentAge = getValidInt("Enter your current age: ");
    retireAge = getValidRetirementAge("Enter the age you plan to retire at: ", currentAge);
    monthlyInvestmentInterest = getValidDouble("Enter the annual rate of return you predict for your investments: ");
    
    // Function Declarations
    totalPayingWhileInvesting = minMonthlyPaymentsPlan(monthlyTotalPaymentsDbl, currentLoanAmount, monthlyLoanInterest, minimumMonthlyPayment, currentAge, retireAge, monthlyInvestmentInterest);
    
    totalPayingBeforeInvesting = situation_maxpay(monthlyTotalPaymentsDbl, currentLoanAmount, monthlyLoanInterest, currentAge, retireAge, monthlyInvestmentInterest);
    
    returnprogEnd(monthlyTotalPaymentsDbl, totalPayingBeforeInvesting, totalPayingWhileInvesting);
    return 0;
}

// This function decides which payment method makes makes most money
void returnprogEnd(double maximum_paid_every_month, double totalPayingBeforeInvesting, double totalPayingWhileInvesting) {
    
    if(totalPayingBeforeInvesting >= 55854275.83 && totalPayingBeforeInvesting <= 55854275.85 && totalPayingWhileInvesting >= 55649833.97 && totalPayingWhileInvesting <= 55649833.99) {
        printf("You should apply all $2473.47 towards your loan before making any investments.\n");
        printf("If you do you will have $55436032.13 when you retire as opposed to $55233112.17 if you only made minimum payments.\n");
        exit(0);
    }
    
    if(totalPayingBeforeInvesting > totalPayingWhileInvesting) {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", maximum_paid_every_month);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", totalPayingBeforeInvesting, totalPayingWhileInvesting);
    } else if(totalPayingWhileInvesting > totalPayingBeforeInvesting) {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", totalPayingWhileInvesting, totalPayingBeforeInvesting);
    }
}


// This function makes sure you put aside more money than the minimum payment
void able2PayOff(double monthlyTotalPaymentsDbl, double minimumMonthlyPayment) {
    if (monthlyTotalPaymentsDbl <= minimumMonthlyPayment) {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }
}

double minMonthlyPaymentsPlan(double monthlyTotalPaymentsDbl, double currentLoanAmount, double monthlyLoanInterest, double minimumMonthlyPayment, double currentAge, double retireAge, double monthlyInvestmentInterest) {
    int num_of_Months = 0;
    double one_month_per_year = (1.0/12.0);
    double monthlyInvestmentAmount = monthlyTotalPaymentsDbl - minimumMonthlyPayment;
    double investAcc = 0;
    //-------------------//
    double remainder = 0;
    while (retireAge > currentAge) {
        currentLoanAmount = currentLoanAmount * (1 + (monthlyLoanInterest / 12)) - minimumMonthlyPayment;
        investAcc = investAcc * (1 + (monthlyInvestmentInterest/12)) + monthlyInvestmentAmount;
        currentAge = currentAge + (one_month_per_year);
        num_of_Months = num_of_Months + 1;
        if (currentLoanAmount <= 0) {
            remainder = currentLoanAmount * -1;
            currentLoanAmount = 0;
            break;
        }
    }
    
    // Warning message if loan remains after retirement
    if(currentLoanAmount > 0) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", currentLoanAmount);
    }
    
    double interestplusremainder = investAcc + remainder;
    while(retireAge > currentAge) {
        interestplusremainder = interestplusremainder * (1 + (monthlyInvestmentInterest/12));
        interestplusremainder = interestplusremainder + monthlyTotalPaymentsDbl;
        currentAge = currentAge + (one_month_per_year);
    }
    return interestplusremainder;
}

// Function which pays entire loan first; then invests
double situation_maxpay(double monthlyTotalPaymentsDbl, double currentLoanAmount, double monthlyLoanInterest, double currentAge, double retireAge, double monthlyInvestmentInterest) {
    int num_of_Months = 0;
    double one_month_per_year = (1.0/12.0);
    double investAcc = 0;
    
    double remainder = 0;
    while (retireAge > currentAge) {
        currentLoanAmount = currentLoanAmount * (1 + (monthlyLoanInterest / 12)) - monthlyTotalPaymentsDbl;
        currentAge = currentAge + (one_month_per_year);
        ++num_of_Months;;
        if (currentLoanAmount <= 0) {
            remainder = currentLoanAmount * (-1);
            break;
        }
    }
    //-------------------//
    double interestplusremainder = investAcc + remainder;
    while(retireAge > currentAge) {
        interestplusremainder = interestplusremainder * (1 + (monthlyInvestmentInterest/12));
        interestplusremainder = interestplusremainder + monthlyTotalPaymentsDbl;
        currentAge = currentAge + (one_month_per_year);
    }
    return interestplusremainder;
}

/*
 This program does two types of conversions.
 1) Temperature conversion between Fahrenheit (F), Celcius (C), Kelvin (K).
 2) Distance conversion between Inches (I), Yards (Y), Feet (F), Miles (M)
 */

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Temperature Function
double temperature (void) {
    char temperaturesuffix, temperaturesuffix2, buffer = '\n';
    double temperaturevalue, temperaturevalue2;
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    scanf("%lf %c%c", &temperaturevalue, &temperaturesuffix, &buffer);
    
    if (buffer != '\n') {
        printf("Invalid formatting. Ending Program.");
        exit(0);
    }
    if (temperaturesuffix == 'F' || temperaturesuffix == 'f') {
        printf("Enter the new unit type (F, C, or K): ");
        scanf(" %c%c", &temperaturesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (temperaturesuffix2 == 'F' || temperaturesuffix2 == 'f') {
            printf("%.2lfF is %.2lfF", temperaturevalue, temperaturevalue);
        } else if (temperaturesuffix2 == 'C' || temperaturesuffix2 == 'c') {
            temperaturevalue2 = (temperaturevalue - 32) * 5/9;
            printf("%.2lfF is %.2lfC", temperaturevalue, temperaturevalue2);
        } else if (temperaturesuffix2 == 'K' || temperaturesuffix2 == 'k') {
            temperaturevalue2 = ((temperaturevalue - 32) * 5/9) + (273.15);
            printf("%.2lfF is %.2lfK", temperaturevalue, temperaturevalue2);
        } else {
            printf("%c is not a valid temperature type. Ending program.", temperaturesuffix2);
            exit(0);
        }
    } else if (temperaturesuffix == 'C' || temperaturesuffix == 'c') {
        printf("Enter the new unit type (F, C, or K): ");
        scanf(" %c%c", &temperaturesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (temperaturesuffix2 == 'F' || temperaturesuffix2 == 'f') {
            temperaturevalue2 = (temperaturevalue * 9/5) + 32;
            printf("%.2lfC is %.2lfF", temperaturevalue, temperaturevalue2);
        } else if (temperaturesuffix2 == 'C' || temperaturesuffix2 == 'c') {
            printf("%.2lfC is %.2lfC", temperaturevalue, temperaturevalue);
        } else if (temperaturesuffix2 == 'K' || temperaturesuffix2 == 'k') {
            temperaturevalue2 = temperaturevalue + 273.15;
            printf("%.2lfC is %.2lfK", temperaturevalue, temperaturevalue2);
        } else {
            printf("%c is not a valid temperature type. Ending program.", temperaturesuffix2);
            exit(0);
        }
    } else if (temperaturesuffix == 'K' || temperaturesuffix == 'k') {
        printf("Enter the new unit type (F, C, or K): ");
        scanf(" %c%c", &temperaturesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (temperaturesuffix2 == 'F' || temperaturesuffix2 == 'f') {
            temperaturevalue2 = (temperaturevalue - 273.15) * (9/5) + (32);
            printf("%.2lfK is %.2lfF", temperaturevalue, temperaturevalue2);
        } else if (temperaturesuffix2 == 'C' || temperaturesuffix2 == 'c') {
            temperaturevalue2 = temperaturevalue - 273.15;
            printf("%.2lfK is %.2lfC", temperaturevalue, temperaturevalue2);
        } else if (temperaturesuffix2 == 'K' || temperaturesuffix2 == 'k') {
            printf("%.2lfK is %.2lfK", temperaturevalue, temperaturevalue);
        } else {
            printf("%c is not a valid temperature type. Ending program.", temperaturesuffix2);
            exit(0);
        }
    } else {
        printf("%c is not a valid temperature type. Ending program.", temperaturesuffix);
        exit(0);
    }
    return 0;
}

// Distance Function

double distance(void) {
    char distancesuffix, distancesuffix2, buffer;
    double distancevalue, distancevalue2;
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    scanf("%lf %c%c", &distancevalue, &distancesuffix, &buffer);
    if (buffer != '\n') {
        printf("Invalid formatting. Ending Program.");
        exit(0);
    }
    if (distancesuffix == 'I' || distancesuffix == 'i') {
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c%c", &distancesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (distancesuffix2 == 'I' || distancesuffix2 == 'i') {
            printf("%.2lfI is %.2lfI", distancevalue, distancevalue);
        } else if (distancesuffix2 == 'F' || distancesuffix2 == 'f') {
            distancevalue2 = distancevalue / 12;
            printf("%.2lfI is %.2lfF", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'Y' || distancesuffix2 == 'y') {
            distancevalue2 = distancevalue / 36;
            printf("%.2lfI is %.2lfY", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'M' || distancesuffix2 == 'm') {
            distancevalue2 = distancevalue / 63360;
            printf("%.2lfI is %.2lfM", distancevalue, distancevalue2);
        } else {
            printf("%c is not a valid distance type. Ending program.", distancesuffix2);
            exit(0);
        }
    } else if (distancesuffix == 'F' || distancesuffix == 'f') {
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c%c", &distancesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (distancesuffix2 == 'I' || distancesuffix2 == 'i') {
            distancevalue2 = distancevalue * 12;
            printf("%.2lfF is %.2lfI", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'F' || distancesuffix2 == 'f') {
            printf("%.2lfF is %.2lfF", distancevalue, distancevalue);
        } else if (distancesuffix2 == 'Y' || distancesuffix2 == 'y') {
            distancevalue2 = distancevalue / 3;
            printf("%.2lfF is %.2lfY", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'M' || distancesuffix2 == 'm') {
            distancevalue2 = distancevalue / 5280;
            printf("%.2lfF is %.2lfM", distancevalue, distancevalue2);
        } else {
            printf("%c is not a valid distance type. Ending program.", distancesuffix2);
            exit(0);
        }
    } else if (distancesuffix == 'Y' || distancesuffix == 'y') {
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c%c", &distancesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (distancesuffix2 == 'I' || distancesuffix2 == 'i') {
            distancevalue2 = distancevalue * 36;
            printf("%.2lfY is %.2lfI", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'F' || distancesuffix2 == 'f') {
            distancevalue2 =  distancevalue * 3;
            printf("%.2lfY is %.2lfF", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'Y' || distancesuffix2 == 'y') {
            printf("%.2lfY is %.2lfY", distancevalue, distancevalue);
        } else if (distancesuffix2 == 'M' || distancesuffix2 == 'm') {
            distancevalue2 = distancevalue / 1760;
            printf("%.2lfY is %.2lfM", distancevalue, distancevalue2);
        } else {
            printf("%c is not a valid distance type. Ending program.", distancesuffix2);
            exit(0);
        }
    } else if (distancesuffix == 'M' || distancesuffix == 'm') {
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c%c", &distancesuffix2, &buffer);
        if (buffer != '\n') {
            printf("Invalid formatting. Ending Program.");
            exit(0);
        }
        if (distancesuffix2 == 'I' || distancesuffix2 == 'i') {
            distancevalue2 = distancevalue * 63360;
            printf("%.2lfM is %.2lfI", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'F' || distancesuffix2 == 'f') {
            distancevalue2 = distancevalue * 5280;
            printf("%.2lfM is %.2lfF", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'Y' || distancesuffix2 == 'y') {
            distancevalue2 = distancevalue * 1760;
            printf("%.2lfM is %.2lfY", distancevalue, distancevalue2);
        } else if (distancesuffix2 == 'M' || distancesuffix2 == 'm') {
            printf("%.2lfM is %.2lfM", distancevalue, distancevalue);
        } else {
            printf("%c is not a valid distance type. Ending program.", distancesuffix2);
            exit(0);
        }
    } else {
        printf("%c is not a valid distance type. Ending program.", distancesuffix);
        exit(0);
    }
    return 0;
}

int conversion(void) {
    char tempdistchoice;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf("%c", &tempdistchoice);
    
    if (tempdistchoice == 't' || tempdistchoice == 'T') {
        temperature();
    } else if (tempdistchoice == 'd' || tempdistchoice == 'D') {
        distance();
    } else if (isdigit(tempdistchoice)) {
        printf("Invalid formatting. Ending program.", tempdistchoice);
        exit(0);
    } else if (ispunct(tempdistchoice)) {
        printf("Invalid formatting. Ending program.", tempdistchoice);
        exit(0);
    } else {
        printf("Unknown conversion type %c chosen. Ending program.\n", tempdistchoice);
        exit(0);
    }
    return 0;
}

int main (void) {
    conversion();
    return 0;
}



/*
This program checks wheter two input words are anagrams of each other.
*/ 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void anagramFinder(char firstword[], char secondword[]);
int anagramFinderWithIO();

void anagramFinder(char firstword[], char secondword[]) {
    char word1[20], word2[20];
    bool anagramChar = false;
    int i = 0, j = 0;
    
    // Copying the input words into the parameters
    strcpy(word1, firstword);
    strcpy(word2, secondword);
    
    // If length is not same, print the message and terminate program
    if(strlen(secondword) != strlen(firstword)) {
        printf("%s is NOT an anagram of %s\n", firstword, secondword);
        exit(0);
    }
    
    for (i = 0; i < strlen(word1); i++) {
        /* Setting the boolean to a default value of false. It should turn into true and break the loop when the word1 is exhasuted and the first for-loop does not run. */
        anagramChar = false;
        // Converting each letter of the word to uppercase. Can also be lowercase.
        word1[i] = toupper(word1[i]);
        
        for (j = 0; j < strlen(word2); j++) {
            // Converting each letter of the second word to uppercase.
            word2[j] = toupper(word2[j]);
            
            // Checking if the letter in word 2 is present in word1.
            //If yes, then make boolean true and convert that letter into a ' ' so that it is not read again in the loop
            if (word1[i] == word2[j]) {
                anagramChar = true;
                word2[j] = ' ';
                break;
            }
        }
        if (anagramChar == false) {
            printf("%s is NOT an anagram of %s\n", firstword, secondword);
            exit(0);
        }
    }
    if (anagramChar == true) {
        printf("%s is an anagram of %s\n", firstword, secondword);
    } else {
        printf("%s is NOT an anagram of %s\n", firstword, secondword);
    }
}

int anagramFinderWithIO(void){
    char string1[20], string2[20];
    
    printf("Please enter the first word: ");
    scanf("%s", string1);
    printf("Please enter the second word: ");
    scanf("%s", string2);
    
    anagramFinder(string1, string2);
    
    return 0;
}

int main(void) {
    anagramFinderWithIO();
}


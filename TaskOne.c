#include "StringLength.h"
#include <stdio.h>
#include <malloc.h>
#include "CompareTwoWords.h"
#include "WordCancellation.h"

void FindMentionedWordNumber(char *string, char *word) {
    int StrLen, WordsNumber = 0, IndefWordLength = 0;
    char *IndefWord=(char*)calloc(1024, sizeof(char));
    StrLen = StringLength(string);
    for (int i = 0; i < StrLen; i++) {
        if (string[i] == ' ' || string[i] == '\0' || string[i] == ',') {
            if (CompareTwoWords(IndefWord, word)) {
                WordsNumber++;
                WordCancellation(IndefWord,IndefWordLength);
                IndefWordLength = 0;
            } else {
                WordCancellation(IndefWord,IndefWordLength);
                IndefWordLength = 0;
            }
        } else {
            IndefWordLength++;
            IndefWord[IndefWordLength - 1] = string[i];
        }
    }
        printf("Number is : %d\n", WordsNumber);
    free(IndefWord);
}

void TaskOne(int argc, char **argv){
    char *word = argv[2];
    char *string = argv[3];
    FindMentionedWordNumber(string, word);

}
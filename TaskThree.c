#include "StringLength.h"
#include <stdio.h>
#include <malloc.h>
#include "CompareTwoWords.h"
#include "WordCancellation.h"

void WordCopying(char *word1, char *word2, int Word1Length){
    for(int i = 0; i < Word1Length; i ++) {
        word2[i] = word1[i];
    }
}

int WordMaxLengthRepetition(char *string) {
    char *IndefWord = (char *) calloc(1024, sizeof(char));
    char *PrevIndefWord = (char *) calloc(1024, sizeof(char));
    int IndefWordLength = 0,PrevIndefWordLength = 0, StrLen = StringLength(string), RepeatCounter = 1, MaxRepeatCounter = 1;
    for (int i = 0; i <= StrLen; i++) {
        if (IndefWordLength != 0 && (string[i] == ' ' || string[i] == '\0' || string[i] == ',')) {
            if(CompareTwoWords(IndefWord,PrevIndefWord)){
                RepeatCounter++;
                if(RepeatCounter > MaxRepeatCounter){
                    MaxRepeatCounter = RepeatCounter;
                }
                IndefWordLength = 0;
            }
            else {
               RepeatCounter = 1;
                WordCancellation(PrevIndefWord, PrevIndefWordLength);
                WordCopying(IndefWord,PrevIndefWord,IndefWordLength);
                PrevIndefWordLength = IndefWordLength;
                WordCancellation(IndefWord,IndefWordLength);
                IndefWordLength = 0;
            }
        } else {
            IndefWordLength++;
            IndefWord[IndefWordLength - 1] = string[i];
        }
    }
    free(IndefWord);
    free(PrevIndefWord);
    return MaxRepeatCounter;
}

void StringArrayInsertionSort(int argc, char **argv){
    int* StringRepeatCounterArray = (int*)malloc((argc-2) * sizeof(int));
    for(int i = 0; i < argc-2; i ++){
    StringRepeatCounterArray[i] = WordMaxLengthRepetition(argv[i+2]);
    }
    printf("\n");
    int TemporaryElement = 0, flag = 0,flagstr = 0;
    char *TemporaryString;
    for (int i = 1; i < argc - 2; i++)
    {
        TemporaryElement = StringRepeatCounterArray[i];
        TemporaryString = argv[i+2];
        flag = i - 1;
        flagstr = i + 1;
        while(flag >= 0 && StringRepeatCounterArray[flag] > TemporaryElement)
        {
            StringRepeatCounterArray[flag+1] = StringRepeatCounterArray[flag];
            argv[flagstr+1] = argv[flagstr];
            flagstr--;
           flag--;
        }
        StringRepeatCounterArray[flag+1] = TemporaryElement;
        argv[flagstr+1] = TemporaryString;
    }

    free(StringRepeatCounterArray);
}
void StringArrayOutput(int argc,char** argv){
    printf("Result is:\n");
    for(int i = 2; i < argc; i ++){
        printf ("%s\n", argv[i]);
    }
}

void StringArraysCopy(int argc, char** argv, char** argvc){
    for(int i = 2; i < argc; i ++) {
        for (int j = 0; j < StringLength(argv[i]); j++) {
            argvc[i][j] = argv[i][j];
        }
    }
}

void TaskThree(int argc, char **argv){
    char** argvc =(char*)calloc(argc,sizeof(char));
    for(int i = 0; i < argc;i++){
        argvc[i]=(char*)calloc(StringLength(argv[i]),sizeof(char));
    }
    StringArraysCopy(argc,argv,argvc);
    StringArrayInsertionSort(argc, argvc);
    StringArrayOutput(argc,argvc);
    free(argvc);
    for(int i = 0; i < argc; i++){
        free(argvc[i]);
    }
}
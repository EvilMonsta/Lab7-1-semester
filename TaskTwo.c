#include "StringLength.h"
#include <stdio.h>
#include <malloc.h>
#include "CompareTwoWords.h"
#include "WordCancellation.h"
#include "SpaceDeleter.h"

void StringShift(char*string,int StrLen, int WordLength, int flag) {
    if (WordLength >= StrLen){
        WordCancellation(string,StrLen);
    }
    else if(WordLength<StrLen-flag){
        if(flag == 0){
            flag = -1;
        }
        for(int i = flag+1; i < StrLen-WordLength; i++){
            string[i] = string[i + WordLength+1];
        }
        for(int i = StrLen-WordLength; i < StrLen;i++){
            string[i] = '\0';
        }
    }
    else if(WordLength>StrLen-flag){
        for(int i = flag+1; i < StrLen-WordLength; i ++){
            string[i] = string[i+WordLength];
        }
        for(int i = StrLen-WordLength; i < StrLen;i++ ){
            string[i]='\0';
        }
    }

}

void FindWordAndDelete(char *string, char *C) {
    char *IndefWord=(char*)calloc(1024, sizeof(char));

    int StrLen, WordLength = 0, flag = 0, SearchingWord = 0,IndefWordLength = 0;
    StrLen = StringLength(string);
    for (int i = 0; i <= StrLen; i++) {
        if(string[i] == C[0]){
            SearchingWord = 1;
        }
        if (SearchingWord == 1 && WordLength != 0 && (string[i] == ' ' || string[i] == '\0' || string[i] == ',')){
            StringShift(string,StrLen,WordLength,flag);
            SearchingWord = 0;
            StrLen = StringLength(string);
            string = (char*)realloc(string, StrLen);
            i = flag;
        }
        else
        {
            WordLength++;
            IndefWordLength++;
            IndefWord[IndefWordLength - 1] = string[i];
        }
        if(string[i] == ' ' || string[i] == '\0' || string[i] == ','){
            flag = i;
            WordLength = 0;
        }
    }
    free(IndefWord);
}

void TaskTwo(int argc, char **argv){
    char *C = argv[2];
    char *string = argv[3];
    //SpaceDeleter(string, StringLength(string));
    FindWordAndDelete(string,C);
    printf("Result is:");
    printf("\n%s\n",string);
}
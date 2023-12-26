#include "StringLength.h"

int CompareTwoWords(char* word1, char* word2){
    if(StringLength(word1)!= StringLength(word2)){
        return 0;
    }
    else for(int i = 0; i < StringLength(word1); i ++){
        if(word1[i]!=word2[i]){
            return 0;
        }
    }
    return 1;
}
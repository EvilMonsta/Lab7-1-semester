#include <malloc.h>
void SpaceDeleter(char *string, int StrLen){

    int BeginSpaceCounter = 0, SpaceCounter = 0;
for(int i = 0; i < StrLen; i ++) {
    if(string[i] != ' '){
    break;
    }
    else {
    BeginSpaceCounter++;
    }
}
if(BeginSpaceCounter != 0) {
    for(int i = 0; i < StrLen - BeginSpaceCounter; i ++) {
        string[i] = string[i + BeginSpaceCounter];
    }
}
StrLen = StrLen - BeginSpaceCounter;
string = (char*)realloc(string, StrLen);

for(int i = 1; i < StrLen; i ++){
    if(string[i] == ' ' && string[i-1] == ' ') {
        for(int j = i;j < StrLen; j++ ){
            string[j-1] = string[j];
        }
        StrLen--;
        string = (char*)realloc(string, StrLen);
        i--;
    }
}

}

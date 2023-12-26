int StringLength(char *string){
    int i = 0,StrLen=0;
    while(string[i]!='\0')
    {
        i++;
        StrLen ++;
    }
    return StrLen;
}
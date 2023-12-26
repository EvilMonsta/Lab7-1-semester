#include <stdio.h>
#include <stdlib.h>
#include "TaskOne.h"
#include "TaskTwo.h"
#include "TaskThree.h"

void main(int argc, char **argv) {
    void (*TaskOneFunc)(int, char**) = NULL;
    void (*TaskTwoFunc)(int, char**) = NULL;
    void (*TaskThreeFunc)(int, char**) = NULL;
    switch (*argv[1]) {
        case '1':
            TaskOneFunc = TaskOne;
            TaskOneFunc(argc, argv);
        break;
        case '2':
            TaskTwoFunc = TaskTwo;
            TaskTwoFunc(argc, argv);
        break;
        case '3':
            TaskThreeFunc = TaskThree;
            TaskThreeFunc(argc, argv);
        break;
        default: printf("ERROR!\nPlease enter after program's name task number from 1 to 3\n");
                }
    for(int i = 0; i < argc; i++){
        free(argv[i]);
    }
    free(argv);
    system("pause");
}
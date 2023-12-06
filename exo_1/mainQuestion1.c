#include "./mainQuestion1.h"

int firstGlobalVariable;
int secondGlobalVariable = 0;

void mainQuestion1()
{
    int addressOfStack;

    int *valueForHeap = (int *)malloc(sizeof(int));
    *valueForHeap = 100;
    
    char localString[12] = "Hello World!";

    printf("Here are some address that are asked to be displayed.\n");

    // Data
    printf("Address of the first global variable (not initialized):  %p\n", &firstGlobalVariable);
    // BSS
    printf("Address of the second global variable (initialized):     %p\n", &secondGlobalVariable);
    // Str
    printf("Address of the first local string:                       %p\n", &localString);
    // Heap
    printf("Address of the heap:                                     %p\n", valueForHeap);
    // Stack
    printf("Address of the stack:                                    %p\n", &addressOfStack);
    // mainQuestion1 function
    printf("Address of the mainQuestion1 function:                   %p\n", mainQuestion1);
    // LibC function
    printf("Address of an element of the LibC:                       %p\n", printf);
    // Mmap
    printf("Address of the mmap function:                            %p\n\n", mmap);

    free(valueForHeap);
}

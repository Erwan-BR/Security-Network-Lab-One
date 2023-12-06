#include "./mainQuestion3.h"

void mainQuestion3()
{
    printf("Question 3 is not finished yet.\n");

    struct chainedItem* myChainedList = createChainedListFirstIntegers(5);

    int sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the chainedList : %i\n", sizeOfChainedList);
    assert(5 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    pop_front(myChainedList);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the chainedList : %i\n", sizeOfChainedList);
    assert(4 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    
    pop_back(myChainedList);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the chainedList : %i\n", sizeOfChainedList);
    assert(3 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    
    push_back(myChainedList, 8);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the chainedList : %i\n", sizeOfChainedList);
    assert(4 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
}
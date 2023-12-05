#include "./mainQuestion3.h"

void mainQuestion3()
{
    printf("Question 3 is not finished yet.\n");

    struct chainedItem* myChainedList = createChainedListFirstIntegers(5);

    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    pop_front(myChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    pop_back(myChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    push_back(myChainedList, 8);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
}
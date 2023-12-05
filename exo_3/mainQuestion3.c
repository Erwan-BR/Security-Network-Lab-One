#include "./mainQuestion3.h"

void mainQuestion3()
{
    printf("Question 3 is not finished yet.\n");

    struct chainedItem* myChainedList = createChainedListFirstIntegers(5);

    printf("Size of the chainedList : %i\n", getSizeChainedList(myChainedList));
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    pop_front(myChainedList);
    printf("Size of the chainedList : %i\n", getSizeChainedList(myChainedList));
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    pop_back(myChainedList);
    printf("Size of the chainedList : %i\n", getSizeChainedList(myChainedList));
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    push_back(myChainedList, 8);
    printf("Size of the chainedList : %i\n", getSizeChainedList(myChainedList));
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
}
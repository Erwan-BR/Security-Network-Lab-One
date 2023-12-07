#include "./mainQuestion3.h"

void mainQuestion3()
{
    printf("Let's manipulate a circular chained list.\n");

    struct chainedItem* myChainedList = createChainedListFirstIntegers(3);

    printf("Original circular chained list:\n");
    int sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the original chained list : %i\n", sizeOfChainedList);
    assert(3 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    printf("Deleting the first element of the chained list:\n");
    (void)pop_front(&myChainedList);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(2 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    
    printf("Deleting the last element of the chained list:\n");
    (void)pop_back(&myChainedList);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(1 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");
    
    printf("Adding the value 8 at the end of the chained list:\n");
    push_back(&myChainedList, 8);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(2 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    printf("Adding the value 10 at the beginning of the chained list:\n");
    push_front(&myChainedList, 10);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(3 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    struct chainedItem* mySecondChainedList = createChainedListFirstIntegers(3);

    printf("Concatenate the chained list with another one, containing (0, 1, 2):\n");
    concatenateTwoChainedLists(&myChainedList, &mySecondChainedList);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(6 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    printf("Applying the square function to the chained list:\n");
    applyFunctionToAllElements(myChainedList, squareAValue);
    sizeOfChainedList = getSizeChainedList(myChainedList);
    printf("Size of the modified chained list : %i\n", sizeOfChainedList);
    assert(6 == sizeOfChainedList);
    displayChainedList(myChainedList);
    printf("-------------------------------\n");

    // Calling the function that realizes a lot of tests of the functions for boudarie case (when size of chained list is 0 or 1)
    testOfChainedListsFunction();
    printf("A bunch of test has been executed. See code to read more about those tests.");
    printf("-------------------------------\n");
}
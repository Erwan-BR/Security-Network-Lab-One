#ifndef exo3_h
#define exo3_h

#include <stdio.h>
#include <stdlib.h>

struct chainedItem
{
    int currentValue;
    struct chainedItem* addressPreviousValue;
    struct chainedItem* addressNextValue;
};

struct chainedItem* createNewChainedItem(int data);
struct chainedItem* createChainedListFirstIntegers(int number);
int getSizeChainedList(struct chainedItem* chainedList);
void displayChainedList(struct chainedItem* chainedList);
void pop_front(struct chainedItem* chainedList);
void pop_back(struct chainedItem* chainedList);
void push_back(struct chainedItem* chainedList, int value);
void concatenateTwoChainedLists(struct chainedItem* fistChainedList, struct chainedItem* secondChainedList);
void applyFunctionToAllElements(struct chainedItem* fistChainedList, int (*function_callback)(int));

#endif /* exo3_h */
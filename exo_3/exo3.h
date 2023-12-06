#ifndef exo3_h
#define exo3_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

struct chainedItem* pop_front(struct chainedItem** chainedList);
struct chainedItem* pop_back(struct chainedItem** chainedList);

void push_back(struct chainedItem** chainedList, int value);
void push_front(struct chainedItem** chainedList, int value);

void concatenateTwoChainedLists(struct chainedItem** fistChainedList, struct chainedItem** secondChainedList);
void applyFunctionToAllElements(struct chainedItem* chainedList, int (*function_callback)(int));

void testOfChainedListsFunction();

int squareAValue(int inputValue);
int doubleAValue(int inputValue);

#endif /* exo3_h */
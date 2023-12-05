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
void displayChainedList(struct chainedItem* chainedList);
void pop_front(struct chainedItem* chainedList);
void pop_back(struct chainedItem* chainedList);
void push_back(struct chainedItem* chainedList, int value);

#endif /* exo3_h */
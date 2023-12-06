#include "./exo3.h"

struct chainedItem* createNewChainedItem(int data)
{
    struct chainedItem* newChainedItem = (struct chainedItem*)malloc(sizeof(struct chainedItem));
    if (NULL == newChainedItem)
    {
        printf("Error of memory allocation for the chained list.\n");
        exit(1);
    }
    newChainedItem->currentValue = data;
    newChainedItem->addressPreviousValue = NULL;
    newChainedItem->addressNextValue = NULL;
    return newChainedItem;
}

struct chainedItem* createChainedListFirstIntegers(int number)
{
    if (0 >= number)
    {
        return NULL;
    }
    
    struct chainedItem* headOfChainedList = createNewChainedItem(0);
    struct chainedItem* currentElementFromChainedList = headOfChainedList;
    struct chainedItem* previousElementFromChainedList = headOfChainedList;

    for (int value = 1; number > value; value++)
    {
        previousElementFromChainedList = currentElementFromChainedList;
        currentElementFromChainedList->addressNextValue = createNewChainedItem(value);
        currentElementFromChainedList = currentElementFromChainedList->addressNextValue;
        currentElementFromChainedList->addressPreviousValue = previousElementFromChainedList;
    }

    return headOfChainedList;
}

int getSizeChainedList(struct chainedItem* chainedList)
{
    int sizeOfChainedList = 0;
    if (NULL == chainedList)
    {
        return sizeOfChainedList;
    }

    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        sizeOfChainedList++;

        currentElementFromList = currentElementFromList->addressNextValue;
    } while(NULL != currentElementFromList);

    return sizeOfChainedList;
}

void displayChainedList(struct chainedItem* chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }
    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        printf("Adress of the previous element: %p\t", currentElementFromList->addressPreviousValue);
        printf("Adress of the current element: %p\t", currentElementFromList);
        printf("Adress of the next element: %p\t", currentElementFromList->addressNextValue);
        printf("Value of the current Item :%i\n", currentElementFromList->currentValue);

        currentElementFromList = currentElementFromList->addressNextValue;
    } while(NULL != currentElementFromList);
}

void pop_front(struct chainedItem* chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }
    if (NULL == chainedList->addressNextValue)
    {
        chainedList = NULL;
    }
    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        currentElementFromList->currentValue = currentElementFromList->addressNextValue->currentValue;

        currentElementFromList = currentElementFromList->addressNextValue;
    } while(NULL != currentElementFromList->addressNextValue);

    currentElementFromList->addressPreviousValue->addressNextValue = NULL;
    free(currentElementFromList);
}

void pop_back(struct chainedItem* chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }
    if (NULL == chainedList->addressNextValue)
    {
        chainedList = NULL;
    }

    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        currentElementFromList = currentElementFromList->addressNextValue;
    } while(NULL != currentElementFromList->addressNextValue);

    currentElementFromList->addressPreviousValue->addressNextValue = NULL;
    free(currentElementFromList);
}

void push_back(struct chainedItem* chainedList, int value)
{
    struct chainedItem* newItem = createNewChainedItem(value);
    if (NULL == chainedList)
    {
        chainedList = newItem;
        return ;
    }
    if (NULL == chainedList->addressNextValue)
    {
        chainedList->addressNextValue = newItem;
        chainedList->addressNextValue->addressPreviousValue = chainedList->addressNextValue;
        return ;
    }

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        currentElementFromList = currentElementFromList->addressNextValue;
    } while(NULL != currentElementFromList->addressNextValue);

    currentElementFromList->addressNextValue = newItem;

    currentElementFromList->addressNextValue->addressPreviousValue = currentElementFromList;
}

void push_front(struct chainedItem* chainedList, int value)
{
    if (NULL == chainedList)
    {
        chainedList = createNewChainedItem(value);
        return ;
    }

    int oldCurrentValue ;
    int newValueToReplace = value;

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        oldCurrentValue = currentElementFromList->currentValue;
        currentElementFromList->currentValue = newValueToReplace;
        newValueToReplace = oldCurrentValue;
        currentElementFromList = currentElementFromList->addressNextValue;
    } while (NULL != currentElementFromList->addressNextValue);

    oldCurrentValue = currentElementFromList->currentValue;
    currentElementFromList->currentValue = newValueToReplace;
    currentElementFromList->addressNextValue = createNewChainedItem(oldCurrentValue);
    currentElementFromList->addressNextValue->addressPreviousValue = currentElementFromList;
}

void concatenateTwoChainedLists(struct chainedItem* fistChainedList, struct chainedItem* secondChainedList)
{
    if (NULL == fistChainedList)
    {
        fistChainedList = secondChainedList;
        return ;
    }
    struct chainedItem* currentElementFromList = fistChainedList;
    while(NULL != currentElementFromList->addressNextValue)
    {
        currentElementFromList = currentElementFromList->addressNextValue;
    }
    currentElementFromList->addressNextValue = secondChainedList;
}

void applyFunctionToAllElements(struct chainedItem* chainedList, int (*function_callback)(int))
{
    if (NULL == chainedList)
    {
        return ;
    }
    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        currentElementFromList->currentValue = function_callback(currentElementFromList->currentValue);
        currentElementFromList = currentElementFromList->addressNextValue;
    } while (NULL != currentElementFromList);
}

int squareAValue(int inputValue)
{
    return inputValue*inputValue;
}

int doubleAValue(int inputValue)
{
    return 2*inputValue;
}
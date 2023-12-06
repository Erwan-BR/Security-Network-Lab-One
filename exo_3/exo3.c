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

// Ameliorer en faisant des appels a push_back / push_front
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

    currentElementFromChainedList->addressNextValue = headOfChainedList;
    headOfChainedList->addressPreviousValue = currentElementFromChainedList;

    return headOfChainedList;
}

int getSizeChainedList(struct chainedItem* chainedList)
{
    int sizeOfChainedList = 0;
    if (NULL == chainedList)
    {
        return sizeOfChainedList;
    }

    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        sizeOfChainedList++;

        currentElementFromList = currentElementFromList->addressNextValue;
    } while((NULL != currentElementFromList) && (headAddress != currentElementFromList));

    return sizeOfChainedList;
}

void displayChainedList(struct chainedItem* chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }

    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        printf("Adress of the previous element: %p\t", currentElementFromList->addressPreviousValue);
        printf("Adress of the current element: %p\t", currentElementFromList);
        printf("Adress of the next element: %p\t", currentElementFromList->addressNextValue);
        printf("Value of the current item :%i\n", currentElementFromList->currentValue);

        currentElementFromList = currentElementFromList->addressNextValue;
    } while((NULL != currentElementFromList) && (headAddress != currentElementFromList));
}

// Changer pour un pointeur de pointeur pour changer la valeur du premier
// Debut d'essai dans pop_front_2
void pop_front(struct chainedItem* chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }
    if (NULL == chainedList->addressNextValue)
    {
        chainedList = NULL;
        return ;
    }

    const struct chainedItem* tailAddress = chainedList->addressPreviousValue->addressPreviousValue;
    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        currentElementFromList->currentValue = currentElementFromList->addressNextValue->currentValue;

        currentElementFromList = currentElementFromList->addressNextValue;
    } while((NULL != currentElementFromList->addressNextValue) && (headAddress != currentElementFromList->addressNextValue));

    currentElementFromList->addressPreviousValue->addressNextValue = (struct chainedItem*) headAddress;
    chainedList->addressPreviousValue = (struct chainedItem*) tailAddress;
    free(currentElementFromList);
}

void pop_front_2(struct chainedItem** chainedList)
{
    if (NULL == chainedList)
    {
        return ;
    }
    if (NULL == (*chainedList)->addressNextValue)
    {
        chainedList = NULL;
        return ;
    }

    (*chainedList)->addressPreviousValue->addressNextValue = (*chainedList)->addressNextValue;
    (*chainedList)->addressNextValue->addressPreviousValue = (*chainedList)->addressPreviousValue;
}

//A Ameliorer car comme c'est criculaire, pas besoin de tour reboucler.
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

    const struct chainedItem* newTailAddress = chainedList->addressPreviousValue->addressPreviousValue;
    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        currentElementFromList = currentElementFromList->addressNextValue;
    } while((NULL != currentElementFromList->addressNextValue) && (headAddress != currentElementFromList->addressNextValue));

    currentElementFromList->addressPreviousValue->addressNextValue = (struct chainedItem*) headAddress;
    chainedList->addressPreviousValue = (struct chainedItem*) newTailAddress;
    free(currentElementFromList);
}

//A Ameliorer car comme c'est criculaire, pas besoin de tour reboucler.
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

    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        currentElementFromList = currentElementFromList->addressNextValue;
    } while((NULL != currentElementFromList->addressNextValue) && (headAddress != currentElementFromList->addressNextValue));

    currentElementFromList->addressNextValue = newItem;

    currentElementFromList->addressNextValue->addressPreviousValue = currentElementFromList;
    currentElementFromList->addressNextValue->addressNextValue = (struct chainedItem*) headAddress;
    chainedList->addressPreviousValue = newItem;
}

//A changer avec un pointeur de pointeur.
void push_front(struct chainedItem* chainedList, int value)
{
    if (NULL == chainedList)
    {
        chainedList = createNewChainedItem(value);
        return ;
    }

    int oldCurrentValue ;
    int newValueToReplace = value;

    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;

    do
    {
        oldCurrentValue = currentElementFromList->currentValue;
        currentElementFromList->currentValue = newValueToReplace;
        newValueToReplace = oldCurrentValue;
        currentElementFromList = currentElementFromList->addressNextValue;
    } while ((NULL != currentElementFromList->addressNextValue) && (headAddress != currentElementFromList->addressNextValue));

    oldCurrentValue = currentElementFromList->currentValue;
    currentElementFromList->currentValue = newValueToReplace;
    currentElementFromList->addressNextValue = createNewChainedItem(oldCurrentValue);
    currentElementFromList->addressNextValue->addressPreviousValue = currentElementFromList;

    chainedList->addressPreviousValue = currentElementFromList->addressNextValue;
    currentElementFromList->addressNextValue->addressNextValue = (struct chainedItem*) headAddress;
}

void concatenateTwoChainedLists(struct chainedItem* fistChainedList, struct chainedItem* secondChainedList)
{
    if (NULL == fistChainedList)
    {
        fistChainedList = secondChainedList;
        return ;
    }
    if (NULL == secondChainedList)
    {
        return ;
    }
    

    const struct chainedItem* headAddressFirstChainedList = fistChainedList;
    const struct chainedItem* tailAddressFirstChainedList = fistChainedList->addressPreviousValue;
    const struct chainedItem* headAddressSecondChainedList = secondChainedList;
    const struct chainedItem* tailAddressSecondChainedList = secondChainedList->addressPreviousValue;

    fistChainedList->addressPreviousValue->addressNextValue = (struct chainedItem*)headAddressSecondChainedList;
    fistChainedList->addressPreviousValue = (struct chainedItem*)tailAddressSecondChainedList;
    secondChainedList->addressPreviousValue->addressNextValue = (struct chainedItem*)headAddressFirstChainedList;
    secondChainedList->addressPreviousValue = (struct chainedItem*)tailAddressFirstChainedList;
}

void applyFunctionToAllElements(struct chainedItem* chainedList, int (*function_callback)(int))
{
    if (NULL == chainedList)
    {
        return ;
    }

    const struct chainedItem* headAddress = chainedList;

    struct chainedItem* currentElementFromList = chainedList;
    do
    {
        currentElementFromList->currentValue = function_callback(currentElementFromList->currentValue);
        currentElementFromList = currentElementFromList->addressNextValue;
    } while ((NULL != currentElementFromList) && (headAddress != currentElementFromList));
}

int squareAValue(int inputValue)
{
    return inputValue*inputValue;
}

int doubleAValue(int inputValue)
{
    return 2*inputValue;
}
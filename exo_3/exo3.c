#include "./exo3.h"

/// @brief Create a single element from a circular chained list. By default, previous and next adresses are the adress of this element.
/// @param data Value to write in the element of the chained list.
/// @return Item containing the value, and that can be added to a circular chained list.
struct chainedItem* createNewChainedItem(int data)
{
    struct chainedItem* newChainedItem = (struct chainedItem*)malloc(sizeof(struct chainedItem));
    if (NULL == newChainedItem)
    {
        printf("Error of memory allocation for the chained list.\n");
        exit(1);
    }
    newChainedItem->currentValue = data;
    newChainedItem->addressPreviousValue = newChainedItem;
    newChainedItem->addressNextValue = newChainedItem;
    return newChainedItem;
}

/// @brief Make a chainedItem point to itself (make it alone, as for a circular chained list with only one element)
/// @param element Element to make it point to itself.
void cleanChainedItemPointers(struct chainedItem* element)
{
    element->addressNextValue = element;
    element->addressPreviousValue = element;
}

/// @brief Create a circular chained List of numbers from 0 to number-1.
/// @param number Number of element in the chained list. If number <=0, the output is NULL.
/// @return Created chainedItem.
struct chainedItem* createChainedListFirstIntegers(int number)
{
    if (0 >= number)
    {
        return NULL;
    }
    
    struct chainedItem* headOfChainedList = NULL;

    for (int value = 0; number > value; value++)
    {
        push_back(&headOfChainedList, value);
    }
    return headOfChainedList;
}

/// @brief Get the size of a circular chained list.
/// @param chainedList Circular chained list of which we want the size.
/// @return Size of the given chained list.
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
    } while(headAddress != currentElementFromList);

    return sizeOfChainedList;
}

/// @brief Display a circular chained list in the terminal. If the list is empty, nothing is displayed.
/// @param chainedList Circular chained list to display.
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
    } while(headAddress != currentElementFromList);
}

/// @brief Pop the first element of a circular chained list.
/// @param chainedList List which the first element has to be deleted.
/// @return Element popped.
struct chainedItem* pop_front(struct chainedItem** chainedList)
{
    int sizeOfChainedList = getSizeChainedList(*chainedList);
    if (0 == sizeOfChainedList)
    {
        *chainedList = NULL;
        return NULL;
    }

    struct chainedItem* elementToReturn = *chainedList;

    if (1 == sizeOfChainedList)
    {
        *chainedList = NULL;
        return elementToReturn;
    }

    struct chainedItem* tailAddress = (*chainedList)->addressPreviousValue;
    struct chainedItem* newHeadAddress = (*chainedList)->addressNextValue;

    tailAddress->addressNextValue = newHeadAddress;
    newHeadAddress->addressPreviousValue = tailAddress;

    *chainedList = newHeadAddress;

    cleanChainedItemPointers(elementToReturn);
    return elementToReturn;
}

/// @brief Pop the last element of a circular chained list.
/// @param chainedList List which the last element has to be deleted.
/// @return Element popped.
struct chainedItem* pop_back(struct chainedItem** chainedList)
{
    int sizeOfChainedList = getSizeChainedList(*chainedList);
    if (0 == sizeOfChainedList)
    {
        *chainedList = NULL;
        return NULL;
    }

    struct chainedItem* elementToReturn = (*chainedList)->addressPreviousValue;

    if (1 == sizeOfChainedList)
    {
        *chainedList = NULL;
        return elementToReturn;
    }

    struct chainedItem* newTailAddress = (*chainedList)->addressPreviousValue->addressPreviousValue;
    struct chainedItem* headAddress = (*chainedList);

    newTailAddress->addressNextValue = headAddress;
    headAddress->addressPreviousValue = newTailAddress;

    cleanChainedItemPointers(elementToReturn);
    return elementToReturn;
}

/// @brief Push a new element at the end of a circular chained list.
/// @param chainedList Circular chained list of which a new element has to be added.
/// @param value Value of the element to add to this circular chained list, in the last position. 
void push_back(struct chainedItem** chainedList, int value)
{
    struct chainedItem* newItem = createNewChainedItem(value);

    int sizeOfChainedList = getSizeChainedList(*chainedList);
    
    if (0 == sizeOfChainedList)
    {
        *chainedList = newItem;
        return ;
    }
    if (1 == sizeOfChainedList)
    {
        (*chainedList)->addressNextValue = newItem;
        (*chainedList)->addressPreviousValue = newItem;
        newItem->addressNextValue = (*chainedList);
        newItem->addressPreviousValue = (*chainedList);

        return ;
    }
    struct chainedItem* oldTailAddress = (*chainedList)->addressPreviousValue;
    struct chainedItem* headAddress = (*chainedList);

    headAddress->addressPreviousValue = newItem;
    oldTailAddress->addressNextValue = newItem;
    newItem->addressNextValue = headAddress;
    newItem->addressPreviousValue = oldTailAddress;
}

/// @brief Push a new element at the begining of a circular chained list.
/// @param chainedList Circular chained list of which a new element has to be added.
/// @param value Value of the element to add to this circular chained list, in the first position. 
void push_front(struct chainedItem** chainedList, int value)
{
    struct chainedItem* newItem = createNewChainedItem(value);
    
    int sizeOfChainedList = getSizeChainedList(*chainedList);
    
    if (0 == sizeOfChainedList)
    {
        *chainedList = newItem;
        return ;
    }
    if (1 == sizeOfChainedList)
    {
        (*chainedList)->addressNextValue = newItem;
        (*chainedList)->addressPreviousValue = newItem;
        newItem->addressNextValue = (*chainedList);
        newItem->addressPreviousValue = (*chainedList);

        (*chainedList) = newItem;
        return ;
    }

    struct chainedItem* tailAddress = (*chainedList)->addressPreviousValue;
    struct chainedItem* oldHeadAddress = (*chainedList);

    oldHeadAddress->addressPreviousValue = newItem;
    tailAddress->addressNextValue = newItem;
    newItem->addressNextValue = oldHeadAddress;
    newItem->addressPreviousValue = tailAddress;

    (*chainedList) = newItem;
}

/// @brief Concatenate two circular chained list into the first one.
/// @param fistChainedList First circular chained list, placed first for the output.
/// @param secondChainedList Second circular chained list, placed second for the output.
void concatenateTwoChainedLists(struct chainedItem** fistChainedList, struct chainedItem** secondChainedList)
{
    if (NULL == *fistChainedList)
    {
        *fistChainedList = *secondChainedList;
        return ;
    }
    if (NULL == *secondChainedList)
    {
        return ;
    }

    const struct chainedItem* headAddressFirstChainedList = *fistChainedList;
    const struct chainedItem* tailAddressFirstChainedList = (*fistChainedList)->addressPreviousValue;
    const struct chainedItem* headAddressSecondChainedList = *secondChainedList;
    const struct chainedItem* tailAddressSecondChainedList = (*secondChainedList)->addressPreviousValue;

    (*fistChainedList)->addressPreviousValue->addressNextValue = (struct chainedItem*)headAddressSecondChainedList;
    (*fistChainedList)->addressPreviousValue = (struct chainedItem*)tailAddressSecondChainedList;
    (*secondChainedList)->addressPreviousValue->addressNextValue = (struct chainedItem*)headAddressFirstChainedList;
    (*secondChainedList)->addressPreviousValue = (struct chainedItem*)tailAddressFirstChainedList;
}

/// @brief Apply a function to all elements of a circular chained list. This function is like a map.
/// @param chainedList Circular chained list of elements to be modified.
/// @param function_callback Function applied to every elements.
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
    } while (headAddress != currentElementFromList);
}

/// @brief Bunch of tests of chained list to check that boundaries case work.
void testOfChainedListsFunction()
{
    /**************************** Applying methods for case of 0-1 element in the chained list. ****************************/
    /***************************************** Purpose: Testing if functions work. *****************************************/
    struct chainedItem* testingLimitChainedList = createChainedListFirstIntegers(0);
    int sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    (void)pop_front(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    (void)pop_back(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    push_front(&testingLimitChainedList, 4);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfLimitChainedList);
    assert(4 == testingLimitChainedList->currentValue);

    (void)pop_front(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    push_front(&testingLimitChainedList, 8);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfLimitChainedList);
    assert(8 == testingLimitChainedList->currentValue);

    (void)pop_back(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    push_back(&testingLimitChainedList, 16);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfLimitChainedList);
    assert(16 == testingLimitChainedList->currentValue);

    (void)pop_front(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    push_back(&testingLimitChainedList, 32);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfLimitChainedList);
    assert(32 == testingLimitChainedList->currentValue);

    (void)pop_back(&testingLimitChainedList);
    sizeOfLimitChainedList = getSizeChainedList(testingLimitChainedList);
    assert(0 == sizeOfLimitChainedList);
    assert(NULL == testingLimitChainedList);

    /**************************** Applying methods for case of 1-2 element in the chained list. ****************************/
    /***************************************** Purpose: Testing if functions work. *****************************************/
    struct chainedItem* testingLimitChainedList_V2 = createChainedListFirstIntegers(1);
    int sizeOfLimitChainedList_V2 = getSizeChainedList(testingLimitChainedList_V2);
    assert(1 == sizeOfLimitChainedList_V2);
    assert(0 == testingLimitChainedList_V2->currentValue);

    push_front(&testingLimitChainedList_V2, 4);
    sizeOfLimitChainedList_V2 = getSizeChainedList(testingLimitChainedList_V2);
    assert(2 == sizeOfLimitChainedList_V2);
    assert(4 == testingLimitChainedList_V2->currentValue);
    assert(0 == testingLimitChainedList_V2->addressNextValue->currentValue);

    (void)pop_back(&testingLimitChainedList_V2);
    sizeOfLimitChainedList_V2 = getSizeChainedList(testingLimitChainedList_V2);
    assert(1 == sizeOfLimitChainedList_V2);
    assert(4 == testingLimitChainedList_V2->currentValue);

    push_back(&testingLimitChainedList_V2, 8);
    sizeOfLimitChainedList_V2 = getSizeChainedList(testingLimitChainedList_V2);
    assert(2 == sizeOfLimitChainedList_V2);
    assert(4 == testingLimitChainedList_V2->currentValue);
    assert(8 == testingLimitChainedList_V2->addressNextValue->currentValue);

    (void)pop_front(&testingLimitChainedList_V2);
    sizeOfLimitChainedList_V2 = getSizeChainedList(testingLimitChainedList_V2);
    assert(1 == sizeOfLimitChainedList_V2);
    assert(8 == testingLimitChainedList_V2->currentValue);

    /***************************** Testing concatenation to check if every case work properly. *****************************/
    // Testing when the first one is NULL.
    concatenateTwoChainedLists(&testingLimitChainedList, &testingLimitChainedList_V2);
    int sizeOfConcatenated = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfConcatenated);
    assert(8 == testingLimitChainedList->currentValue);

    // Testing when the second one is NULL.
    testingLimitChainedList_V2 = createChainedListFirstIntegers(0);
    concatenateTwoChainedLists(&testingLimitChainedList, &testingLimitChainedList_V2);
    sizeOfConcatenated = getSizeChainedList(testingLimitChainedList);
    assert(1 == sizeOfConcatenated);
    assert(8 == testingLimitChainedList->currentValue);
}

int squareAValue(int inputValue)
{
    return inputValue*inputValue;
}

int doubleAValue(int inputValue)
{
    return 2*inputValue;
}
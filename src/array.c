#include "./array.h"

/**
 * Initializes the Array.
 * @return  Array*  The initialized array.
 **/
Array* init() {
    Array* newArray = malloc(sizeof(Array));
    
    newArray->head = NULL;
    newArray->tail = NULL;
    newArray->length = 0;

    return newArray;
}

/**
 * Destroys and Free's up the memory for a given array.
 **/
void drop(Array* array) {
    Item* currItem = array->head;
    Item* prevItem = currItem;

    while (currItem != NULL) {
        prevItem = currItem;
        free(currItem);
        currItem = prevItem->next;
    }

    free(array);
}

/**
 * Clones a given array.
 * @return  Array*  The clone array.
 **/
Array* clone(Array* array) {
    if (array->head == NULL) {
        return init();
    }

    Item* currItem = array->head;

    Array* clone = init();
    Item* currCloneItem = clone->head;

    while (currItem != NULL) {
        Item clonedItem = (*currItem);
        currCloneItem = &clonedItem;

        currItem = currItem->next;
        currCloneItem = currCloneItem->next;
    }

    return clone;
}


/**
 * Update Item's indexes on updates.
 **/
void updateIndexes(Array* array) {
    Item* currItem = array->head;
    uInt index = 0;
    uInt length = 0;

    while (currItem != NULL) {
        currItem->index = index;
        array->tail = currItem;
        currItem = currItem->next;
        
        index += 1;
        length += 1;
    }

    array->length = length;
}


/**
 * Compares the currItem data to the given data.
 * @return  uInt    true or false.
 **/
uInt compare(Data currData, Data compareData) {
    // Implement your own compare function if you are using custom Data datatypes.
    return currData == compareData;
}

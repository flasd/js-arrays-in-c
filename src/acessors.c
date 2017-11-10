#include "./acessors.h"

/**
 * Joins two arrays together.
 * @return  Array*  The new array.
 **/
Array* concat(Array* first, Array* second) {
    first->tail->next = second->head;
    updateIndexes(first);
    return first;
}

/**
 * Determines whether an array contains a certain element.
 * @return  uInt    true or false
 **/
uInt includes(Data data, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        if (compare(currItem->data, data)) {
            return 1;
        }

        currItem = currItem->next;
    }

    return 0;
}

/**
 * Searches the array for a value, stoping at the first match.
 * @return  int     The index of the found element or -1 if not found.
 **/
int indexOf(Data data, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        if (compare(currItem->data, data)) {
            return currItem->index;
        }

        currItem = currItem->next;
    }

    return -1;
}

/**
 * Searches the array for a value until the tail.
 * @return  int     The index of the last match or -1 if not found.
 **/
int lastIndexOf(Data data, Array* array) {
    Item* currItem = array->head;
    int lastIndex = -1;

    while (currItem != NULL) {
        if (compare(currItem->data, data)) {
            lastIndex = currItem->index;
        }

        currItem = currItem->next;
    }

    return lastIndex;
}

/**
 * Extracts a section of an array.
 * @return  Array*  Extracted array.
 **/
Array* slice(uInt begin, uInt end, Array* array) {
    Array* sourceArray = clone(array);

    Item* currItem = sourceArray->head;
    Item* prevItem = currItem;

    Array* newArray = init();
    Item* newArrItem = newArray->head;

    uInt mode = 0;

    while (currItem != NULL) {
        if (currItem->index < begin || currItem->index > end) {
            prevItem = currItem;
            currItem = currItem->next;

            free(prevItem);

            continue;
        }

        if (currItem->index == begin) {
            newArrItem = currItem;
        }

        if (currItem->index == end) {
            newArrItem->next = NULL;
        }
        
        newArrItem = newArrItem->next != NULL ? newArrItem->next : newArrItem;
        currItem = currItem->next; 
    }

    updateIndexes(newArray);
    return newArray;
}

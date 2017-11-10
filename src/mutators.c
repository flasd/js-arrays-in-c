#include "./mutators.h"

/**
 * Fills all the elements of an array from a start index to an
 * end index with a static value.
 **/
void fill(Data data, int start, int end, Array* array) {
    Item* currItem = array->head;
    
    while (currItem != NULL) {
        if (currItem->index >= start && currItem->index <= end) {
            currItem->data = data;
        }

        currItem = currItem->next;
    }
}

/**
 * Removes the last element from an array.
 * @return  Item*   The removed item.
 **/
Item* pop(Array* array) {
    Item* currItem = array->head;
    Item* prevItem = currItem;
    
    while (currItem->next != NULL) {
        prevItem = currItem;
        currItem = currItem->next;
    }
    
    prevItem->next = NULL;
    updateIndexes(array);
    return currItem;
}

/**
 * Adds one or more elements to the end of an array.
 * @return  uInt    New length of the array.
 **/
uInt push(Data data, Array* array) {
    Item* newItem = malloc(sizeof(Item));

    newItem->data = data;
    newItem->index = array->length;
    
    array->length += (uInt) 1;
    
    Item* currItem = array->head;
    Item* prevItem = currItem;

    if (currItem == NULL) {
        array->head = newItem;
        return newItem->index;
    }
    
    while (currItem->next != NULL) {
        currItem = currItem->next;
    }

    currItem->next = newItem;

    updateIndexes(array);
    return newItem->index;
}

/**
 * Reverses an array.
 **/
void reverse(Array* array) {
    Item* currItem = array->head;
    Item* reversedItem = NULL;
    Item* tempItem = NULL;

    while (currItem != NULL) {
        tempItem = currItem;

        currItem = currItem->next;
        tempItem->next = reversedItem;
        
        reversedItem = tempItem;
    }

    array->head = reversedItem;
    updateIndexes(array);
}

/**
 * Removes the first element from an array.
 * @return  Item*   The removed item.
 **/
Item* shift(Array* array) {
    Item* currItem = array->head;
    
    if (currItem == NULL) {
        return NULL;
    }
    
    array->head = currItem->next;
    free(currItem);
    updateIndexes(array);
}

/**
 * Sorts the elements of an array.
 **/
void sort(Comparator fn, Array* array) {
    for (uInt i = array->length; i > 0; i -= 1) {
        Item* currItem = array->head;
        Item* prevItem = currItem;
        Item* nextItem = currItem->next;

        while (currItem != NULL) {
            nextItem = currItem->next;

            if (nextItem == NULL) {
                break;
            }

            const uInt shouldReplace = fn(currItem->data, nextItem->data);

            if (shouldReplace) {
                prevItem->next = nextItem;
                currItem->next = nextItem->next;
                nextItem->next = currItem;
            }

            prevItem = currItem;
            currItem = currItem->next;
        }
    }
    updateIndexes(array);
}

/**
 * Changes the contents of an array by removing existing elements.
 **/
void splice(uInt start, uInt deleteCount, Array* array) {
    Item* currItem = array->head;
    Item* prevItem = currItem;

    Array* newArray = init();
    Item* newArrItem = newArray->head;

    uInt mode = 0;
    uInt end = start + deleteCount;

    while (currItem != NULL) {
        if (currItem->index < start || currItem->index > end) {
            prevItem = currItem;
            currItem = currItem->next;

            free(prevItem);

            continue;
        }

        if (currItem->index == start) {
            newArrItem = currItem;
        }

        if (currItem->index == end) {
            newArrItem->next = NULL;
        }
        
        newArrItem = newArrItem->next != NULL ? newArrItem->next : newArrItem;
        currItem = currItem->next; 
    }

    drop(array);
    updateIndexes(newArray);
    (*array) = (*newArray);
}

/**
 * Adds one or more elements to the beginning of an array.
 **/
void unshift(Item* item, Array* array) {
    Array* unshiftedArr = init();

    item->next = array->head;
    unshiftedArr->head = item;

    updateIndexes(unshiftedArr);
    (*array) = (*unshiftedArr);
}

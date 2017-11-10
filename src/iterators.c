#include "./iterators.h"

/**
 * Returns true if every element in this array satisfies the
 * provided testing function.
 * @return  uInt    true or false
 **/
uInt every(Iterator fn, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        const uInt isTrue = fn(currItem->data, currItem->index, array);
        
        if (!isTrue) {
            return 0;
        }

        currItem = currItem->next;
    }

    return 1;
}

/**
 * Creates a new array with all of the elements of this array
 * for which the provided filtering function returns true.
 * @return  Array*  The filtered array.
 **/
Array* filter(Iterator fn, Array* array) {
    Item* currItem = array->head;
    
    Array* filteredArray = init();
    
    while (currItem != NULL) {
        const uInt passTest = fn(currItem->data, currItem->index, array);

        if (passTest) {
            push(currItem->data, array);
        }
        
        currItem = currItem->next;
    }
    
    updateIndexes(filteredArray);
    return filteredArray;
}

/**
 * Returns the found value in the array, if an element in the array
 * satisfies the provided testing function or undefined if not found.
 * @return  Item*   Found Item or NULL
 **/
Item* find(Iterator fn, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        const uInt found = fn(currItem->data, currItem->index, array);
        
        if (found) {
            return currItem;
        }

        currItem = currItem->next;
    }

    return NULL;
}

/**
 * Returns the found index in the array, if an element in the array
 * satisfies the provided testing function or -1 if not found.
 * @return  int Found index or -1
 **/
int findIndex(Iterator fn, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        const uInt found = fn(currItem->data, currItem->index, array);
        
        if (found) {
            return currItem->index;
        }

        currItem = currItem->next;
    }

    return -1;
}

/**
 * Calls a function for each element in the array.
 **/
void forEach(Iterator fn, Array* array) {
    Item* currItem = array->head;
    
    while (currItem != NULL) {
        fn(currItem->data, currItem->index, array);

        currItem = currItem->next;
    }
}

/**
 * Creates a new array with the results of calling a provided function
 * on every element in this array.
 * @return  Array*  The mapped array.
 **/
Array* map(Iterator fn, Array* array) {
    Array* sourceArr = clone(array);
    Item* currItem = sourceArr->head;
    
    while (currItem != NULL) {
        currItem->data = fn(currItem->data, currItem->index, array);

        currItem = currItem->next;
    }

    updateIndexes(sourceArr);
    return sourceArr;
}

/**
 * Applies a function against an accumulator and each element in the array
 * (from left to right) to reduce it to a single value.
 * @return  Data    The accumulator.
 **/
Data reduce(Reducer fn, Data initialValue, Array* array) {
    Data accumulator;
    Item* currItem = array->head;

    while (currItem != NULL) {
        accumulator = fn(accumulator, currItem->data, currItem->index, array);
        currItem = currItem->next;
    }

    return accumulator;
}

/**
 * Apply a function against an accumulator and each value of the array
 * (from right-to-left) as to reduce it to a single value.
 * @return  Data    The accumulator.
 **/
Data reduceRight(Reducer fn, Data initialValue, Array* array) {
    reverse(array);
    
    Data accumulator;
    Item* currItem = array->head;

    while (currItem != NULL) {
        accumulator = fn(accumulator, currItem->data, currItem->index, array);
        currItem = currItem->next;
    }

    return accumulator;
}

/**
 * Returns true if at least one element in this array satisfies the provided
 * testing function.
 * @return  uInt    true or false
 **/
uInt some(Iterator fn, Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        const uInt isTrue = fn(currItem->data, currItem->index, array);
        
        if (isTrue) {
            return 1;
        }

        currItem = currItem->next;
    }

    return 0;
}

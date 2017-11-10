#ifndef __ARRAY_MUTATORS_H__
#define __ARRAY_MUTATORS_H__

#include "./types.h"
#include "./array.h"

// Mutators

/**
 * Fills all the elements of an array from a start index to an
 * end index with a static value.
 **/
void fill(Data data, int start, int end, Array* array);

/**
 * Removes the last element from an array.
 * @return  Item*   The removed item.
 **/
Item* pop(Array* array);

/**
 * Adds one or more elements to the end of an array.
 * @return  uInt    New length of the array.
 **/
uInt push(Data data, Array* array);

/**
 * Reverses an array.
 **/
void reverse(Array* array);

/**
 * Removes the first element from an array.
 * @return  Item*   The removed item.
 **/
Item* shift(Array* array);

/**
 * Sorts the elements of an array.
 **/
void sort(Comparator fn, Array* array);

/**
 * Changes the contents of an array by removing existing elements.
 **/
void splice(uInt start, uInt deleteCount, Array* array);

/**
 * Adds one or more elements to the beginning of an array.
 **/
void unshift(Item* item, Array* array);

#endif

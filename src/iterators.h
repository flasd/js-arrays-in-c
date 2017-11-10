#ifndef __ARRAY_ITERATORS_H__
#define __ARRAY_ITERATORS_H__

#include "./types.h"
#include "./array.h"

/**
 * Returns true if every element in this array satisfies the
 * provided testing function.
 * @return  uInt    true or false
 **/
uInt every(Iterator fn, Array* array);

/**
 * Creates a new array with all of the elements of this array
 * for which the provided filtering function returns true.
 * @return  Array*  The filtered array.
 **/
Array* filter(Iterator fn, Array* array);

/**
 * Returns the found value in the array, if an element in the array
 * satisfies the provided testing function or undefined if not found.
 * @return  Item*   Found Item or NULL
 **/
Item* find(Iterator fn, Array* array);

/**
 * Returns the found index in the array, if an element in the array
 * satisfies the provided testing function or -1 if not found.
 * @return  int Found index or -1
 **/
int findIndex(Iterator fn, Array* array);

/**
 * Calls a function for each element in the array.
 **/
void forEach(Iterator fn, Array* array);

/**
 * Creates a new array with the results of calling a provided function
 * on every element in this array.
 * @return  Array*  The mapped array.
 **/
Array* map(Iterator fn, Array* array);

/**
 * Applies a function against an accumulator and each element in the array
 * (from left to right) to reduce it to a single value.
 * @return  Data    The accumulator.
 **/
Data reduce(Reducer fn, Data initialValue, Array* array);

/**
 * Apply a function against an accumulator and each value of the array
 * (from right-to-left) as to reduce it to a single value.
 * @return  Data    The accumulator.
 **/
Data reduceRight(Reducer fn, Data initialValue, Array* array);

/**
 * Returns true if at least one element in this array satisfies the provided
 * testing function.
 * @return  uInt    true or false
 **/
uInt some(Iterator fn, Array* array);

#endif

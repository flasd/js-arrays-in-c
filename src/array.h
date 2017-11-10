#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>
#include "./types.h"

// Managers

/**
 * Initializes the Array.
 * @return  Array*  The initialized array.
 **/
Array* init();

/**
 * Destroys and Free's up the memory for a given array.
 **/
void drop(Array* array);

/**
 * Clones a given array.
 * @return  Array*  The clone array.
 **/
Array* clone(Array* array);

/**
 * Update Item's indexes on updates.
 **/
void updateIndexes(Array* array);

/**
 * Compares the currItem data to the given data.
 * @return  uInt    true or false.
 **/
uInt compare(Data currData, Data compareDate);

#include "./acessors.h"
#include "./iterators.h"
#include "./mutators.h"

#endif

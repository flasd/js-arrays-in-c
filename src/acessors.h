#ifndef __ARRAY_ACESSORS_H__
#define __ARRAY_ACESSORS_H__

#include "./types.h"
#include "./array.h"

// Acessors

/**
 * Joins two arrays together.
 * @return  Array*  The new array.
 **/
Array* concat(Array* head, Array* tail);

/**
 * Determines whether an array contains a certain element.
 * @return  uInt    true or false
 **/
uInt includes(Data data, Array* array);

/**
 * Searches the array for a value, stoping at the first match.
 * @return  int     The index of the found element or -1 if not found.
 **/
int indexOf(Data data, Array* array);

/**
 * Searches the array for a value until the tail.
 * @return  int     The index of the last match or -1 if not found.
 **/
int lastIndexOf(Data data, Array* array);

/**
 * Extracts a section of an array.
 * @return  Array*  Extracted array.
 **/
Array* slice(uInt begin, uInt end, Array* array);

#endif

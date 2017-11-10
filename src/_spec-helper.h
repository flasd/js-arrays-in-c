#ifndef __SPEC_HELPER_H__
#define __SPEC_HELPER_H__

#include <stdio.h>

/**
 * Js Style describe("something", fn);
 **/
void describe(char* title, void (*fn)(void));

/**
 * Alias to describe
 **/
typedef describe it;

/**
 * Assert condition
 * @return  int     true or false
 **/
int assert(int assertion, char* message, int* testCount);

#endif

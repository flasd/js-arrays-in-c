#ifndef ARR_TYPES_H
#define ARR_TYPES_H

typedef int Data;
typedef unsigned int uInt;

typedef struct Item {
    Data data;
    uInt index;
    struct Item* next;
} Item;

typedef struct Array {
    Item* head;
    Item* tail;
    uInt length;
} Array;

typedef uInt (*Iterator)(Data /* currItem */, uInt /* currIndex */, Array*);
typedef Data (*Reducer)(Data /* accumulator */, Data /* currItem */, uInt /* currIndex */, Array*);
typedef uInt (*Comparator)(Data /* itemA */, Data /* itemB */);

#endif

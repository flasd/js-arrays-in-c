#include <stdio.h>
#include "./array.h"

#include "./acessors.spec.c"
#include "./array.spec.c"
#include "./iterators.spec.c"
#include "./mutators.spec.c"

int printArray(Array* array) {
    Item* currItem = array->head;

    while (currItem != NULL) {
        printf("Index: %d. Data: %d\n", currItem->index, currItem->data);
        currItem = currItem->next;
    }
}

int main(void) {
    int testCount = 0;
    Array* myArr = init();

    assert(myArr->length == 0, "Array Type Error", &testCount);

    uInt pushResult = push(3, myArr);
    assert(pushResult == 0, "Pushin return the index", &testCount);
    assert(myArr->head->data == 3, "Pushed the wrong item", &testCount);
    
    drop(myArr);
}
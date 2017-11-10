#include "./_spec-helper.h"

void describe(char* title, void (*fn)(void)) {
    printf("%s\n", title);
    fn();
}

int assert(int assertion, char* message, int* testCount) {
    (*testCount) += 1;

    if (assertion) {
        printf(" [✓] %d Passed!\n", (*testCount));
    } else {
        printf(" [x] %d Failed.\n %s\n", (*testCount), message);
        
        // throw to stop execution.
        int* p = NULL;
        (*p) += 1;
    }
}

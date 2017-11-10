#include "./_spec-helper.h"

void everySpec(void) {
    /* every Assertions */
}

void filterSpec(void) {
    /* filter Assertions */
}

void findSpec(void) {
    /* find Assertions */
}

void findIndexSpec(void) {
    /* findIndex Assertions */
}

void forEachSpec(void) {
    /* forEach Assertions */
}

void mapSpec(void) {
    /* map Assertions */
}

void reduceSpec(void) {
    /* reduce Assertions */
}

void reduceRightSpec(void) {
    /* reduceRight Assertions */
}

void someSpec(void) {
    /* some Assertions */
}

void iteratorSpec(void) {
    it("", &everySpec);
    it("", &filterSpec);
    it("", &findSpec);
    it("", &findIndexSpec);
    it("", &forEachSpec);
    it("", &mapSpec);
    it("", &reduceSpec);
    it("", &reduceRightSpec);
    it("", &someSpec);
}

describe("", &iteratorSpec);

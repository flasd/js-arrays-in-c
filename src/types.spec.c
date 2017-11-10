#include "./_spec-helper.h"
#include "./mutators.h"

void DataSpec(void) {
    /* Data Assertions */
}

void uIntSpec(void) {
    /* uInt Assertions */
}

void ItemSpec(void) {
    /* Item Assertions */
}

void ArraySpec(void) {
    /* Array Assertions */
}

void IteratorSpec(void) {
    /* Iterator Assertions */
}

void ReducerSpec(void) {
    /* Reducer Assertions */
}

void ComparatorSpec(void) {
    /* Comparator Assertions */
}



void typeSpec(void) {
    it("", &DataSpec);
    it("", &uIntSpec);
    it("", &ItemSpec);
    it("", &ArraySpec);
    it("", &IteratorSpec);
    it("", &ReducerSpec);
    it("", &ComparatorSpec);
}

describe("", &typeSpec);

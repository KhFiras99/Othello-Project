#include <iostream>
#include "Case.h"

using namespace std;
Case::Case() :value('0') {}
Case::Case(char c) : value(c) {}
Case::~Case() {}

char Case::getValue() {
    return value;
}
void Case::setValue(char v) {
    value = v;
}
void Case::operator=(const Case& C) {
    if (this != &C) {
        value = C.value;
    }
}
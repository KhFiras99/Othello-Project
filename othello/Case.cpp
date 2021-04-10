/*
#include <iostream>
#include "Case.h"

using namespace std;

Case::Case() :ligne(0), colonne(0), value(0){}
Case::Case(int a, int b, int c) :ligne(a), colonne(b), value(c) {}
Case::~Case() {}

int Case::getLine() {
	return ligne;
}
int Case::getColonne() {
	return colonne;
}
int Case::getValue() {
	return value;
}
void Case::operator=(const Case& C) {
    if (this != &C) {
        ligne = C.ligne;
        colonne = C.colonne;
        value = C.value;
    }
}

*/
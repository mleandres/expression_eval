#include <string>
#include <iostream>
#include "Expression.h"

// default ctor is good

// will be overridden by Variable
void Expression::set(const string &s, const int x) {
	return;
}

// will be overridden by Variable
void Expression::unset(const string &s) {
	return;
}

// dtor for Integer and Variable
Expression::~Expression() {}

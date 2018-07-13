#include <string>
#include <iostream>
#include "Integer.h"

using namespace std;

Integer::Integer(const int val = 0) :  val{val} {}

// prints just the val of Integer expression
void Integer::prettyprint(ostream &out) const {
	out << val;
}

// evaluates returns the integer value
int Integer::evaluate() const {
	return val;
}

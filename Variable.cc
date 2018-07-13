#include <iostream>
#include <string>
#include "Variable.h"

using namespace std;

Variable::Variable(const string &name) : name{name}, val{0}, isSet{false} {}

void Variable::set(const string &s, const int x) {
	if (name == s) {
		isSet = true;
		val = x;
	}
}

void Variable::unset(const string &s) {
	if (name == s) isSet = false;
}

void Variable::prettyprint(ostream &out) const {
	// if variable is set then print the value
	if (isSet) out << val;

	// otherwise print name
	else out << name;
}

// returns val (iSset will be handled by main)
int Variable::evaluate() const {
	if (isSet == false) {
		throw name;
	}
	return val;
}


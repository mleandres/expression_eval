#include <iostream>
#include <string>
#include "Unaryop.h"

using namespace std;

Unaryop::Unaryop(const string &type, Expression *arg) : type{type}, arg{arg} {}

void Unaryop::prettyprint(ostream &out) const {
	// case if type is absolute value:
	//   |arg|
	if (type == "ABS") {
		out << "|";
		arg->prettyprint(out);
		out << "|";
	}

	// case if type is negative:
	//   -arg
	else if (type == "NEG") {
		out << "-";
		arg->prettyprint(out);
	}
}

void Unaryop::set(const string &s, const int x) {
	arg->set(s, x);
}

void Unaryop::unset(const string &s) {
	arg->unset(s);
}

int Unaryop::evaluate() const {
	int ans = arg->evaluate();
	// case if type is absolute value
	if (type == "ABS") {
		if (ans < 0) ans *=-1;
	}

	// case if type is negative
	else if (type == "NEG") {
		ans *= -1;
	}
	return ans;
}

// need to destroy arg expression
Unaryop::~Unaryop() {
	delete arg;
}

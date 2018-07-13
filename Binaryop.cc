#include <iostream>
#include <string>
#include "Binaryop.h"

using namespace std;

Binaryop::Binaryop(const string &type, Expression *lhs, Expression *rhs)
	: type{type}, lhs{lhs}, rhs{rhs} {}

void Binaryop::prettyprint(ostream &out) const {
	out << "(";
	lhs->prettyprint(out);
	out << " " << type << " ";
	rhs->prettyprint(out);
	out << ")";
}

void Binaryop::set(const string &s, const int x) {
	lhs->set(s, x);
	rhs->set(s, x);
}

void Binaryop::unset(const string &s) {
	lhs->unset(s);
	rhs->unset(s);
}

int Binaryop::evaluate() const {
	int ans = 0;
	int lans = lhs->evaluate();
	int rans = rhs->evaluate();
	if (type == "+") {
		ans = lans + rans;
	}
	else if (type == "-") {
		ans = lans - rans;
	}
	else if (type == "*") {
		ans = lans * rans;
	}
	else if (type == "/") {
		if (rans == 0) throw 1337;
		ans = lans / rans;
	}
	return ans;
}

// need to destroy lhs and rhs expressions
Binaryop::~Binaryop() {
	delete lhs;
	delete rhs;
}

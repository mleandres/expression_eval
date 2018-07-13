#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Expression {

public:

	// pure virtual method that prints out an expression without a newline
	virtual void prettyprint(ostream &out) const = 0;

	// sets a variable with name s to the value x
	virtual void set(const string &s, const int x);

	// unsets the variable with the name s
	virtual void unset(const string &s);

	// pure virtual method that returns an int of an evaluated expression
	virtual int evaluate() const = 0;

	virtual ~Expression();
};

#endif

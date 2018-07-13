#ifndef VARIABLE_H
#define VARIABLE_H
#include <string>
#include "Expression.h"

using namespace std;

class Variable final : public Expression {
	string name;
	int val;
	bool isSet;

public:

	// Constructor with one parameter
	Variable(const string &name);

	// prints the variable name if not set or the value if set to the ostream out
	void prettyprint(ostream &out) const override;

	// Sets the value x to the variable if the string s matches the name
	void set(const string &s, const int x) override;

	// unset the variable if the string s matches the name
	void unset(const string &s) override;

	// returns the value set to x. throws the name as an exception if not set
	int evaluate() const override;

};

#endif

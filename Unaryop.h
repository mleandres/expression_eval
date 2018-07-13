#ifndef UNARYOP_H
#define UNARYOP_H
#include <string>
#include "Expression.h"

using namespace std;

class Unaryop final : public Expression {
	string type;
	Expression *arg;
public:

	// two parameter constructor with type of operator and pointer to expression
	//   to operate on (arg)
	Unaryop(const string &type, Expression *arg);

	// pretty prints Operation and calls prettyprint on arg
	void prettyprint(ostream &out) const override;

  // calls set of arg to "find" variable with name s
	void set(const string &s, const int x) override;

	// similar to set
	void unset(const string &s) override;

	// calls evaluate of arg and returns operation of "this" on that returned
	//   value
	int evaluate() const override;

	~Unaryop() override;
};

#endif

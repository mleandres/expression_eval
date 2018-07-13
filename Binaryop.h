#ifndef BINARYOP_H
#define BINARYOP_H
#include "Expression.h"

class Binaryop final : public Expression {
	string type;
	Expression *lhs;
	Expression *rhs;

public:
	// Constructor with 3 parameters: type of operation, lhs argument and rhs
	//   argument
	Binaryop(const string &type, Expression *lhs, Expression *rhs);

	// prints the (lhs <type> rhs) where lhs and rhs are Expressions, to the
	//   ostream out, where <type> is the type of operation.
	//   Also calls prettyprint of lhs and rhs.
	void prettyprint(ostream &out) const override;

	// Calls set of lhs and rhs to "find" the variable with the name s.
	void set(const string &s, const int x) override;

	// similar to set
	void unset(const string &s) override;

	// calls evaluate on lhs and rhs then returns value of lhs <type> rhs where
	//   <type> is the type of operation to be performed.
	int evaluate() const override;

	~Binaryop() override;
};

#endif

#ifndef INTEGER_H
#define INTEGER_H
#include <string>
#include "Expression.h"

class Integer final : public Expression {
	int val;

public:

	// Constructor with 1 parameter
	Integer(const int val);

	// pretty print method
	void prettyprint(ostream &out) const override;

	// evaluate method
	int evaluate() const override;


};

#endif

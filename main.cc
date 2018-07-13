#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Expression.h"
#include "Integer.h"
#include "Variable.h"
#include "Unaryop.h"
#include "Binaryop.h"

using namespace std;

int main () {
  string s;

  // vector to simulate stack of Expression pointers
  vector<Expression*> exprStack;

  // Expression pointer for use after done
  Expression *expr = nullptr;

  // Read and construct expression object
  while (cin >> s) {
    istringstream ss(s);
    int n;

    if (ss >> n) {
      // create new Integer Expression on top of stack
      exprStack.emplace_back(new Integer{n});
    }

    else if (s == "NEG" || s == "ABS") {
      // make new Unaryop object with the most recent Expression
      Expression *ep = exprStack.back();
      exprStack.pop_back();
      exprStack.emplace_back(new Unaryop{s, ep});
    }

    else if (s == "+" || s == "-" || s == "*" || s == "/") {
      // make new Binaryop object with the two most recent Expressions
      Expression *rhs = exprStack.back();
      exprStack.pop_back();

      Expression *lhs = exprStack.back();
      exprStack.pop_back();

      exprStack.emplace_back(new Binaryop{s, lhs, rhs});
    }

    else if (s == "done") {
      // set expr to be pointer to entire expression to use for the rest of main
      expr = exprStack.back();
      // also prints expression given ostream
      expr->prettyprint(cout);
      cout << endl;
      break;
    }

    // else create a variable object
    else {
      exprStack.emplace_back(new Variable{s});
    }
  }

  // set expr to be pointer to entire expression to use for the rest of main

  // Command interpreter
  while (cin >> s) {

    if (s == "eval") {
      // try to eval and catch if exception is thrown
      try {
        int ans = expr->evaluate();
        cout << ans << endl;
      }
      // ech
      catch(string e) {
        cout << e << " has no value." << endl;
      }
      //
      catch(int e) {
        cout << "Floating point exception" << endl;
        break;
      }

    }

    else if (s == "set") {
      int value;
      // s now has name of a variable
      cin >> s;
      // value now has value to set
      cin >> value;

      expr->set(s, value);
    }
    else if (s == "unset") {
      // s now has name of a variable
      cin >> s;
      expr->unset(s);
    }
    else if (s == "print") {
      expr->prettyprint(cout);
      cout << endl;
    }
  }
  for(auto n : exprStack) {
    delete n;
  }
}

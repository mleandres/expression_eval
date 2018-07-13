# Expression Evaluator

## Description

This program evaluates simple arithmetic expressions in prefix notation.

There are four tipes of expressions to evaluate:
- lone integers
- variables (which have a name that is letters only)
- unary operation (`NEG` is negation and `ABS` is absolute value) applied to an expression
- binary operation (+, -, *, or /) applied to two expressions

when finished enter `done`

An expression could look like `12 34 7 + * NEG done` which denotes: -(12 * (34 + 7))

### Variable commands:
- `set var num` sets the variable `var` to be the value `num`
- `unset var` reverts the variable `var` to being unassigned
- `eval` evaluates the expression
- `print` prints the expression nicely

### Example:

```
1 2 + 3 x - * ABS NEG done
-|((1 + 2) * (3 - x))|
eval
> x has no value.
set x 4
print
> -|((1 + 2) * (3 - 4))|
eval
-3
set x 3
print
> -|((1 + 2) * (3 - 3))|
eval
0
unset x
print
> -|((1 + 2) * (3 - x))|
eval
> x has no value.
```
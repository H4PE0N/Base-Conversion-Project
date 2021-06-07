
#include "../common-include-header.h"

int integer_variable_greater(int first, int second)
{
  int boolean = (first > second); return boolean;
}

int integer_variable_smaller(int first, int second)
{
  int boolean = (first < second); return boolean;
}

int integer_power_operation(int base, int exponent)
{
  int product = 1;
  for(int index = 0; index < exponent; index += 1)
  { product = (product * base); } return product;
}

int integer_variable_equals(int first, int second)
{
  int boolean = (first == second); return boolean;
}

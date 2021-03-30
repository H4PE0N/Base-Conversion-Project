
#include "common-include-header.h"

int hexdec_character_value(char character)
{
  char table[] = {'0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  return string_character_index(table, 16, character);
}

void change_hexdec_variables(char* hexdec, int amount,
  int index, int* integer)
{
  int number = (amount - index - 1);
  int value = integer_power_operation(16, number);

  int current = (*integer / value);
  char character = hexdec_index_character(current);

  hexdec = allocate_string_character(hexdec, index,
    character); *integer -= (current * value);
}

char hexdec_index_character(int index)
{
  char letters[] = {'0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  return string_index_character(letters, index);
}

int hexdec_values_amount(int integer)
{
  for(int amount = 0; true; amount = amount + 1)
  {
    int product = integer_power_operation(16, amount);
    if(!integer_variable_greater(integer, product))
      return amount;
  }
  return INT_NONE;
}

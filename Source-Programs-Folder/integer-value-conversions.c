
#include "common-include-header.h"

int convert_binary_integer(char* binary, int amount)
{
  int integer = 0;
  for(int index = 0; index < amount; index = index + 1)
  {
    char value = string_index_character(binary, index);
    if(character_variable_equals(value, '1'))
    {
      int number = (amount - index - 1);
      integer += integer_power_operation(2, number);
    }
  }
  return integer;
}

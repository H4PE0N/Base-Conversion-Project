
#include "common-include-header.h"

char convert_binary_character(char* binary, int amount)
{
  int integer = 0;
  for(int index = 0; index < amount; index = index + 1)
  {
    char letter = string_index_character(binary,index);
    if(character_variable_equals(letter, '1'))
    {
      int number = (amount - index - 1);
      integer += integer_power_operation(2, number);
    }
  }
  return convert_integer_character(integer);
}

char convert_integer_character(int integer)
{
  char character = integer; return character;
}

char convert_hexdec_character(char* hexdec, int amount)
{
  int integer = 0;
  for(int index = 0; index < amount; index = index + 1)
  {
    char letter = string_index_character(hexdec,index);
    int number = (amount - index - 1);
    int value = integer_power_operation(16, number);
    integer +=(value * hexdec_character_value(letter));
  }
  return convert_integer_character(integer);
}

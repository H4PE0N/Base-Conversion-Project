
#include "common-include-header.h"

int hexdec_character_value(char character)
{
  char table[] = {'0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  for(int index = 0; index < 16; index = index + 1)
  {
    char current = string_index_character(table,index);
    if(character_variable_equals(character, current))
      return index;
  }
  return INT_NONE;
}

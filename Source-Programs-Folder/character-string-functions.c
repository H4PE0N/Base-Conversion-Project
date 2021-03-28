
#include "common-include-header.h"

char* generate_character_string(int length)
{
  char* string = malloc(sizeof(char) * length);
  for(int index = 0; index < length; index = index + 1)
  {
    string = allocate_string_character(string, index,
      CHAR_NONE);
  }
  return string;
}

char* allocate_string_character(char* string,int index,
  char character)
{
  *(string + index) = character; return string;
}

char string_index_character(char* string, int index)
{
  char character = *(string + index); return character;
}

int character_string_length(char* string)
{
  for(int length = 0; true; length = length + 1)
  {
    char character = string_index_character(string,
      length);
    if(character_variable_equals(character, CHAR_NONE))
      return length;
  }
  return INT_NONE;
}

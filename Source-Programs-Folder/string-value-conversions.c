
#include "common-include-header.h"

char* convert_base64_string(char* base64, int length)
{
  char** bsebin = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(base64,
      index);
    if(!character_variable_equals(character, '='))
    {
      int integer = base64_character_value(character);
      char* binary = integer_base64_binary(integer);

      bsebin = allocate_sentence_string(bsebin, index,
        binary);
    }
  }
  int amount = character_sentence_amount(bsebin);
  char*stream=concat_character_sentence(bsebin,amount);
  int strlen = character_string_length(stream);

  int binlen = (strlen - (strlen % 8));
  char* newbin = character_string_section(stream, 0,
    binlen);

  char** strbin = divide_character_string(newbin, binlen, 8);

  char* string = convert_binary_string(strbin, binlen/8);
  return string;
}

char* convert_binary_string(char** binary, int amount)
{
  char* string = generate_character_string(amount);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* current = sentence_index_string(binary, index);
    int length = character_string_length(current);
    char character = convert_binary_character(current,
      length);
    string = allocate_string_character(string, index,
      character);
  }
  return string;
}

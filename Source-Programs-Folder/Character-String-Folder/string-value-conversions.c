
#include "../common-include-header.h"

char* convert_base64_string(char* base64, int length)
{
  char** binary = convert_base64_binary(base64, length);
  int amount = character_sentence_amount(binary);
  char* string = convert_binary_string(binary, amount);
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

char* convert_array_string(int* array, int length)
{
  char* string = generate_character_string(length);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = array_index_integer(array, index);
    string = allocate_string_character(string, index,
      character);
  }
  return string;
}

char* convert_hexdec_string(char** hexdec, int amount)
{
  char* string = generate_character_string(amount);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* current=sentence_index_string(hexdec, index);
    int length = character_string_length(current);
    char character = convert_hexdec_character(current,
      length);
    string = allocate_string_character(string, index,
      character);
  }
  return string;
}


#include "../common-include-header.h"

char* convert_integer_binary(int integer)
{
  char* binary = generate_character_string(STR_SIZE);
  int amount = binary_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    change_binary_variables(binary, amount, index,
      &integer);
  }
  return binary;
}

char* integer_limited_binary(int integer, int limit)
{
  char* binary = generate_character_string(STR_SIZE);
  for(int index = 0; index < limit; index = index + 1)
  {
    change_binary_variables(binary, limit, index,
      &integer);
  }
  return binary;
}

char*character_limited_binary(char character,int limit)
{
  char* binary = generate_character_string(STR_SIZE);
  int integer = (int) character;
  for(int index = 0; index < limit; index = index + 1)
  {
    change_binary_variables(binary, limit, index,
      &integer);
  }
  return binary;
}

char* convert_character_binary(char character)
{
  char* binary = generate_character_string(STR_SIZE);
  int integer = (int) character;
  int amount = binary_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    change_binary_variables(binary, amount, index,
      &integer);
  }
  return binary;
}

char** convert_string_binary(char* string, int length)
{
  char** binary = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(string,
      index);
    char*current=character_limited_binary(character,8);
    binary = allocate_sentence_string(binary, index,
      current);
  }
  return binary;
}

char** convert_array_binary(int* array, int length)
{
  char** binary = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < length; index = index + 1)
  {
    int integer = array_index_integer(array, index);
    char* current = integer_limited_binary(integer, 8);
    binary = allocate_sentence_string(binary, index,
      current);
  }
  return binary;
}
// CHANGE: SPLIT UP IN TWO FUNCTIONS
char** convert_hexdec_binary(char** hexdec, int amount)
{
  char** binary = generate_character_sentence(amount,
    STR_SIZE);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* currhex=sentence_index_string(hexdec, index);
    int length = character_string_length(currhex);
    int integer=convert_hexdec_integer(currhex,length);
    char* currbin = convert_integer_binary(integer);
    binary = allocate_sentence_string(binary, index,
      currbin);
  }
  return binary;
}
// CHANGE: SPLIT UP IN TWO FUNCTIONS
char** convert_base64_binary(char* base64, int length)
{
  char** binary = extract_base64_binary(base64, length);
  int amount = character_sentence_amount(binary);

  char*stream=concat_character_sentence(binary, amount,
    CHAR_NONE);
  int strlen = character_string_length(stream);

  int binlen = (strlen - (strlen % 8));
  char* newbin = character_string_section(stream, 0,
    binlen);
  char** strbin = divide_character_string(newbin,
    binlen, 8); return strbin;
}

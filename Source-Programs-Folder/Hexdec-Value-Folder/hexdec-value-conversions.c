
#include "../common-include-header.h"

char* convert_integer_hexdec(int integer)
{
  char* hexdec = generate_character_string(STR_SIZE);
  int amount = hexdec_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    change_hexdec_variables(hexdec, amount, index,
      &integer);
  }
  return hexdec;
}

char* convert_binary_hexdec(char* binary, int amount)
{
  char* hexdec = generate_character_string(STR_SIZE);
  int integer = convert_binary_integer(binary, amount);
  int hexamt = hexdec_values_amount(integer);
  for(int index = 0; index < hexamt; index = index + 1)
  {
    change_hexdec_variables(hexdec, hexamt, index,
      &integer);
  }
  return hexdec;
}

char* convert_character_hexdec(char character)
{
  char* hexdec = generate_character_string(STR_SIZE);
  int integer = (int) character;
  int amount = hexdec_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    change_hexdec_variables(hexdec, amount, index,
      &integer);
  }
  return hexdec;
}

char** convert_base64_hexdec(char* base64, int length)
{
  int* array = convert_base64_array(base64,length);
  int amount = integer_array_length(array);
  char** hexdec = convert_array_hexdec(array, amount);
  return hexdec;
}

char** convert_array_hexdec(int* array, int length)
{
  char** hexdec = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < length; index = index + 1)
  {
    int integer = array_index_integer(array, index);
    char* current = convert_integer_hexdec(integer);
    hexdec = allocate_sentence_string(hexdec, index,
      current);
  }
  return hexdec;
}

char** convert_string_hexdec(char* string, int length)
{
  char** hexdec = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(string,
      index);
    char* current =convert_character_hexdec(character);
    hexdec = allocate_sentence_string(hexdec, index,
      current);
  }
  return hexdec;
}

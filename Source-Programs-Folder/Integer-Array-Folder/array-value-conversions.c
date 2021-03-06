
#include "../common-include-header.h"

int* convert_binary_array(char** binary, int amount)
{
  int* array = generate_integer_array(amount);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* current=sentence_index_string(binary, index);
    int length = character_string_length(current);
    int integer=convert_binary_integer(current,length);
    array=allocate_array_integer(array, index,integer);
  }
  return array;
}

int* convert_string_array(char* string, int length)
{
  int* array = generate_integer_array(length);
  for(int index = 0; index < length; index = index + 1)
  {
    int integer = string_index_character(string, index);
    array = allocate_array_integer(array, index, integer);
  }
  return array;
}

int* convert_hexdec_array(char** hexdec, int amount)
{
  int* array = generate_integer_array(amount);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* current=sentence_index_string(hexdec, index);
    int length = character_string_length(current);
    int integer=convert_hexdec_integer(current,length);
    array=allocate_array_integer(array,index, integer);
  }
  return array;
}

int* convert_base64_array(char* base64, int length)
{
  char** binary = convert_base64_binary(base64,length);
  int amount = character_sentence_amount(binary);
  int* array = convert_binary_array(binary, amount);
  return array;
}

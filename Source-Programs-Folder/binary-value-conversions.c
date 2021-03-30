
#include "common-include-header.h"

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

char* integer_limited_binary(int integer)
{
  char* binary = generate_character_string(STR_SIZE);
  for(int index = 0; index < 8; index = index + 1)
  {
    change_binary_variables(binary, 8, index,&integer);
  }
  return binary;
}

char* character_limited_binary(char character)
{
  char* binary = generate_character_string(STR_SIZE);
  int integer = convert_character_integer(character);
  for(int index = 0; index < 8; index = index + 1)
  {
    change_binary_variables(binary, 8, index,&integer);
  }
  return binary;
}
// CHANGE THIS FUNCTION TO A COMMON WITH ARGUMENT
char* integer_base64_binary(int integer)
{
  char* binary = generate_character_string(STR_SIZE);
  for(int index = 0; index < 6; index = index + 1)
  {
    change_binary_variables(binary, 6, index,&integer);
  }
  return binary;
}

char* convert_hexdec_binary(char* hexdec, int amount)
{
  char* binary = generate_character_string(STR_SIZE);
  int integer = convert_hexdec_integer(hexdec, amount);
  int binamt = binary_values_amount(integer);
  for(int index = 0; index < binamt; index = index + 1)
  {
    change_binary_variables(binary, binamt, index,
      &integer);
  }
  return binary;
}

char** convert_base64_binary(char* base64, int length)
{
  char** binary = generate_character_sentence(length,
    STR_SIZE);
  return binary;
}

char* convert_character_binary(char character)
{
  char* binary = generate_character_string(STR_SIZE);
  int integer = convert_character_integer(character);
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
    char* current =character_limited_binary(character);
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
    char* current = integer_limited_binary(integer);
    binary = allocate_sentence_string(binary, index,
      current);
  }
  return binary;
}

/*===================================================*/

void change_binary_variables(char* binary, int amount,
  int index, int* integer)
{
  int number = (amount - index - 1);
  if(*integer >= integer_power_operation(2, number))
  {
    binary=allocate_string_character(binary,index,'1');
    *integer -= integer_power_operation(2, number);
  } else {
    binary=allocate_string_character(binary,index,'0');
  }
}

int binary_values_amount(int integer)
{
  for(int amount = 0; true; amount = amount + 1)
  {
    int product = integer_power_operation(2, amount);
    if(!integer_variable_greater(integer, product))
      return amount;
  }
  return INT_NONE;
}

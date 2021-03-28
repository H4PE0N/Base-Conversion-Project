
#include "common-include-header.h"

char* convert_integer_binary(int integer)
{
  char* binary = generate_character_string(STR_SIZE);
  int amount = binary_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    int number = (amount - index - 1);
    if(integer >= integer_power_operation(2, number))
    {
      binary = allocate_string_character(binary, index, '1');
      integer -= integer_power_operation(2, number);
    }
    else
    {
      binary = allocate_string_character(binary, index, '0');
    }
  }
  return binary;
}

char* convert_hexdec_binary(char* hexdec, int amount)
{
  char* binary = generate_character_string(STR_SIZE);
  return binary;
}

char* convert_base64_binary(char* base64, int length)
{
  char* binary = generate_character_string(STR_SIZE);
  return binary;
}

char* convert_character_binary(char character)
{
  char* binary = generate_character_string(STR_SIZE);
  return binary;
}

char* convert_string_binary(char* string, int length)
{
  char* binary = generate_character_string(STR_SIZE);
  return binary;
}

char* convert_array_binary(int* array, int length)
{
  char* binary = generate_character_string(STR_SIZE);
  return binary;
}

/*===================================================*/

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


#include "common-include-header.h"

char* convert_integer_hexdec(int integer)
{
  char* hexdec = generate_character_string(STR_SIZE);
  int amount = hexdec_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    int number = (amount - index - 1);
    int value = integer_power_operation(16, number);

    int current = (integer / value);
    char character = hexdec_index_character(current);

    hexdec = allocate_string_character(hexdec, index, character);
    integer -= (current * value);
  }
  return hexdec;
}

char* convert_binary_hexdec(char* binary, int amount)
{
  char* hexdec = generate_character_string(STR_SIZE);
  return hexdec;
}

char* convert_character_hexdec(char character)
{
  char* hexdec = generate_character_string(STR_SIZE);
  return hexdec;
}

char* convert_base64_hexdec(char* base64, int length)
{
  char* hexdec = generate_character_string(STR_SIZE);
  return hexdec;
}

char* convert_array_hexdec(int* array, int length)
{
  char* hexdec = generate_character_string(STR_SIZE);
  return hexdec;
}

char* convert_string_hexdec(char* string, int length)
{
  char* hexdec = generate_character_string(STR_SIZE);
  return hexdec;
}

/*---------------------------------------------------*/

char hexdec_index_character(int index)
{
  char table[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  char character = *(table + index); return character;
}

int hexdec_values_amount(int integer)
{
  for(int amount = 0; true; amount = amount + 1)
  {
    int product = integer_power_operation(16, amount);
    if(!integer_variable_greater(integer, product))
      return amount;
  }
  return INT_NONE;
}

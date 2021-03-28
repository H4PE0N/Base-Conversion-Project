
#include "common-include-header.h"

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
  int integer = convert_character_integer(character);
  int amount = hexdec_values_amount(integer);
  for(int index = 0; index < amount; index = index + 1)
  {
    change_hexdec_variables(hexdec, amount, index,
      &integer);
  }
  return hexdec;
}

char* convert_base64_hexdec(char* base64, int length)
{
  char* hexdec = generate_character_string(STR_SIZE);
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

/*---------------------------------------------------*/

void change_hexdec_variables(char* hexdec, int amount,
  int index, int* integer)
{
  int number = (amount - index - 1);
  int value = integer_power_operation(16, number);

  int current = (*integer / value);
  char character = hexdec_index_character(current);

  hexdec = allocate_string_character(hexdec, index,
    character); *integer -= (current * value);
}

char hexdec_index_character(int index)
{
  char table[] = {'0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
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

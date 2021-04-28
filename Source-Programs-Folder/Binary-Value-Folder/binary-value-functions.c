
#include "../common-include-header.h"

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
// DEN HÄR SKA ÄNDRAS OCH BLI KORTARE
char** extract_base64_binary(char* base64, int length)
{
  char** binary = generate_character_sentence(length,
    STR_SIZE);

  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(base64,
      index);
    if(character_variable_equals(character, '='))
      continue;

    int integer = base64_character_value(character);
    char* current=integer_limited_binary(integer, 6);

    binary = allocate_sentence_string(binary, index,
      current);
  }
  return binary;
}

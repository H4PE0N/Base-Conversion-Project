
#include "common-include-header.h"

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

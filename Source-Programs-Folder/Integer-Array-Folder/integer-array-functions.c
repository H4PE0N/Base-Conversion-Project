
#include "../common-include-header.h"

int* generate_integer_array(int length)
{
  int* array = malloc(sizeof(int) * (length + 1));
  for(int index = 0; index < (length + 1); index += 1)
  {
    array = allocate_array_integer(array, index,
      INT_NONE);
  }
  return array;
}

int* allocate_array_integer(int* array, int index,
  int integer)
{
  *(array + index) = integer; return array;
}

int array_index_integer(int* array, int index)
{
  int integer = *(array + index); return integer;
}

int integer_array_length(int* array)
{
  for(int length = 0; true; length = length + 1)
  {
    int integer = array_index_integer(array, length);
    if(integer_variable_equals(integer, INT_NONE))
      return length;
  }
  return INT_NONE;
}

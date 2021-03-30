
#include "common-include-header.h"

char* convert_integer_base64(int integer)
{
  char* base64 = generate_character_string(STR_SIZE);
  return base64;
}

char* convert_hexdec_base64(char* hexdec, int length)
{
  char* base64 = generate_character_string(STR_SIZE);
  return base64;
}

char* convert_binary_base64(char* binary, int length)
{
  char* base64 = generate_character_string(STR_SIZE);
  return base64;
}

char* convert_array_base64(int* array, int length)
{
  char* base64 = generate_character_string(STR_SIZE);
  return base64;
}

char* convert_character_base64(char character)
{
  char* base64 = generate_character_string(STR_SIZE);
  return base64;
}

char* convert_string_base64(char* string, int length)
{
  char** strbin = convert_string_binary(string,length);
  char** bsebin=generate_base64_binary(strbin, length);

  int amount = character_sentence_amount(bsebin);
  int* array = convert_binary_array(bsebin, amount);

  char* base64 = generate_character_string(STR_SIZE);
  for(int index = 0; index < amount; index = index + 1)
  {
    int integer = array_index_integer(array, index);
    char character = base64_index_character(integer);
    base64 = allocate_string_character(base64, index,
      character);
  }

  int modint = (amount % 4);
  int blanks = (modint == 0 ? 0 : (4 - modint));
  for(int index = 0; index < blanks; index = index + 1)
  {
    base64 = allocate_string_character(base64, amount +
      index, '=');
  }
  return base64;
}

/*
hello
h        e        l        l        o
00010100 01010001 01000101 00010100 01010001
0001010001010001010001010001010001010001: 40
42 % 8 = 2
000101000101000101000101000101000101000100: 42
000101 000101 000101 000101 000101 000101 000100 ******
a      G      V      s      b      G      8      =
aGVsbG8=
*/

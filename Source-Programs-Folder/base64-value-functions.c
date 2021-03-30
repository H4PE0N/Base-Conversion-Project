
#include "common-include-header.h"

char** generate_base64_binary(char** binary,int amount)
{
  char* concat = generate_character_string(STR_SIZE);
  concat = concat_character_sentence(binary, amount);
  int conlen = character_string_length(concat);

  char** bsebin = divide_character_string(concat,
    conlen, 6);

  int bseamt = character_sentence_amount(bsebin);

  char* string=sentence_index_string(bsebin, bseamt-1);
  int length = character_string_length(string);

  string = append_string_characters(string, length,'0',
    6 - length); return bsebin;
}

int base64_character_value(char character)
{
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q','R',
  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b','c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y',
  'z', '0', '1', '2', '3', '4', '5', '6', '7', '8','9',
    '+', '/'};
  return string_character_index(letters, 64,character);
}

char base64_index_character(int index)
{
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
  'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q','R',
  'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b','c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n',
  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x','y',
  'z', '0', '1', '2', '3', '4', '5', '6', '7', '8','9',
    '+', '/'};
  return string_index_character(letters, index);
}

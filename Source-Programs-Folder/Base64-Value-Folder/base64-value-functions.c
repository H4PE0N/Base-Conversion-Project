
#include "../common-include-header.h"

char b64File[] = "../Source-Programs-Folder/Base64-\
Value-Folder/base64-values-table.txt";

char* values_base64_string(int* array, int length)
{
  char* base64 = generate_character_string(STR_SIZE);

  for(int index = 0; index < length; index = index + 1)
  {
    int integer = array_index_integer(array, index);
    char character = base64_index_character(integer);
    base64 = allocate_string_character(base64, index,
      character);
  }
  return base64;
}
// THIS FUNCTION LOOKS BAD
char** generate_base64_binary(char** binary,int amount)
{
  char* concat = generate_character_string(STR_SIZE);
  concat = concat_character_sentence(binary, amount,
    CHAR_NONE);
  int conlen = character_string_length(concat);

  char** bsebin = divide_character_string(concat,
    conlen, 6);
  int bseamt = character_sentence_amount(bsebin);

  char* string=sentence_index_string(bsebin, bseamt-1);
  int length = character_string_length(string);
  string = append_string_characters(string, length,'0',
    6 - length); return bsebin;
}
// THIS FUNCTION LOOKS BAD
char* append_base64_ending(char* base64, int length)
{
  int modint = (length % 4);
  int blanks = (modint == 0 ? 0 : (4 - modint));
  base64 = append_string_characters(base64, length,'=',
    blanks);
  return base64;
}

int base64_character_value(char character)
{
  char* letters = extract_file_information(b64File);
  int length = character_string_length(letters);
  int index = string_character_index(letters, length,
    character); return index;
}

char base64_index_character(int index)
{
  char* letters = extract_file_information(b64File);
  return string_index_character(letters, index);
}


#include "../common-include-header.h"

char* generate_character_string(int length)
{
  char* string = malloc(sizeof(char) * (length + 1));
  for(int index = 0; index < (length + 1); index += 1)
  {
    string = allocate_string_character(string, index,
      CHAR_NONE);
  }
  return string;
}

int character_string_length(char* string)
{
  for(int length = 0; true; length = length + 1)
  {
    char character = string_index_character(string,
      length);
    if(character_variable_equals(character, CHAR_NONE))
      return length;
  }
  return INT_NONE;
}

char**generate_character_sentence(int height,int width)
{
  char** sentence = malloc(sizeof(char*) * (height+1));
  for(int index = 0; index < (height + 1); index += 1)
  {
    char* string = generate_character_string(width);
    sentence = allocate_sentence_string(sentence,index,
      string);
  }
  return sentence;
}

char* sentence_index_string(char** sentence,int index)
{
  char* string = *(sentence + index); return string;
}

char* append_string_characters(char* string,int length,
  char character, int amount)
{
  for(int index = 0; index < amount; index = index + 1)
  {
    string = allocate_string_character(string, index +
      length, character);
  }
  return string;
}

char* character_string_section(char* string, int first,
  int second)
{
  int length = (second - first + 1);
  char* section = generate_character_string(length);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(string,
      first + index);
    section = allocate_string_character(section, index,
      character);
  }
  return section;
}
// THIS FUNCTION LOOKS BAD
char* concat_character_sentence(char** sentence,
  int amount, char seperator)
{
  char* concat = generate_character_string(STR_SIZE);
  char* first = sentence_index_string(sentence, 0);
  int first_len = character_string_length(first);
  concat = copy_character_string(first, first_len,
    concat);
  for(int index = 1; index < amount; index = index + 1)
  {
    char* current = sentence_index_string(sentence,
      index);
    int length = character_string_length(concat);
    concat = concat_character_strings(concat, length,
      current, seperator);
  }
  return concat;
}
// THIS FUNCTION LOOKS BAD
char* concat_character_strings(char* first, int start,
  char* second, char seperator)
{
  int length = character_string_length(second);
  if(!character_variable_equals(seperator, CHAR_NONE))
  {
    first = allocate_string_character(first, start,
      seperator); start = (start + 1);
  }
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(second,
      index);
    first=allocate_string_character(first, start+index,
      character);
  }
  return first;
}

int character_sentence_amount(char** sentence)
{
  for(int amount = 0; true; amount = amount + 1)
  {
    char*string=sentence_index_string(sentence,amount);
    if(!character_string_length(string)) return amount;
  }
  return INT_NONE;
}

int string_character_index(char* string, int length,
  char character)
{
  for(int index = 0; index < length; index = index + 1)
  {
    char current=string_index_character(string, index);
    if(character_variable_equals(character, current))
      return index;
  }
  return INT_NONE;
}

char** allocate_sentence_string(char** sentence,
  int index, char* string)
{
  *(sentence + index) = string; return sentence;
}

char** divide_character_string(char* string,int length,
  int piece)
{
  char** sentence = generate_character_sentence(length,
    STR_SIZE); int total = (length + (length % piece));
  for(int index = 0; index < total; index += piece)
  {
    char*section=character_string_section(string,index,
      index + piece - 1);
    int amount = character_sentence_amount(sentence);
    sentence=allocate_sentence_string(sentence, amount,
      section);
  }
  return sentence;
}

char* copy_character_string(char* copying, int length,
  char* string)
{
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(copying,
      index);
    string = allocate_string_character(string, index,
      character);
  }
  return string;
}

char string_index_character(char* string, int index)
{
  char character = *(string + index); return character;
}
// THIS FUNCTION LOOKS BAD
char* extract_file_information(char* filename)
{
  char* string = generate_character_string(STR_SIZE);
  FILE* filedata = fopen(filename, "r");
  if(filedata == NULL) { return NULL; } char character;
  for(int index = 0; (character=fgetc(filedata)) !=EOF;
    index = index + 1)
  {
    string =allocate_string_character(string, index,
      character);
  }
  int length = character_string_length(string);
  string = delete_string_character(string, length,
    length - 1); return string;
}

char* allocate_string_character(char* string,int index,
  char character)
{
  *(string + index) = character; return string;
}
// THIS FUNCTION LOOKS BAD
char* delete_string_character(char* string, int length,
  int start) // start: index
{
  for(int index = start; index < length; index += 1)
  {
    char token = string_index_character(string, index);
    char second=string_index_character(string,index+1);
    string = allocate_string_character(string, index,
      second);
    string = allocate_string_character(string, index+1,
      token);
  }
  string = allocate_string_character(string, length,
    CHAR_NONE); return string;
}

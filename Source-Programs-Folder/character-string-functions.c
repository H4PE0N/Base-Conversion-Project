
#include "common-include-header.h"

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

char* allocate_string_character(char* string,int index,
  char character)
{
  *(string + index) = character; return string;
}

char string_index_character(char* string, int index)
{
  char character = *(string + index); return character;
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

char** allocate_sentence_string(char** sentence,
  int index, char* string)
{
  *(sentence + index) = string; return sentence;
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
  char* section = generate_character_string(STR_SIZE); // length
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(string,
      first + index);
    section = allocate_string_character(section, index,
      character);
  }
  return section;
}

char* concat_character_sentence(char** sentence,
  int amount)
{
  char* concat = generate_character_string(STR_SIZE);
  for(int index = 0; index < amount; index = index + 1)
  {
    char* current = sentence_index_string(sentence,
      index);
    int c_length = character_string_length(current);
    int t_length = character_string_length(concat);
    concat = concat_character_strings(concat, t_length,
      current, c_length);
  }
  return concat;
}

char* concat_character_strings(char* first, int start,
  char* second, int length)
{
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(second,
      index);
    first = allocate_string_character(first, start +
      index, character);
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

char** divide_character_string(char* string,int length,
  int piece)
{
  char** sentence = generate_character_sentence(length,
    STR_SIZE);
  for(int index = 0; index < (length + 4); index += piece)
  {
    char*section=character_string_section(string,index,
      index + piece - 1);
    int amount = character_sentence_amount(sentence);
    sentence=allocate_sentence_string(sentence, amount,
      section);
  }
  return sentence;
}

char* copy_character_string(char* copying, int length)
{
  char* string = generate_character_string(length);
  for(int index = 0; index < length; index = index + 1)
  {
    char character = string_index_character(copying,
      index);
    string = allocate_string_character(string, index,
      character);
  }
  return string;
}

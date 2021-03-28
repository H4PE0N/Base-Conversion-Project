
#ifndef CHARACTER_STRING_FUNCTIONS_H
#define CHARACTER_STRING_FUNCTIONS_H

char* generate_character_string(int);
char**generate_character_sentence(int, int);

char* allocate_string_character(char*, int, char);
char string_index_character(char*, int);

int character_string_length(char*);

char* sentence_index_string(char**, int);
char** allocate_sentence_string(char**, int, char*);

#endif

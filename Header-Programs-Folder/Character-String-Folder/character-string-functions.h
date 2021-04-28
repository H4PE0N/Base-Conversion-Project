
#ifndef CHARACTER_STRING_FUNCTIONS_H
#define CHARACTER_STRING_FUNCTIONS_H

char* generate_character_string(int);
char**generate_character_sentence(int, int);

char* allocate_string_character(char*, int, char);
char string_index_character(char*, int);

int character_string_length(char*);

char* sentence_index_string(char**, int);
char** allocate_sentence_string(char**, int, char*);

char* concat_character_strings(char*, int, char*, char);

char* concat_character_sentence(char**, int, char);

char* character_string_section(char*, int, int);

int character_sentence_amount(char**);

int string_character_index(char*, int, char);

char* append_string_characters(char*, int, char, int);

char** divide_character_string(char*, int, int);

char* copy_character_string(char*, int, char*);

char* delete_string_character(char*, int, int);

char* extract_file_information(char*);

#endif

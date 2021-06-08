
#ifndef BASE64_VALUE_FUNCTIONS
#define BASE64_VALUE_FUNCTIONS

extern char b64File[];

char* values_base64_string(int*, int);
char** generate_base64_binary(char**, int);

int base64_character_value(char);
char base64_index_character(int);

char* append_base64_ending(char*, int);

#endif

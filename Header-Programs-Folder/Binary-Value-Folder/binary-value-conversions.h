
#ifndef BINARY_VALUE_CONVERSIONS_H
#define BINARY_VALUE_CONVERSIONS_H

char* convert_integer_binary(int);
char** convert_hexdec_binary(char**, int);
char** convert_base64_binary(char*, int);
char* convert_character_binary(char);
char** convert_string_binary(char*, int);
char** convert_array_binary(int*, int);
char* integer_limited_binary(int, int);
char* character_limited_binary(char, int);
char* integer_base64_binary(int);

#endif

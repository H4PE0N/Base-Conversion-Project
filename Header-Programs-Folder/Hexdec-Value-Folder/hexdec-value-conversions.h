
#ifndef HEXDEC_VALUE_CONVERSIONS
#define HEXDEC_VALUE_CONVERSIONS

char* convert_integer_hexdec(int);
char* convert_binary_hexdec(char*, int);
char* convert_character_hexdec(char);
char** convert_base64_hexdec(char*, int);
char** convert_array_hexdec(int*, int);
char** convert_string_hexdec(char*, int);

#endif

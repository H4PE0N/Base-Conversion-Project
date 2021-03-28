
#ifndef BASE64_VALUE_CONVERSIONS_H
#define BASE64_VALUE_CONVERSIONS_H

char* convert_integer_base64(int);
char* convert_hexdec_base64(char*, int);
char* convert_binary_base64(char*, int);
char* convert_array_base64(int*, int);
char* convert_character_base64(char);
char* convert_string_base64(char*, int);

#endif

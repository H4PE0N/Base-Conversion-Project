
#ifndef HEXDEC_VALUE_CONVERSIONS_H
#define HEXDEC_VALUE_CONVERSIONS_H

char* convert_integer_hexdec(int);
char* convert_binary_hexdec(char*, int);
char* convert_character_hexdec(char);
char* convert_base64_hexdec(char*, int);
char* convert_array_hexdec(int*, int);
char* convert_string_hexdec(char*, int);

char hexdec_index_character(int);
int hexdec_values_amount(int);

#endif

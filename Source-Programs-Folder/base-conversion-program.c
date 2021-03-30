
#include "common-include-header.h"

int main(int amount, char* arguments[])
{
	// int integer = 567;
	//
	// char* binary = convert_integer_binary(integer);
	// int length = character_string_length(binary);
	//
	// char* hexdec = convert_binary_hexdec(binary, length);
	// char* base64 = convert_integer_base64(integer);
	// char character = convert_integer_character(integer);

	char* string = arguments[1];
	int length = character_string_length(string);

	char* base64 = convert_string_base64(string, length);
	int bselen = character_string_length(base64);

	char* newstr = convert_base64_string(base64, bselen);

	// printf("INTEGER\t: %d\n", integer);
	// printf("BINARY\t: %s\n", binary);
	// printf("HEXDEC\t: %s\n", hexdec);
	printf("STRING\t: %s\n", string);
	printf("BASE64\t: %s\n", base64);
	printf("NEWSTR\t: %s\n", newstr);
	// printf("LETTER\t: %c\n", character);

  return false;
}

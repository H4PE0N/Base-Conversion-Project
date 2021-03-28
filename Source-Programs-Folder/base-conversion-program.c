
#include "common-include-header.h"

int main(int amount, char* arguments[])
{
	int integer = 567;

	char* binary = convert_integer_binary(integer);
	int length = character_string_length(binary);

	char* hexdec = convert_binary_hexdec(binary, length);
	char* base64 = convert_integer_base64(integer);
	char character = convert_integer_character(integer);

	printf("INTEGER\t: %d\n", integer);
	printf("BINARY\t: %s\n", binary);
	printf("HEXDEC\t: %s\n", hexdec);
	printf("BASE64\t: %s\n", base64);
	printf("LETTER\t: %c\n", character);

  return false;
}

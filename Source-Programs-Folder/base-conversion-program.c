
#include "common-include-header.h"

int main(int amount, char* arguments[])
{
	char* string = sentence_index_string(arguments, 1);
	int strlen = character_string_length(string);

	char* base64 = convert_string_base64(string, strlen);
	int bselen = character_string_length(base64);

	printf("\nSTRING:\n%s\n", string);

	printf("\nBASE64:\n%s\n", base64);

	printf("\nSTRING:\n%s\n", convert_base64_string(base64, bselen));
  return false;
}

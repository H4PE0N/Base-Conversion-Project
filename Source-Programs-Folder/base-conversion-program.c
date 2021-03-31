
#include "common-include-header.h"

int main(int amount, char* arguments[])
{
	char string[STR_SIZE];
	printf("INPUT STRING: "); scanf("%[^\n]%*c", string);
	int length = character_string_length(string);

	char* base64 = convert_string_base64(string, length);

	printf("\nBASE64:\n");
	printf("%s\n", base64);

  return false;
}

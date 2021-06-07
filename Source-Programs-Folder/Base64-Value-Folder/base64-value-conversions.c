
#include "../common-include-header.h"

char* convert_hexdec_base64(char** hexdec, int amount)
{
  char** binary = convert_hexdec_binary(hexdec, amount);
  char* base64 = convert_binary_base64(binary, amount);
  return base64;
}

char* convert_binary_base64(char** binary, int length)
{
  char** bsebin=generate_base64_binary(binary, length);
  int amount = character_sentence_amount(bsebin);

  int* array = convert_binary_array(bsebin, amount);
  char* base64 = values_base64_string(array, amount);

  base64 = append_base64_ending(base64, amount);
  return base64;
}

char* convert_array_base64(int* array, int length)
{
  char** binary = convert_array_binary(array, length);
  char* base64 = convert_binary_base64(binary, length);
  return base64;
}

char* convert_string_base64(char* string, int length)
{
  char** binary = convert_string_binary(string,length);
  char* base64 = convert_binary_base64(binary, length);
  return base64;
}

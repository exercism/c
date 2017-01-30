int len(char *str)
{
   int count = 0;
   while (*str) {
      str++, count++;
   }
   return count;
}

int convert(char input[64])
{
   int lens = len(input);
   int result = 0;
   for (int i = 0; i < lens; i++) {
      result <<= 1;
      if (input[i] == '1') {
         result |= 1;
      } else if (input[i] != '0') {
         return 0;
      }
   }
   return result;
}

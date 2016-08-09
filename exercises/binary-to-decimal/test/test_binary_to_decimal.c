#include "vendor/unity.h"
#include "../src/binary_to_decimal.h"

void Convert_Binary_small(){
    printf("Just Printing decimal in integer %d and %s in string \n", Convert_to_Decimal(100) , Decimal); /* converts and sets the int dec into a string in the global char Decimal */
     Decimal[0] = '\0';
}

void Convert_Binary_Medium_oneByte(){
     printf("Just Printing decimal in integer %d and %s in string \n", Convert_to_Decimal(11110011) , Decimal);
     Decimal[0] = '\0';
}

void Convert_Binary_Medium_twoBytes(){
     printf("Just Printing decimal in integer %d and %s in string \n", Convert_to_Decimal(1111001101110011) , Decimal);
     Decimal[0] = '\0';
}

int main(void)
{
  
  UnityBegin("test/test_binary_to_decimal.c");

  RUN_TEST(Convert_Binary_small);
  RUN_TEST(Convert_Binary_Medium_oneByte);
  RUN_TEST(Convert_Binary_Medium_twoBytes);
  
  UnityEnd();
  return 0;
}

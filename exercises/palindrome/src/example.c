#include "palindrome.h"
#include "stdio.h"
#include "assert.h"
#include "string.h"
#include "stdlib.h"

int isPalindrome(int a, int b){

   char number[9];
   int i,length;

   /* negative numbers not allowed */
   if(a*b<0)
      return 1;


   sprintf(number,"%d",a*b);
   length = strlen(number);

   for(i = 0; i< length/2; i++){

      if(number[i] != number[length-i-1]){
         return 1;
      }
   }
   return 0;
}

Paire* palindromeFactors(int min, int max){
   
   Paire* tableP;
   assert((tableP = malloc(sizeof(Paire)))!=NULL);
   Paire stock;
   int i,j,tablePcount = 0;
   for( i = min; i <= max; i++){
      for( j = min; j <= max; j++){
         if(isPalindrome(i,j)==0){
           stock.a = i;
           stock.b = j;
           tableP[tablePcount] = stock;
           tablePcount++;
           assert(realloc(tableP,sizeof(Paire))!=NULL);
         }
      }
   }
   return tableP;
}

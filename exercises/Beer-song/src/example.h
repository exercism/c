#include <stdio.h>

void Sing_Beer_Song(int bottles){
	int bottlec;
	for(bottlec = bottles;bottles != 0;bottles--){
	   if(bottles == 1){
	       break;
	   }else{
	   printf("%d bottles of beer on the wall, %d bottles of beer.\nTake one down and pass it around, %d bottles of beer on the wall.\n\n",bottles,bottles,bottles-1);
	   }
         }
	printf("1 bottle of beer on the wall, 1 bottle of beer.\n");
    printf("Take one down and pass it around, no more bottles of beer on the wall.\n\n");
    printf("No more bottles of beer on the wall, no more bottles of beer.\n");
    printf("Go to the store and buy some more, %d bottles of beer on the wall.\n",bottlec);
}

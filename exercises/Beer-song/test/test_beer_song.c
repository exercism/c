#include "vendor/unity.h"
#include "../src/example.h"

void Write_99_Bottles_of_Beer(){
    Sing_Beer_Song(99);
}

void Write_999_Bottles_of_Beer(){
    Sing_Beer_Song(999);
}

void Write_9999_Bottles_of_Beer(){
    Sing_Beer_Song(9999);
}

int main(void)
{
  
  UnityBegin("test/test_beer_song.c");

  RUN_TEST(Write_99_Bottles_of_Beer);
  RUN_TEST(Write_999_Bottles_of_Beer);
  RUN_TEST(Write_9999_Bottles_of_Beer);

  UnityEnd();
  return 0;
}

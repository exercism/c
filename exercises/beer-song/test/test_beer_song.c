#include "vendor/unity.h"
#include "../src/beer_song.h"

#define BUFFER_SIZE   (1024)

void setUp(void)
{
}

void tearDown(void)
{
}

void test_handles_arbitrary_verse(void)
{
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "84 bottles of beer on the wall, 84 bottles of beer.\n"
       "Take one down and pass it around, 83 bottles of beer on the wall.\n";

   verse(response, 84);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

void test_handles_2_bottles(void)
{
   TEST_IGNORE();               // delete this line to run test
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "2 bottles of beer on the wall, 2 bottles of beer.\n"
       "Take one down and pass it around, 1 bottle of beer on the wall.\n";

   verse(response, 2);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

void test_handles_1_bottle(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "1 bottle of beer on the wall, 1 bottle of beer.\n"
       "Take it down and pass it around, no more bottles of beer on the wall.\n";

   verse(response, 1);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

void test_handles_0_bottles(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

   verse(response, 0);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

void test_sings_several_verses(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "8 bottles of beer on the wall, 8 bottles of beer.\n"
       "Take one down and pass it around, 7 bottles of beer on the wall.\n"
       "\n"
       "7 bottles of beer on the wall, 7 bottles of beer.\n"
       "Take one down and pass it around, 6 bottles of beer on the wall.\n"
       "\n"
       "6 bottles of beer on the wall, 6 bottles of beer.\n"
       "Take one down and pass it around, 5 bottles of beer on the wall.\n";

   sing(response, 8, 6);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

void test_sings_the_last_4_verses(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "3 bottles of beer on the wall, 3 bottles of beer.\n"
       "Take one down and pass it around, 2 bottles of beer on the wall.\n"
       "\n"
       "2 bottles of beer on the wall, 2 bottles of beer.\n"
       "Take one down and pass it around, 1 bottle of beer on the wall.\n"
       "\n"
       "1 bottle of beer on the wall, 1 bottle of beer.\n"
       "Take it down and pass it around, no more bottles of beer on the wall.\n"
       "\n"
       "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

   sing(response, 3, 0);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

int main(void)
{
   UnityBegin("test/test_beer_song.c");

   RUN_TEST(test_handles_arbitrary_verse);
   RUN_TEST(test_handles_2_bottles);
   RUN_TEST(test_handles_1_bottle);
   RUN_TEST(test_handles_0_bottles);
   RUN_TEST(test_sings_several_verses);
   RUN_TEST(test_sings_the_last_4_verses);

   UnityEnd();
   return 0;
}

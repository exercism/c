#include "test-framework/unity.h"
#include "beer_song.h"

#define BUFFER_SIZE   (1024)

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_first_generic_verse(void)
{
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "99 bottles of beer on the wall, 99 bottles of beer.\n"
       "Take one down and pass it around, 98 bottles of beer on the wall.\n";

   recite(99, 1, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_last_generic_verse(void)
{
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "3 bottles of beer on the wall, 3 bottles of beer.\n"
       "Take one down and pass it around, 2 bottles of beer on the wall.\n";

   recite(3, 1, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_verse_with_2_bottles(void)
{
   TEST_IGNORE();               // delete this line to run test
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "2 bottles of beer on the wall, 2 bottles of beer.\n"
       "Take one down and pass it around, 1 bottle of beer on the wall.\n";

   recite(2, 1, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_verse_with_1_bottle(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "1 bottle of beer on the wall, 1 bottle of beer.\n"
       "Take it down and pass it around, no more bottles of beer on the wall.\n";

   recite(1, 1, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_verse_with_0_bottles(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

   recite(0, 1, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_first_two_verses(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "99 bottles of beer on the wall, 99 bottles of beer.\n"
       "Take one down and pass it around, 98 bottles of beer on the wall.\n"
       "\n"
       "98 bottles of beer on the wall, 98 bottles of beer.\n"
       "Take one down and pass it around, 97 bottles of beer on the wall.\n";

   recite(99, 2, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

static void test_last_three_verses(void)
{
   TEST_IGNORE();
   char response[BUFFER_SIZE];
   const char expected[BUFFER_SIZE] =
       "2 bottles of beer on the wall, 2 bottles of beer.\n"
       "Take one down and pass it around, 1 bottle of beer on the wall.\n"
       "\n"
       "1 bottle of beer on the wall, 1 bottle of beer.\n"
       "Take it down and pass it around, no more bottles of beer on the wall.\n"
       "\n"
       "No more bottles of beer on the wall, no more bottles of beer.\n"
       "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

   recite(2, 3, response);
   TEST_ASSERT_EQUAL_STRING(expected, response);
}

int main(void)
{
   UnityBegin("test_beer_song.c");

   RUN_TEST(test_first_generic_verse);
   RUN_TEST(test_last_generic_verse);
   RUN_TEST(test_verse_with_2_bottles);
   RUN_TEST(test_verse_with_1_bottle);
   RUN_TEST(test_verse_with_0_bottles);
   RUN_TEST(test_first_two_verses);
   RUN_TEST(test_last_three_verses);

   return UnityEnd();
}

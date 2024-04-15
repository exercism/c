#include "rotational_cipher.h"

#include "test-framework/unity.h"

#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_rotate(const char *expected, const char *text, int shift_key)
{
   char *rotated = rotate(text, shift_key);

   TEST_ASSERT_EQUAL_STRING(expected, rotated);

   free(rotated);
}

static void test_rotate_a_by_0_same_output_as_input(void)
{
   test_rotate("a", "a", 0);
}

static void test_rotate_a_by_1(void)
{
   TEST_IGNORE();   // delete this line to run test
   test_rotate("b", "a", 1);
}

static void test_rotate_a_by_26_same_output_as_input(void)
{
   TEST_IGNORE();
   test_rotate("a", "a", 26);
}

static void test_rotate_m_by_13(void)
{
   TEST_IGNORE();
   test_rotate("z", "m", 13);
}

static void test_rotate_n_by_13_with_wrap_around_alphabet(void)
{
   TEST_IGNORE();
   test_rotate("a", "n", 13);
}

static void test_rotate_capital_letters(void)
{
   TEST_IGNORE();
   test_rotate("TRL", "OMG", 5);
}

static void test_rotate_spaces(void)
{
   TEST_IGNORE();
   test_rotate("T R L", "O M G", 5);
}

static void test_rotate_numbers(void)
{
   TEST_IGNORE();
   test_rotate("Xiwxmrk 1 2 3 xiwxmrk", "Testing 1 2 3 testing", 4);
}

static void test_rotate_punctuation(void)
{
   TEST_IGNORE();
   test_rotate("Gzo'n zvo, Bmviyhv!", "Let's eat, Grandma!", 21);
}

static void test_rotate_all_letters(void)
{
   TEST_IGNORE();
   test_rotate("Gur dhvpx oebja sbk whzcf bire gur ynml qbt.",
               "The quick brown fox jumps over the lazy dog.", 13);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_rotate_a_by_0_same_output_as_input);
   RUN_TEST(test_rotate_a_by_1);
   RUN_TEST(test_rotate_a_by_26_same_output_as_input);
   RUN_TEST(test_rotate_m_by_13);
   RUN_TEST(test_rotate_n_by_13_with_wrap_around_alphabet);
   RUN_TEST(test_rotate_capital_letters);
   RUN_TEST(test_rotate_spaces);
   RUN_TEST(test_rotate_numbers);
   RUN_TEST(test_rotate_punctuation);
   RUN_TEST(test_rotate_all_letters);

   return UNITY_END();
}

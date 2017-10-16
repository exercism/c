#include "vendor/unity.h"
#include "../src/atbash_cipher.h"
#include <stdlib.h>
#include <string.h>

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_encode(char *input, char *expected)
{
   char *result = atbash_encode(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

static void test_decode(char *input, char *expected)
{
   char *result = atbash_decode(input);

   TEST_ASSERT_EQUAL_STRING(expected, result);

   free(result);
}

void test_encode_yes(void)
{
   test_encode("yes", "bvh");
}

void test_encode_no(void)
{
   TEST_IGNORE();
   test_encode("no", "ml");
}

void test_encode_OMG(void)
{
   TEST_IGNORE();
   test_encode("OMG", "lnt");
}

void test_encode_spaces(void)
{
   TEST_IGNORE();
   test_encode("O M G", "lnt");
}

void test_encode_mindblowingly(void)
{
   TEST_IGNORE();
   test_encode("mindblowingly", "nrmwy oldrm tob");
}

void test_encode_numbers(void)
{
   TEST_IGNORE();
   test_encode("Testing,1 2 3, testing.", "gvhgr mt123 gvhgr mt");
}

void test_encode_deep_thought(void)
{
   TEST_IGNORE();
   test_encode("Truth is fiction.", "gifgs rhurx grlm");
}

void test_encode_all_the_letters(void)
{
   TEST_IGNORE();
   test_encode("The quick brown fox jumps over the lazy dog.",
               "gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt");
}

void test_encode_ignores_non_ascii(void)
{
   TEST_IGNORE();
   test_encode("non ascii éignored", "mlmzh xrrrt mlivw");
}

void test_decode_exercism(void)
{
   TEST_IGNORE();
   test_decode("vcvix rhn", "exercism");
}

void test_decode_a_sentence(void)
{
   TEST_IGNORE();
   test_decode("zmlyh gzxov rhlug vmzhg vkkrm thglm v",
               "anobstacleisoftenasteppingstone");
}

void test_decode_numbers(void)
{
   TEST_IGNORE();
   test_decode("gvhgr mt123 gvhgr mt", "testing123testing");
}

void test_decode_all_the_letters(void)
{
   TEST_IGNORE();
   test_decode("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt",
               "thequickbrownfoxjumpsoverthelazydog");
}

int main(void)
{
   UnityBegin("test/test_atbash_cipher.c");

   RUN_TEST(test_encode_yes);
   RUN_TEST(test_encode_no);
   RUN_TEST(test_encode_OMG);
   RUN_TEST(test_encode_spaces);
   RUN_TEST(test_encode_mindblowingly);
   RUN_TEST(test_encode_numbers);
   RUN_TEST(test_encode_deep_thought);
   RUN_TEST(test_encode_all_the_letters);
   RUN_TEST(test_encode_ignores_non_ascii);

   RUN_TEST(test_decode_exercism);
   RUN_TEST(test_decode_a_sentence);
   RUN_TEST(test_decode_numbers);
   RUN_TEST(test_decode_all_the_letters);

   UnityEnd();
   return 0;
}

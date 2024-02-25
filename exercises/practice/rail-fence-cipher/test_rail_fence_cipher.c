#include "test-framework/unity.h"
#include <stdlib.h>
#include "rail_fence_cipher.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_encode_with_two_rails(void)
{
   TEST_IGNORE();
   char *actual = encode("XOXOXOXOXOXOXOXOXO", 2);
   TEST_ASSERT_EQUAL_STRING("XXXXXXXXXOOOOOOOOO", actual);
   free(actual);
}

static void test_encode_with_three_rails(void)
{
   TEST_IGNORE();
   char *actual = encode("WEAREDISCOVEREDFLEEATONCE", 3);
   TEST_ASSERT_EQUAL_STRING("WECRLTEERDSOEEFEAOCAIVDEN", actual);
   free(actual);
}

static void test_encode_with_ending_in_the_middle(void)
{
   TEST_IGNORE();
   char *actual = encode("EXERCISES", 4);
   TEST_ASSERT_EQUAL_STRING("ESXIEECSR", actual);
   free(actual);
}

static void test_decode_with_three_rails(void)
{
   TEST_IGNORE();
   char *actual = decode("TEITELHDVLSNHDTISEIIEA", 3);
   TEST_ASSERT_EQUAL_STRING("THEDEVILISINTHEDETAILS", actual);
   free(actual);
}

static void test_decode_with_five_rails(void)
{
   TEST_IGNORE();
   char *actual = decode("EIEXMSMESAORIWSCE", 5);
   TEST_ASSERT_EQUAL_STRING("EXERCISMISAWESOME", actual);
   free(actual);
}

static void test_decode_with_six_rails(void)
{
   TEST_IGNORE();
   char *actual = decode(
       "133714114238148966225439541018335470986172518171757571896261", 6);
   TEST_ASSERT_EQUAL_STRING(
       "112358132134558914423337761098715972584418167651094617711286", actual);
   free(actual);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_encode_with_two_rails);
   RUN_TEST(test_encode_with_three_rails);
   RUN_TEST(test_encode_with_ending_in_the_middle);
   RUN_TEST(test_decode_with_three_rails);
   RUN_TEST(test_decode_with_five_rails);
   RUN_TEST(test_decode_with_six_rails);

   return UNITY_END();
}

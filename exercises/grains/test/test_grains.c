#include "vendor/unity.h"
#include "../src/grains.h"

void test_square_1(void) {
  TEST_ASSERT_EQUAL(1ul, square(1));
}

void test_square_2(void) {
  TEST_ASSERT_EQUAL(2ul, square(2));
}

void test_square_3(void) {
  TEST_ASSERT_EQUAL(4ul, square(3));
}

void test_square_4(void) {
  TEST_ASSERT_EQUAL(8ul, square(4));
}

void test_square_16(void) {
  TEST_ASSERT_EQUAL(32768ul, square(16));
}

void test_square_32(void) {
  TEST_ASSERT_EQUAL(2147483648ul, square(32));
}

void test_square_64(void) {
  TEST_ASSERT_EQUAL(9223372036854775808ul, square(64));
}

void test_total(void) {
  TEST_ASSERT_EQUAL(18446744073709551615ul, total());
}

int main(void) {
  UnityBegin("test/test_grains.c");

  RUN_TEST(test_square_1);
  RUN_TEST(test_square_2);
  RUN_TEST(test_square_3);
  RUN_TEST(test_square_4);
  RUN_TEST(test_square_16);
  RUN_TEST(test_square_32);
  RUN_TEST(test_square_64);
  RUN_TEST(test_total);

  UnityEnd();
  return 0;
}

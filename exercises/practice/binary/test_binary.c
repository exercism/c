#include "test-framework/unity.h"
#include "binary.h"

void setUp(void) {}
void tearDown(void) {}

static void test_binary_conversion(void)
{
    TEST_ASSERT_EQUAL(0, convert("0"));
    TEST_ASSERT_EQUAL(1, convert("1"));
    TEST_ASSERT_EQUAL(2, convert("10"));
    TEST_ASSERT_EQUAL(3, convert("11"));
    TEST_ASSERT_EQUAL(4, convert("100"));
    TEST_ASSERT_EQUAL(9, convert("1001"));
    TEST_ASSERT_EQUAL(26, convert("11010"));
    TEST_ASSERT_EQUAL(1128, convert("10001101000"));
    TEST_ASSERT_EQUAL(31, convert("000011111"));
}

static void test_invalid_inputs(void)
{
    TEST_ASSERT_EQUAL(INVALID, convert("2"));
    TEST_ASSERT_EQUAL(INVALID, convert("01201"));
    TEST_ASSERT_EQUAL(INVALID, convert("10nope"));
    TEST_ASSERT_EQUAL(INVALID, convert("nope10"));
    TEST_ASSERT_EQUAL(INVALID, convert("10nope10"));
    TEST_ASSERT_EQUAL(INVALID, convert("001 nope"));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_binary_conversion);
    RUN_TEST(test_invalid_inputs);

    return UNITY_END();
}

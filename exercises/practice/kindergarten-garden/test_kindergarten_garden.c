#include "kindergarten_garden.h"

#include "test-framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_kindergarten_garden(const char *diagram, const char *student,
                                     const plants_t expected)
{
   const plants_t actual = plants(diagram, student);

   TEST_ASSERT_EQUAL_INT_ARRAY(expected.plants, actual.plants, 4);
}

static void test_partial_garden_garden_with_single_student(void)
{
   const plants_t expected = { .plants = { RADISHES, CLOVER, GRASS, GRASS } };
   test_kindergarten_garden("RC\n"
                            "GG",
                            "Alice", expected);
}

static void test_partial_garden_different_garden_with_single_student(void)
{
   TEST_IGNORE();   // delete this line to run test
   const plants_t expected = { .plants = { VIOLETS, CLOVER, RADISHES,
                                           CLOVER } };
   test_kindergarten_garden("VC\n"
                            "RC",
                            "Alice", expected);
}

static void test_partial_garden_garden_with_two_students(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { CLOVER, GRASS, RADISHES, CLOVER } };
   test_kindergarten_garden("VVCG\n"
                            "VVRC",
                            "Bob", expected);
}

static void test_partial_garden_second_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { CLOVER, CLOVER, CLOVER, CLOVER } };
   test_kindergarten_garden("VVCCGG\n"
                            "VVCCGG",
                            "Bob", expected);
}

static void test_partial_garden_third_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { GRASS, GRASS, GRASS, GRASS } };
   test_kindergarten_garden("VVCCGG\n"
                            "VVCCGG",
                            "Charlie", expected);
}

static void test_full_garden_for_alice_first_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { VIOLETS, RADISHES, VIOLETS,
                                           RADISHES } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Alice", expected);
}

static void test_full_garden_for_bob_second_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { CLOVER, GRASS, CLOVER, CLOVER } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Bob", expected);
}

static void test_full_garden_for_charlie(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { VIOLETS, VIOLETS, CLOVER, GRASS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Charlie", expected);
}

static void test_full_garden_for_david(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { RADISHES, VIOLETS, CLOVER,
                                           RADISHES } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "David", expected);
}

static void test_full_garden_for_eve(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { CLOVER, GRASS, RADISHES, GRASS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Eve", expected);
}

static void test_full_garden_for_fred(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { GRASS, CLOVER, VIOLETS, CLOVER } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Fred", expected);
}

static void test_full_garden_for_ginny(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { CLOVER, GRASS, GRASS, CLOVER } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Ginny", expected);
}

static void test_full_garden_for_harriet(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { VIOLETS, RADISHES, RADISHES,
                                           VIOLETS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Harriet", expected);
}

static void test_full_garden_for_ileana(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { GRASS, CLOVER, VIOLETS, CLOVER } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Ileana", expected);
}

static void test_full_garden_for_joseph(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { VIOLETS, CLOVER, VIOLETS, GRASS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Joseph", expected);
}

static void test_full_garden_for_kincaid_second_to_last_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { GRASS, CLOVER, CLOVER, GRASS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Kincaid", expected);
}

static void test_full_garden_for_larry_last_student_s_garden(void)
{
   TEST_IGNORE();
   const plants_t expected = { .plants = { GRASS, VIOLETS, CLOVER, VIOLETS } };
   test_kindergarten_garden("VRCGVVRVCGGCCGVRGCVCGCGV\n"
                            "VRCCCGCRRGVCGCRVVCVGCGCV",
                            "Larry", expected);
}

int main(void)
{
   UNITY_BEGIN();

   RUN_TEST(test_partial_garden_garden_with_single_student);
   RUN_TEST(test_partial_garden_different_garden_with_single_student);
   RUN_TEST(test_partial_garden_garden_with_two_students);
   RUN_TEST(test_partial_garden_second_student_s_garden);
   RUN_TEST(test_partial_garden_third_student_s_garden);
   RUN_TEST(test_full_garden_for_alice_first_student_s_garden);
   RUN_TEST(test_full_garden_for_bob_second_student_s_garden);
   RUN_TEST(test_full_garden_for_charlie);
   RUN_TEST(test_full_garden_for_david);
   RUN_TEST(test_full_garden_for_eve);
   RUN_TEST(test_full_garden_for_fred);
   RUN_TEST(test_full_garden_for_ginny);
   RUN_TEST(test_full_garden_for_harriet);
   RUN_TEST(test_full_garden_for_ileana);
   RUN_TEST(test_full_garden_for_joseph);
   RUN_TEST(test_full_garden_for_kincaid_second_to_last_student_s_garden);
   RUN_TEST(test_full_garden_for_larry_last_student_s_garden);

   return UNITY_END();
}

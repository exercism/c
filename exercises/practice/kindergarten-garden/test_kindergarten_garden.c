#include "kindergarten_garden.h"

#include "test-framework/unity.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_kindergarten_garden(const char *diagram, const char *student,
                                     const plant_t *expected)
{
   plant_t actual[4];
   plants(diagram, student, actual);

   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, 4);
}

static void test_partial_garden_garden_with_single_student(void)
{
   const plant_t expected[] = { RADISHES, CLOVER, GRASS, GRASS };
   test_kindergarten_garden("RC\nGG", "Alice", expected);
}

static void test_partial_garden_different_garden_with_single_student(void)
{
   const plant_t expected[] = { VIOLETS, CLOVER, RADISHES, CLOVER };
   test_kindergarten_garden("VC\nRC", "Alice", expected);
}

static void test_partial_garden_garden_with_two_students(void)
{
   const plant_t expected[] = { CLOVER, GRASS, RADISHES, CLOVER };
   test_kindergarten_garden("VVCG\nVVRC", "Bob", expected);
}

static void test_partial_garden_second_student_s_garden(void)
{
   const plant_t expected[] = { CLOVER, CLOVER, CLOVER, CLOVER };
   test_kindergarten_garden("VVCCGG\nVVCCGG", "Bob", expected);
}

static void test_partial_garden_third_student_s_garden(void)
{
   const plant_t expected[] = { GRASS, GRASS, GRASS, GRASS };
   test_kindergarten_garden("VVCCGG\nVVCCGG", "Charlie", expected);
}

static void test_full_garden_for_alice_first_student_s_garden(void)
{
   const plant_t expected[] = { VIOLETS, RADISHES, VIOLETS, RADISHES };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Alice", expected);
}

static void test_full_garden_for_bob_second_student_s_garden(void)
{
   const plant_t expected[] = { CLOVER, GRASS, CLOVER, CLOVER };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Bob", expected);
}

static void test_full_garden_for_charlie(void)
{
   const plant_t expected[] = { VIOLETS, VIOLETS, CLOVER, GRASS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Charlie",
       expected);
}

static void test_full_garden_for_david(void)
{
   const plant_t expected[] = { RADISHES, VIOLETS, CLOVER, RADISHES };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "David", expected);
}

static void test_full_garden_for_eve(void)
{
   const plant_t expected[] = { CLOVER, GRASS, RADISHES, GRASS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Eve", expected);
}

static void test_full_garden_for_fred(void)
{
   const plant_t expected[] = { GRASS, CLOVER, VIOLETS, CLOVER };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Fred", expected);
}

static void test_full_garden_for_ginny(void)
{
   const plant_t expected[] = { CLOVER, GRASS, GRASS, CLOVER };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Ginny", expected);
}

static void test_full_garden_for_harriet(void)
{
   const plant_t expected[] = { VIOLETS, RADISHES, RADISHES, VIOLETS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Harriet",
       expected);
}

static void test_full_garden_for_ileana(void)
{
   const plant_t expected[] = { GRASS, CLOVER, VIOLETS, CLOVER };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Ileana",
       expected);
}

static void test_full_garden_for_joseph(void)
{
   const plant_t expected[] = { VIOLETS, CLOVER, VIOLETS, GRASS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Joseph",
       expected);
}

static void test_full_garden_for_kincaid_second_to_last_student_s_garden(void)
{
   const plant_t expected[] = { GRASS, CLOVER, CLOVER, GRASS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Kincaid",
       expected);
}

static void test_full_garden_for_larry_last_student_s_garden(void)
{
   const plant_t expected[] = { GRASS, VIOLETS, CLOVER, VIOLETS };
   test_kindergarten_garden(
       "VRCGVVRVCGGCCGVRGCVCGCGV\nVRCCCGCRRGVCGCRVVCVGCGCV", "Larry", expected);
}

int main(void)
{
   UnityBegin("test_kindergarten-garden.c");

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

   return UnityEnd();
}

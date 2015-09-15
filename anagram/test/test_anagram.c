#include <stdlib.h>
#include <string.h>

#include "unity.h"
#include "anagram.h"

void setUp(void) {
}

void tearDown(void) {
}

int stringcmp(const void *a, const void *b) {
  return strcmp(a, b);
}

void test_no_matches(void) {
  char inputs[][MAX_STR_LEN] = {
    "hello",
    "world",
    "zombies",
    "pants"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("diaper", vin);

  TEST_ASSERT_EQUAL(0, vout.size);

  free(vout.vec);
}

void test_detect_simple_anagram(void) {
  char inputs[][MAX_STR_LEN] = {
    "tan",
    "stand",
    "at"
  };

  char outputs[][MAX_STR_LEN] = {
    "tan"
  };
  int outputs_len = sizeof(outputs)/MAX_STR_LEN;

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("ant", vin);

  TEST_ASSERT_EQUAL(outputs_len, vout.size);
  for (int x = 0; x < vout.size; x++) {
    TEST_ASSERT_EQUAL(strlen(outputs[x]), strlen(vout.vec[x]));
    TEST_ASSERT_EQUAL_MEMORY(outputs[x], vout.vec[x], strlen(outputs[x]));
  }

  free(vout.vec);
}

void test_does_not_confuse_different_duplicates(void) {
  char inputs[][MAX_STR_LEN] = {
    "eagle"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("galea", vin);

  TEST_ASSERT_EQUAL(0, vout.size);

  free(vout.vec);
}

void test_eliminate_anagram_subsets(void) {
  char inputs[][MAX_STR_LEN] = {
    "dog",
    "goody"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("good", vin);

  TEST_ASSERT_EQUAL(0, vout.size);

  free(vout.vec);
}

void test_detect_anagram(void) {
  char inputs[][MAX_STR_LEN] = {
    "enlists",
    "google",
    "inlets",
    "banana"
  };

  char outputs[][MAX_STR_LEN] = {
    "inlets"
  };
  int outputs_len = sizeof(outputs)/MAX_STR_LEN;

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("listen", vin);

  TEST_ASSERT_EQUAL(outputs_len, vout.size);
  for (int x = 0; x < vout.size; x++) {
    TEST_ASSERT_EQUAL(strlen(outputs[x]), strlen(vout.vec[x]));
    TEST_ASSERT_EQUAL_MEMORY(outputs[x], vout.vec[x], strlen(outputs[x]));
  }

  free(vout.vec);
}

void test_multiple_anagrams(void) {
  char inputs[][MAX_STR_LEN] = {
    "gallery",
    "ballerina",
    "regally",
    "clergy",
    "largely",
    "leading"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  char outputs[][MAX_STR_LEN] = {
    "gallery",
    "regally",
    "largely"
  };
  int outputs_len = sizeof(outputs)/MAX_STR_LEN;
  qsort(outputs, outputs_len, sizeof(char)*MAX_STR_LEN, stringcmp);

  struct Vector vout = anagrams_for("allergy", vin);
  qsort(vout.vec, vout.size, sizeof(char)*MAX_STR_LEN, stringcmp);

  TEST_ASSERT_EQUAL(outputs_len, vout.size);
  for (int x = 0; x < vout.size; x++) {
    TEST_ASSERT_EQUAL(strlen(outputs[x]), strlen(vout.vec[x]));
    TEST_ASSERT_EQUAL_MEMORY(outputs[x], vout.vec[x], strlen(outputs[x]));
  }

  free(vout.vec);
}

void test_case_insensitive_anagrams(void) {
  char inputs[][MAX_STR_LEN] = {
    "cashregister",
    "Carthorse",
    "radishes"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  char outputs[][MAX_STR_LEN] = {
    "Carthorse"
  };
  int outputs_len = sizeof(outputs)/MAX_STR_LEN;
  qsort(outputs, outputs_len, sizeof(char)*MAX_STR_LEN, stringcmp);

  struct Vector vout = anagrams_for("Orchestra", vin);
  qsort(vout.vec, vout.size, sizeof(char)*MAX_STR_LEN, stringcmp);

  TEST_ASSERT_EQUAL(outputs_len, vout.size);
  for (int x = 0; x < vout.size; x++) {
    TEST_ASSERT_EQUAL(strlen(outputs[x]), strlen(vout.vec[x]));
    TEST_ASSERT_EQUAL_MEMORY(outputs[x], vout.vec[x], strlen(outputs[x]));
  }

  free(vout.vec);
}

// void test_unicode_anagrams(void) {
//   // These words don't make sense, they're just greek letters cobbled together.
//   char inputs[][MAX_STR_LEN] = {
//     "ΒΓΑ",
//     "ΒΓΔ",
//     "γβα"
//   };
//
//   struct Vector vin = {
//     inputs,
//     sizeof(inputs)/MAX_STR_LEN
//   };
//
//   char outputs[][MAX_STR_LEN] = {
//     "ΒΓΑ",
//     "γβα"
//   };
//   int outputs_len = sizeof(outputs)/MAX_STR_LEN;
//   qsort(outputs, outputs_len, sizeof(char)*MAX_STR_LEN, stringcmp);
//
//   struct Vector vout = anagrams_for("ΑΒΓ", vin);
//   qsort(vout.vec, vout.size, sizeof(char)*MAX_STR_LEN, stringcmp);
//
//   TEST_ASSERT_EQUAL(outputs_len, vout.size);
//   for (int x = 0; x < vout.size; x++) {
//     TEST_ASSERT_EQUAL(strlen(outputs[x]), strlen(vout.vec[x]));
//     TEST_ASSERT_EQUAL_MEMORY(outputs[x], vout.vec[x], strlen(outputs[x]));
//   }
//
//   free(vout.vec);
// }
//
// void test_misleading_unicode_anagrams(void) {
//   // Despite what a human might think these words different letters, the input uses Greek A and B
//   // while the list of potential anagrams uses Latin A and B.
//   char inputs[][MAX_STR_LEN] = {
//     "ABΓ"
//   };
//
//   struct Vector vin = {
//     inputs,
//     sizeof(inputs)/MAX_STR_LEN
//   };
//
//   struct Vector vout = anagrams_for("ΑΒΓ", vin);
//
//   TEST_ASSERT_EQUAL(0, vout.size);
//
//   free(vout.vec);
// }

void test_does_not_detect_a_word_as_its_own_anagram(void) {
  char inputs[][MAX_STR_LEN] = {
    "banana"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("banana", vin);

  TEST_ASSERT_EQUAL(0, vout.size);

  free(vout.vec);
}

void test_does_not_detect_a_differently_cased_word_as_its_own_anagram(void) {
  char inputs[][MAX_STR_LEN] = {
    "bAnana"
  };

  struct Vector vin = {
    inputs,
    sizeof(inputs)/MAX_STR_LEN
  };

  struct Vector vout = anagrams_for("banana", vin);

  TEST_ASSERT_EQUAL(0, vout.size);

  free(vout.vec);
}

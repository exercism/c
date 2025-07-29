#include "test-framework/unity.h"
#include "hangman.h"
#include "string.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_initial_state(void) {
    Hangman* game = create_game("foo");
    TEST_ASSERT_EQUAL_STRING(STATUS_ONGOING, get_status(game));
    TEST_ASSERT_EQUAL_STRING("___", get_masked_word(game));
    TEST_ASSERT_EQUAL_INT(9, game->remaining_guesses);
    destroy_game(game);
}

// void test_game_lost_after_10_wrong_guesses(void) {
//     Hangman* game = create_game("foo");

//     for (int i = 0; i < 10; i++) {
//         guess_letter(game, 'x');
//     }

//     TEST_ASSERT_EQUAL_STRING(STATUS_LOSE, get_status(game));

//     destroy_game(game);
// }

void test_correct_guess_reveals_letter(void) {
    Hangman* game = create_game("foobar");
    guess_letter(game, 'b');
    TEST_ASSERT_EQUAL_STRING(STATUS_ONGOING, get_status(game));
    TEST_ASSERT_EQUAL_STRING("___b__", get_masked_word(game));
    TEST_ASSERT_EQUAL_INT(9, game->remaining_guesses);
    destroy_game(game);
}

void test_wrong_guess_reduces_remaining(void) {
    Hangman* game = create_game("foo");
    guess_letter(game, 'x');
    TEST_ASSERT_EQUAL_STRING(STATUS_ONGOING, get_status(game));
    TEST_ASSERT_EQUAL_STRING("___", get_masked_word(game));
    TEST_ASSERT_EQUAL_INT(8, game->remaining_guesses);
    destroy_game(game);
}



int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_initial_state);
    //RUN_TEST(test_game_lost_after_10_wrong_guesses);
    RUN_TEST(test_correct_guess_reveals_letter);
    RUN_TEST(test_wrong_guess_reduces_remaining);

    return UNITY_END();
}

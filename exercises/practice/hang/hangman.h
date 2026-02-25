#ifndef HANGMAN_H
#define HANGMAN_H

#define STATUS_WIN "win"
#define STATUS_LOSE "lose"
#define STATUS_ONGOING "ongoing"

typedef struct {
    char* word;
    char* masked_word;
    int* guessed_letters;
    int remaining_guesses;
    const char* status;
} Hangman;

Hangman* create_game(const char* word);
void destroy_game(Hangman* game);
void guess_letter(Hangman* game, char letter);
const char* get_masked_word(Hangman* game);
const char* get_status(Hangman* game);

#endif

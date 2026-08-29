#include "hangman.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

Hangman* create_game(const char* word) {
    Hangman* game = malloc(sizeof(Hangman));
    if (!game) return NULL;

    game->word = strdup(word);
    game->masked_word = malloc(strlen(word) + 1);
    game->guessed_letters = calloc(26, sizeof(int));  

    for (size_t i = 0; i < strlen(word); i++) {
        game->masked_word[i] = '_';
    }
    game->masked_word[strlen(word)] = '\0';

    game->remaining_guesses = 9;
    game->status = STATUS_ONGOING;

    return game;
}

void destroy_game(Hangman* game) {
    if (!game) return;
    free(game->word);
    free(game->masked_word);
    free(game->guessed_letters);
    free(game);
}

void guess_letter(Hangman* game, char letter) {
    if (strcmp(game->status, STATUS_ONGOING) != 0) {
        fprintf(stderr, "The game has already ended.\n");
        exit(1);
    }

    letter = tolower(letter);
    if (game->guessed_letters[letter - 'a']) {
        game->remaining_guesses--;
        return;
    }

    game->guessed_letters[letter - 'a'] = 1;

    int correct = 0;
    for (size_t i = 0; i < strlen(game->word); i++) {
        if (tolower(game->word[i]) == letter) {
            game->masked_word[i] = game->word[i];
            correct = 1;
        }
    }

    if (!correct) {
        game->remaining_guesses--;
    }

    if (strcmp(game->word, game->masked_word) == 0) {
        game->status = STATUS_WIN;
    } else if (game->remaining_guesses == 0) {
        game->status = STATUS_LOSE;
    }
}

const char* get_masked_word(Hangman* game) {
    return game->masked_word;
}

const char* get_status(Hangman* game) {
    return game->status;
}

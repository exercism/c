#include "secret_handshake.h"
#include <stdint.h>
#include <stdlib.h>

const char *actions[] = {"wink", "double blink", "close your eyes", "jump"};

const char **commands(const size_t number) {
  const char **action_sequence = calloc(4, sizeof(char *));
  size_t k = 0;
  if (number & 16) {
    for (int i = 3; i >= 0; i--)
      if (number & 1 << i)
        action_sequence[k++] = actions[i];
  } else {
    for (int i = 0; i <= 3; i++)
      if (number & 1 << i)
        action_sequence[k++] = actions[i];
  }
  return action_sequence;
}

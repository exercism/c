#include "secret_handshake.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct {
   const char *cmd;
   const size_t num;
} cmd_t;

static const cmd_t cmds[] = {
   {"wink", 1}, {"double blink", 2},
   {"close your eyes", 4}, {"jump", 8}
};

static const size_t CMD_COUNT = ARRAY_SIZE(cmds);
static const size_t CMD_REVERSE = 16;

/* bitcount: count the number of set bits in n */
static size_t bitcount(size_t num)
{
   size_t count;
   for (count = 0; num; num = num & (num - 1), count++) ;
   return count;
}

const char **commands(size_t number)
{
   if (number > 31)
      number %= 32;

   bool reverse = false;
   if ((number & CMD_REVERSE) == CMD_REVERSE) {
      number -= CMD_REVERSE;
      reverse = true;
   }

   const size_t len = bitcount(number);
   const char **cmd_array = malloc(sizeof(char *) * (len ? len : 1));
   if (cmd_array == NULL) {
      fprintf(stderr, "Memory error!\n");
      return NULL;
   }

   if (len == 0) {
      cmd_array[0] = NULL;
      return cmd_array;
   }

   size_t pos_cmd_array = 0;
   for (size_t i = 0; i < CMD_COUNT; i++) {
      size_t k = reverse ? (CMD_COUNT - 1 - i) : i;
      if ((number & cmds[k].num) == cmds[k].num)
         cmd_array[pos_cmd_array++] = cmds[k].cmd;
   }

   return cmd_array;
}

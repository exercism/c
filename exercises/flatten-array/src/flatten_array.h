#ifndef FLATTEN_ARRAY_H
#define FLATTEN_ARRAY_H

#define NONE 0

enum item_type { UNDEF, null, ELEMENT, ARRAY };

typedef struct item item_t;

struct item {
   item_t *next;
   item_t *array_elements;
   enum item_type type;
   int value;
};

int *flatten(item_t * head);

#endif

#ifndef PROTEIN_TRANSLATION_H
#define PROTEIN_TRANSLATION_H

#include <stdbool.h>
#include <stddef.h>

#define MAX_AMINOACIDS 10

typedef enum {
   Methionine,
   Phenylalanine,
   Leucine,
   Serine,
   Tyrosine,
   Cysteine,
   Tryptophan,
} aminoacid_t;

typedef struct {
   bool valid;
   size_t count;
   aminoacid_t protein[MAX_AMINOACIDS];
} protein_t;

protein_t protein(const char *const rna);

#endif

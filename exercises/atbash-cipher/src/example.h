#ifndef _ATBASH_CIPHER_H
#define _ATBASH_CIPHER_H

#define GROUP_SIZE      (5)

void atbash_encode(const char *input, char *output);
void atbash_decode(const char *input, char *output);

#endif

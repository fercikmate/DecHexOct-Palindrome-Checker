#ifndef LIB_H
#define LIB_H
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>

struct PalindromeList {
    int_least32_t number;
    struct PalindromeList *next;
};

void getParameters(int_least32_t *getNumber, int_least8_t *getSystem);
void findPalindromes(int_least32_t findNumber, int_least8_t findSystem);
int_least32_t reverseInBase(int_least32_t ReverseNumber, int_least8_t ReverseBase);
void addToList(struct PalindromeList **head, struct PalindromeList **tail, int_least32_t FoundNumber);
void printPalindromes(struct PalindromeList *head);

#endif

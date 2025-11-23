#ifndef PALINDROME_H
#define PALINDROME_H
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
void findPalindromes(const int_least32_t findNumber, const int_least8_t findSystem);
int_least32_t reverseInBase(const int_least32_t ReverseNumber, const int_least8_t ReverseBase);
void addToList(struct PalindromeList **head, struct PalindromeList **tail, int_least32_t FoundNumber);
void printPalindromes(const struct PalindromeList *head);

#endif

#include "palindrome.h"
void getParameters(int_least32_t *getNumber, int_least8_t *getSystem);
void findPalindromes(const int_least32_t findNumber, const int_least8_t findSystem);
int main(void)
{
    int_least32_t ChosenNumber = 0;
    int_least8_t ChosenSystem = 0;
    /*Enter number and system*/
    getParameters(&ChosenNumber, &ChosenSystem);
    /*Find and print palindromes*/
    findPalindromes(ChosenNumber, ChosenSystem);
    return 0;
}

#include "lib.h"
void getParameters(int_least32_t *getNumber, int_least8_t *getSystem);
void findPalindromes(int_least32_t findNumber, int_least8_t findSystem);
void main()
{
    int_least32_t ChosenNumber = 0;
    int_least8_t ChosenSystem = 0;
    /*Enter number and system*/
    getParameters(&ChosenNumber, &ChosenSystem);
    /*Find and print palindromes*/
    findPalindromes(ChosenNumber, ChosenSystem);
        
}

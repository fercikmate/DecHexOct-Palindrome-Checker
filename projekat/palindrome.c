#include "palindrome.h"
#pragma CHECK_MISRA("-20.9") /*Allow printf scanf */
#pragma CHECK_MISRA("-5.7") /*Allow reusable variables */
#pragma CHECK_MISRA("-20.4") /*Allow dynamic memory allocation */
#pragma CHECK_MISRA("-10.1") /*Allow initializing pointers to NULL */

void getParameters(int_least32_t *getNumber, int_least8_t *getSystem)
{
    printf("Enter a whole number to get all palindromes smaller than it: ");
    *getNumber = 0;
    while(*getNumber <= 0)
    {
        scanf("%" SCNd32, getNumber);
        if (*getNumber <= 0)
        {
            printf("Invalid input. Please enter a positive whole number: ");
            /*clear buffer*/
            int_least32_t c;
            c = getchar();
            while ((c != (int_least32_t)'\n') && (c != (int_least32_t)EOF))
            {
                c = getchar();
            }
            *getNumber = 0; 
        }
    }
    printf("Choose the number system to find all palindromes smaller than %" PRId32 ":\n", *getNumber);
    printf("1- Decimal, 2- Hexadecimal, 3- Octal: ");
    *getSystem = 0;
    while ((*getSystem < 1) || (*getSystem > 3))
    {
        scanf("%" SCNd8, getSystem);
        if ((*getSystem < 1) || (*getSystem > 3))
        {
            printf("Invalid input. Please enter 1, 2, or 3: ");
            int_least32_t c;
            /*clear buffer*/
            c = getchar();
            while ((c != (int_least32_t)'\n') && (c != (int_least32_t)EOF))
            {
                c = getchar();
            }
            *getSystem = 0; 
        }
        
    }
    printf("You have chosen number %" PRId32 " and system %" PRId8 ".\n", *getNumber, *getSystem);
    
}

void findPalindromes(const int_least32_t findNumber,const int_least8_t findSystem)
{
    assert(findNumber > 0);
    assert((findSystem >=  1) && (findSystem <= 3));
    struct PalindromeList *head = NULL;
    struct PalindromeList *current = NULL; /* serves as tail ptr*/
    int_least32_t CheckNumber = 1; 
    switch(findSystem)
    {
        case 1:
            /*Decimal*/
            while(CheckNumber < findNumber)
            {
                /*Reverse the number*/
                int_least32_t DecReversed = reverseInBase(CheckNumber, 10);
                
                if(DecReversed == CheckNumber)
                {
                    /*Add number to list*/
                    addToList(&head, &current, CheckNumber);
                }
                CheckNumber++;
            }
            
            if(head == NULL)
            {
                printf("No decimal palindromes found.\n");
                return;
            }
            else printf("Decimal palindromes found:\n");

            /*Print and free */
            while (head != NULL)
            {
                struct PalindromeList *temp = head;
                printf("Palindrome: %" PRId32 "\n", head->number);
                head = head->next;
                free(temp);
            }
            break;
        case 2:
            /*Hexadecimal*/
            
            while(CheckNumber < findNumber)
            {
                /*Reverse the number*/
                int_least32_t HexReversed = reverseInBase(CheckNumber, 16);
                
                if(HexReversed == CheckNumber)
                {
                    /*Add number to list*/
                   addToList(&head, &current, CheckNumber);
                }
                CheckNumber++;
            }
            
            if(head == NULL)
            {
                printf("No hexadecimal palindromes found.\n");
                return;
            }
            else printf("Hexadecimal palindromes found:\n");

            /*Print and free */
            while (head != NULL)
            {
                struct PalindromeList *temp = head;
                printf("Palindrome: %X (decimal: %" PRId32 ")\n", head->number, head->number);
                head = head->next;
                free(temp);
            }
            break;
        case 3:
            /*Octal*/
            while(CheckNumber < findNumber)
            {
                /*Reverse the number*/
                int_least32_t OctReversed = reverseInBase(CheckNumber, 8);
                if(OctReversed == CheckNumber)
                {
                    /*Add number to list*/
                    addToList(&head, &current, CheckNumber);
                }
                CheckNumber++;
            }
            
            if(head == NULL)
            {
                printf("No octal palindromes found.\n");
                return;
            }
            else printf("Octal palindromes found:\n");

            /*Print and free */
            while (head != NULL)
            {
                struct PalindromeList *temp = head;
                printf("Palindrome: %o (decimal: %" PRId32 ")\n", head->number, head->number);
                head = head->next;
                free(temp);
            }
            break;
        default:
            printf("Invalid system choice.\n");
            break;
    }
}

int_least32_t reverseInBase(const int_least32_t ReverseNumber, const int_least8_t ReverseBase)
{
    assert((ReverseBase == 8) || (ReverseBase == 10) || (ReverseBase == 16));
    assert(ReverseNumber >= 0);
    int_least32_t reversed = 0;
    int_least32_t temp = ReverseNumber;
    while(temp > 0)
    {
        reversed = (reversed * ReverseBase) + (temp % ReverseBase);
        temp = temp / ReverseBase;
    }
    return reversed;
}

void addToList(struct PalindromeList **head, struct PalindromeList **tail, const int_least32_t FoundNumber)
{
    assert((head != NULL) && (tail != NULL)); 
    struct PalindromeList *newPalindrome = malloc(sizeof(struct PalindromeList));
    newPalindrome->number = FoundNumber;
    newPalindrome->next = NULL;
    if(*head == NULL)
    {
        /*First element*/
        *head = newPalindrome;
        *tail = newPalindrome;
    }
    else
    {
        /*let the tail point to lastly added element*/
        (*tail)->next = newPalindrome;
        *tail = newPalindrome;
    }
}


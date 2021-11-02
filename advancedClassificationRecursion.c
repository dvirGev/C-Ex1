#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int breakPalindrome(int n)
{
    int digit = (int)log10(n);
    if (n == 0)
    {
        return 0;
    }
    return (((n % 10) * pow(10, digit)) + breakPalindrome(n / 10));
}
int isPalindrome(int n)
{
    if (n == breakPalindrome(n)) {
        return 1;
    }
    return 0;
}

int breakArmstrong(int n, int numberOfDigit)
{
    if (n < 10)
    {
        return (int)(pow(n, numberOfDigit));
    }
    int x = (int)(pow(n % 10, numberOfDigit));
    return (x + breakArmstrong(n / 10, numberOfDigit));
}
int isArmstrong(int n)
{
    if (n < 0)
    {
        return 0;
    }
    int numberOfDigit = (int)log10(n) + 1;
    if (n == breakArmstrong(n, numberOfDigit))
    {
        return 1;
    }
    return 0;
}
#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n)
{
    int reversed = 0, remainder, original;
    original = n;
    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    if (original == reversed)
    {
        return 1;
    }
    return 0;
}

int isArmstrong(int n)
{
    int numberOfdigit = (int)log10(n) + 1;
    int breakN = n;
    int sum = 0;
    while (breakN > 0)
    {
        int res = breakN % 10;
        sum += (int)pow(res, numberOfdigit);
        breakN /= 10;
    }

    return (sum == n) ? 1 : 0;
}
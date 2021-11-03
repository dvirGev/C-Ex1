#include<stdio.h>
#include<math.h>
#include"NumClass.h"

int factorial(int n) {
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
int isStrong(int n) {
    int x = n;
    int sum = 0;
    while (x > 0)
    {
        int res = x % 10;
        sum += factorial(res);
        x /= 10;
    }
    return (n == sum)? 1: 0;
}

int isPrime(int n) {    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
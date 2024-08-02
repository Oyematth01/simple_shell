#include <stdio.h>

/**
 * factorial - Computes the factorial of a number.
 * @n: The number to compute the factorial of.
 * 
 * Return: The factorial of the number n, or -1 if n < 0.
 */
int factorial(int n)
{
    if (n < 0)
    {
        return (-1); /* Error case for negative input */
    }
    if (n == 0 || n == 1)
    {
        return (1); /* Base case: 0! = 1! = 1 */
    }
    return (n * factorial(n - 1)); /* Recursive case */
}

/**
 * main - Entry point of the program.
 * 
 * Return: Always 0.
 */
int main(void)
{
    int num = 5;
    int result;

    result = factorial(num);
    if (result == -1)
    {
        printf("Error: Negative input\n");
        return (1);
    }
    printf("Factorial of %d is %d\n", num, result);

    return (0);
}

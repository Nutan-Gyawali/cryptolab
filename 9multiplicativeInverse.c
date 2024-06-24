#include <stdio.h>

// Function for the extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find the multiplicative inverse of 'a' under modulo 'm'
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);

    // If gcd is not 1, then inverse does not exist
    if (g != 1)
    {
        printf("Inverse doesn't exist as gcd(%d, %d) = %d\n", a, m, g);
        return -1;
    }
    else
    {
        // m is added to handle negative x
        int res = (x % m + m) % m;
        printf("Multiplicative inverse of %d under modulo %d is %d\n", a, m, res);
        return res;
    }
}

int main()
{
    int a, m = 26;

    // Taking input from the user
    printf("Enter the number to find its multiplicative inverse modulo %d: ", m);
    scanf("%d", &a);

    // Ensure positive integer input
    if (a <= 0)
    {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    // Find the multiplicative inverse modulo 26
    modInverse(a, m);

    return 0;
}

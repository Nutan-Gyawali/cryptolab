/*
 * C program to implement RSA Algorithm
 */

#include <stdio.h>
#include <math.h>

// Function to find gcd
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main()
{
    // 2 random prime numbers
    double p, q;
    char choice;

    do
    {
        printf("Enter two prime numbers: ");
        scanf("%lf %lf", &p, &q);

        double n = p * q;
        double count;
        double totient = (p - 1) * (q - 1);

        // public key - e stands for encrypt
        double e = 2;

        // for checking co-prime which satisfies e > 1
        while (e < totient)
        {
            count = gcd((int)e, (int)totient);
            if (count == 1)
                break;
            else
                e++;
        }

        // private key - d stands for decrypt
        double d;
        // k can be any arbitrary value
        double k = 2;

        // choosing d such that it satisfies d*e = 1 + k * totient
        d = (1 + (k * totient)) / e;

        double msg;
        printf("Enter Message to be encrypted (integer): ");
        scanf("%lf", &msg);

        double c = pow(msg, e);
        double m = pow(c, d);
        c = fmod(c, n);
        m = fmod(m, n);

        printf("p = %.0lf\n", p);
        printf("q = %.0lf\n", q);
        printf("n = pq = %.0lf\n", n);
        printf("totient = %.0lf\n", totient);
        printf("e = %.0lf\n", e);
        printf("d = %.0lf\n", d);
        printf("Encrypted data = %.0lf\n", c);
        printf("Original Message sent = %.0lf\n", m);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any trailing newline character
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

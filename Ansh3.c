#include <stdio.h>

int main() {
    int num, i, remainder, sum = 0, digits = 0;

    scanf("%d", &num);

    i = num;
    while (i != 0) {
        i /= 10;
        digits++;
    }

    i = num;
    while (i != 0) {
        remainder = i % 10;
        int power = 1; // Compute power manually
        for (int j = 0; j < digits; j++) {
            power *= remainder;
        }
        sum += power;
        i /= 10;
    }

    if (sum == num)
        printf("Armstrong");
    else
        printf("Not Armstrong");

    printf("\nAnshkumar Darji - 24CE022");
    return 0;
}



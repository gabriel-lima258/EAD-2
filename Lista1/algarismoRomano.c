#include <stdio.h>
#include <string.h>

void romanNumber(int num, char *roman) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    roman[0] = '\0';

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            strcat(roman, symbols[i]);
            num -= values[i];
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int number;
        scanf("%d", &number);

        char roman[50];

        romanNumber(number, roman);

        printf("%s\n", roman);
    }

    return 0;
}
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int getLastDigit(int number) {
    return abs(number % 10);
}

void printLastDigitMessage(int number) {
    int lastDigit = getLastDigit(number);

    printf("The last digit of %d is ", number);
    
    if (lastDigit == 0) {
        printf("0.\n");
    } else if (lastDigit > 5) {
        printf("%d and is greater than 5.\n", lastDigit);
    } else {
        printf("%d and is less than 6 and not 0.\n", lastDigit);
    }
}

int main(void) {
    srand(time(0));
    int randomNumber = getRandomNumber(-100, 100);
    printLastDigitMessage(randomNumber);
    return 0;
}

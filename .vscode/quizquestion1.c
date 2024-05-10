#include <stdio.h>

void printMatrix(int width, int height);

int main() {
    int width, height;

    //ask the user for width and height
    printf("Enter the width of the matrix: ");
    scanf("%d", &width);
    printf("Enter the height of the matrix: ");
    scanf("%d", &height);

    // Call the printMatrix function
    printMatrix(width, height);

    return 0;
}
//this whole section is trying to make the numbers line up as you had it. I had a few printouts where I forgot and it printed with 10, 11, and 12, so I needed to make this system to make sure they only kept wraping around single digit numbers, which makes the spiral pattern on the printout.
void printMatrix(int width, int height) {
    int i, j, num;

    for (i = 0; i < height; i++) {
        num = i;
        for (j = 0; j < width; j++) {
            printf("%d", num % 10); //numbers are within single digits
            num++;
            if (num > 9) num = 0; // wrap around if num exceeds 9
        }
        printf("\n");
    }
}
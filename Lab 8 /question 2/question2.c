#include <stdio.h>
#include <string.h>
#include "mylibrary.h"
#include "mylibrary.c"

#define MAX 10

int main(){

    double filenumbers [MAX][MAX];
    double currentnum = 0;
    double val;

    FILE *myfile = fopen ("L8_real.txt", "r");

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){

            fscanf (myfile, "%lf ", &currentnum);
            filenumbers[i][j] = currentnum;
        }
    }

    fclose (myfile);

    double diagonalSumgonal = diag(filenumbers);
    double SumOfAll = all(filenumbers);
    double rightmostAve = right(filenumbers);
    double FourCornerSum = corners (filenumbers);
    double LargestNumInDiagtantival = lanti (filenumbers);

    FILE *outb = fopen ("results.bin", "wb");

    fwrite(&diagonalSumgonal, sizeof(diagonalSumgonal), 1, outb);
    fwrite(&SumOfAll, sizeof(SumOfAll), 1, outb);
    fwrite(&rightmostAve, sizeof(rightmostAve), 1, outb);
    fwrite(&FourCornerSum, sizeof(FourCornerSum), 1, outb);
    fwrite(&LargestNumInDiagtantival, sizeof(LargestNumInDiagtantival), 1, outb);

    fclose(outb);

    FILE *inb = fopen ("results.bin", "rb");

    for (int i = 0; i < 5; i++){
        fread(&val, sizeof(val), 1, inb);
        if (i == 0){
            printf ("the sum of the diagonal is: %.2lf \n", val);
        } else if (i == 1){
           printf ("the sum of file numbers is: %.2lf \n", val); 
        } else if (i == 2){
            printf ("the last column average is: %.2lf \n", val);
        } else if (i == 3){
            printf ("the 4 corners added together is: %.2lf \n", val);
        } else if (i == 4){
            printf ("the biggest number in the antidiagonal is: %.2lf \n", val);
        }
    }
    fclose (inb);
    return (0);
}
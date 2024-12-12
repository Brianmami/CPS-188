#include <stdio.h>

int main() {

    int n1 = 9; 
    int number1, number2;
    for (number1 = 1; number1 <= n1; number1++){ //creating loop in a loop

        int firstelement = 1; //creating the first and last digit of each row
        for (number2 = 1; number2 <= number1; number2++){
            printf ("%d ", firstelement); 
            firstelement = firstelement * (number1 - number2) / number2;
        }   //will run through all numbers for variable "number2" until it does not satisfy the condition
            //once it does not satisfy the condition, variable "number1" will increment by 1 and the loop repeats 
        printf("\n");
    }
return(0);
}



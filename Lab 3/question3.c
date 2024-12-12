#include <stdio.h>
#include <math.h>

//create the function with the if statements to compare the final and midterm mark to use the correct method
double midterm_function (double mt, double fe){

    double midterm_calculation;

    if (mt >= fe){

        midterm_calculation = ((mt * 0.35) + (fe * .40));
    } else if (mt < fe) {
       midterm_calculation = ((mt * 0.25) + (fe * .50)); 
    }
return (midterm_calculation);
}

int main()
{
    double array[10]; // array
    int i, j, a; // variables to use for arrays 
    int k = 0; // variable to store the result of the array of the marks given by the user

    //(initialization; condition; update)
    for(i = 0; i < 10; i++)
    {
        printf("enter a test value: ");
        scanf("%lf", &array[i]); //store the values in each array address, going up by one each time
    }

    for(i=0;i < 9; i++) //dropping the first (lowest) mark
    {
        for (j = 0; j < 9; j++)  
        {

            if (array[j] > array[j+1]) // sorting the list in increasing order 
            {
                a = array[j];
                array[j] = array[j+1];
                array[j+1] = a;
            }
        }
    }

    for (i=1; i < 10; i++) //dropping the lowest mark and storing the value of the array into a variable 
    {
        k = array[i] + k;
    }

    double l = k; //making the array value into a double 
    double assignments = (l/0.9) * 0.25; //calculating the value 

    double midmark, finalmark; //asking for midterm and final mark 

        printf("what is your midterm mark?: ");
        scanf("%lf", &midmark);

        printf("what is your final mark?: ");
        scanf("%lf", &finalmark);

    double mark = midterm_function (midmark, finalmark); //calling for the midterm function to find which method to use 
    
    double total_mark = mark + assignments; //adding assignments

printf ("the overall grade is: %lf \n", total_mark);





return (0);
}

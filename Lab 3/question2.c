#include <stdio.h> 
#include <math.h>

// Create the function to calculate body mass index 
double 
bodymassindexcalc (double weight, double height){
    double bmi;
    bmi = weight / (pow(height, 2));
    return (bmi);
}

int main (){
//create the variables to store weight and height and also ask the user for them 
    double w_kg;
    double h_m;

    printf ("What is your weight in kilograms?: ");
    scanf ("%lf", &w_kg);

    printf ("What is your weight in metres?: ");
    scanf ("%lf", &h_m);

    

    // create the if statements to use the correct classification of the users weight 
    double bodymassindex = bodymassindexcalc (w_kg, h_m);
   
    if (bodymassindex < 18.5){

        printf ("your BMI value is %.1lf which classifies you as underweight. \n", bodymassindex);
        } else if (bodymassindex >= 18 && bodymassindex <= 24.9){
            
            printf ("your BMI value is %.1lf which classifies you as normal. \n", bodymassindex);
        } else if (bodymassindex >= 25 && bodymassindex <=29.9){

            printf ("your BMI value is %.1lf, which classifies you as overweight. \n", bodymassindex);
        } else if (bodymassindex > 30){

            printf ("your BMI value is %.1lf which classifies you as obese. \n", bodymassindex);
        }

    
    return (0);
}

#include <stdio.h>
#include <math.h>

int main(){
//set variables
    double A;  
    double B;
    double C;
    double perimeter;

//ask for A
    printf("\nEnter side A: ");
    scanf("%lf", &A);
//ask for B
    printf("Enter side B: ");
    scanf("%lf", &B);

    //hypotenuse 
    C = sqrt((pow(A, 2)) + (pow(B, 2)));
    
    //perimeter
    perimeter = A + B + C;

    //area 
    double area = (A * B) / 2;

        

//print the hypotenuse
    printf("\nThe hypotenuse is: %.2lf\n", C);
//print the perimeter
    printf("The perimeter is: %.2lf\n", perimeter); 
//print the area 
printf("The area is: %.2lf\n", area);

return(0);

}


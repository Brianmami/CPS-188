#include <stdio.h>

int main(){

    FILE *fp;

    int iterations;
    double max, min;


    fp = fopen("numbers3.txt", "r");

    fscanf (fp, "%d %lf %lf ", &iterations, &min, &max);

    double arr[iterations];
    double normalized[iterations];

    for (int i = 0; i < iterations; i++){ //this gets xi and puts it the array at i

        fscanf (fp, "%lf ", &arr[i]);
    }

    double x_lo = 10000;
    double x_hi = -10000;

    for (int i = 0; i < iterations; i++){ //sorts the list for highest and lowest value 
        double value = arr[i];

        if (value < x_lo){
            x_lo = value;
        }

        if (value > x_hi){
            x_hi = value;
        }
    }

    for (int i = 0; i < iterations; i++){

        normalized[i] = min + (arr[i] - x_lo) * (max - min) / (x_hi - x_lo);

    }

    printf ("  Original | Normalized\n");
    printf ("  ---------------------\n");
    
    for (int i = 0; i < iterations; i++){
        printf (" %7.2lf   |     %.2lf       \n", arr[i], normalized[i]);
    }

    fclose (fp);

    return 0;
}
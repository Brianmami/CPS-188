#include <stdio.h>

float temp_to_press (float t1, float p1, float t2){

    float pressure2;
    pressure2 = (p1 / t1) * t2;
    return (pressure2);
}

float press_to_temp (float t1, float p1, float p2){

    float temperature2;
    temperature2 = (t1 / p1) * p2;
    return (temperature2);
}

int main (){
    
    printf("Temperature (K)             Pressure (atm)\n");
    printf("_______________            _______________\n");

    float temp, max_temp;

    max_temp = press_to_temp(300, 50, 500);

    for(temp = 273.15; temp < max_temp; temp += 100){
        printf("\t%-10.2f", temp);
        printf("\t\t%.2f\n", temp_to_press(300, 50, temp));
    }
    
    printf ("\t%-10.2f", max_temp);
    printf ("\t\t500\n");
    printf ("\tkaboom\n");

return(0);
}
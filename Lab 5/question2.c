#include <stdio.h>

void earthToMoon(double speed, double* min, double* max){
    const double PERIGEE = 363104;
    const double APOGEE = 405696;

    *min = PERIGEE / speed;
    *max = APOGEE / speed;
}

void earthToMars(double speed, double* min, double* max){
    const double PERIGEE = 5.46E7;
    const double APOGEE = 4.01E8;

    *min = PERIGEE / speed;
    *max = APOGEE / speed;
}

void earthToVenus(double speed, double* min, double* max){
    const double PERIGEE = 3.8E7;
    const double APOGEE = 2.61E8;

    *min = PERIGEE / speed;
    *max = APOGEE / speed;
}

int main (){

    double menu;
    double min, max;
    double speed;


    while (1){
        
        printf ("1. Traveling to the Moon\n2. Traveling to Mars\n3. Traveling to Venus\n4. Exit program.\n\n");
        printf ("> ");
        scanf("%lf", &menu);

        if (menu == 4){
            break;
        }

        printf ("\nthe speed (km/hr): ");
        scanf ("%lf", &speed);


        if (menu == 1){

            earthToMoon(speed, &min, &max);

        }

        else if (menu == 2){
            earthToMars(speed, &min, &max);

        } 

        else if (menu == 3){
            earthToVenus(speed, &min, &max);

        }
        printf ("the min is %.2f hours and the max is %.2f hours\n", min, max );
        printf("\n");
    }

}
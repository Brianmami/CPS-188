#include <stdio.h>
#include <math.h>

double spsound (double cel)

{

double formula, far;

far = (cel * (9.0 / 5.0)) + 32.0;
formula = 1086.0 * sqrt(((5.0 * far + 297.0) / 247.0)) * 1.09728;

return (formula);

} 

int main(void)

{

    double cels, ans;

    printf ("what is the degrees in celsius?: ");
    scanf ("%lf", &cels);

    ans = spsound(cels);

    printf ("the speed is %lf km/hr.\n", ans);

    return (0);

}

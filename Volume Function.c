
#include <stdio.h>
#include <math.h>


double Volume_in_gal(double dia, double height){
    const float pi = 3.14;
    double volume = pi * ((dia/2)*(dia/2)) * height;
    double gal = volume * 7.47;
    return gal;
}

int main()
{
    double Volume_in_gal(double dia, double height);
        printf("%lf", Volume_in_gal(10.0, 10.0));

    return 0;
}

#include <stdio.h>
#include <math.h>


double P_loss(double l1, double r1, double c1);
double v_drop(double l1, double r1, double c1);

int main()
{
    double v_drop(double c1, double c2, double c3);
        printf("volt: %f\npower: %f", v_drop(16.0, 4.016, 16.0), P_loss(16.0, 4.016, 16.0)); //parameter enter

    return 0;
}

double v_drop(double l1, double r1, double c1){
    double cableres = (r1 / 1000) * l1;
    double voltage = c1 * cableres;
    return voltage;
}

double P_loss(double l1, double r1, double c1){
    double power = (c1 * c1) * r1 ;
    return power;
}
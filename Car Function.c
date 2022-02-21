/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


double mileage(double c1, double c2, double c3);

int main()
{
    double mileage(double c1, double c2, double c3);
        printf("%f", mileage(10.0, 15.0, 40.0)); //parameter enter

    return 0;
}

double mileage(double c1, double c2, double c3){
    double gas = 1/ ((1 / c1) + (1 / c2) + (1 / c3));
    return gas;
}
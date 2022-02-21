/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>


double CritFreq(double R_a, double R_b, double C_a, double C_b){
    const float pi = 3.14;
    double freq = 1 / (pi * 2 * sqrt(R_a * R_b * C_a * C_b));
    return freq;
}

int main()
{
    double CritFreq(double R_a, double R_b, double C_a, double C_b);
        printf("%f", CritFreq(1000,1000,0.022e-6, 0.022e-6)); //parameter enter

    return 0;
}

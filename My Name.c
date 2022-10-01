#include <stdio.h>


char sayMyName(int);

int main(){
    sayMyName(5); //this is # of times to print name
    return 0;
}

char sayMyName(int x){
    char name[] = "your name"; //the name you want printed
    for(int i = 0; i < x; i++)
        printf("%s\n", name);
}   


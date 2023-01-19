#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



void GetNthField(char *dest, const char *sou, int, char *delim);
void GetTime();
void GetLat();
void GetDir();
void GetLon();

int main(){
   
    char tbuf[100];
    char labuf[100];
    char dbuf[10];
    char lobuf[100];
    char field[100];
    char *token;
    char delim[] = ",";
   

    char GPS_GGA_string[] = "$GPGGA,134658.00,5106.9792,N,11402.3003,W,2,09,1.0,1048.47,M,-16.27,M,08,AAAA*60";

    // Ref: https://docs.novatel.com/OEM7/Content/Logs/GPGGA.htm
   
    /*strncpy(buf, GPS_GGA_string + 7, 9);            
buf[99] = 0x00;
printf( "%s", buf);*/
 
    /*token = strtok(buf, delim);
        printf("Field 1 = %s\n", buf);
   
    for (int i = 2; i <= 15; i++){
        token = strtok(NULL, delim);
        printf("Field %d = %s\n", i, token);}*/
   
   
    GetNthField(field, GPS_GGA_string, 1, delim);        GetTime(tbuf, field); //time
    GetNthField(field, GPS_GGA_string, 2, delim);        GetLat(labuf, field); //latitude
    GetNthField(field, GPS_GGA_string, 3, delim);        GetDir(dbuf, field); // lat direction
    GetNthField(field, GPS_GGA_string, 4, delim);        GetLon(lobuf, field); // longitude
    GetNthField(field, GPS_GGA_string, 5, delim);        GetDir(dbuf, field); // lon direction

}


void GetNthField(char *dest, const char *sou, int index, char *delim){ //pointer
    char buf[100]; // make space    
    strcpy(buf, sou); //put source in buf
    char *fntoken;
    fntoken = strtok(buf, delim); //token is made with delim inside buf
   
for(int i = 1; i <= index; i++){ //loops until correct index is found
        fntoken = strtok(NULL, delim); //places NULL in current space after every loop if not the correct index
}
strcpy(dest, fntoken); //transfers token to destination to use inside main
}    

void GetTime(char *dest, const char *sou){
char strhour[5], strmin[5], strsec[5]; //space for each int
int inthour, intmin, intsec;

    strncpy(strhour, sou, 2); //save 2 places from 134658.00
    strncpy(strmin, sou + 2, 2); //save 4 places from 134658.00
    strncpy(strsec, sou + 4, 2); //save 6 places from 134658.00
   
    inthour = atoi(strhour); //convert to int
    intmin = atoi(strmin); //convert to int
    intsec = atoi(strsec); //convert to int
   
    if(inthour >= 13){
        int newHour = inthour - 12; //convert 24h to 12h
            printf("Time: %d:%d:%d PM", newHour, intmin, intsec);
    }
        else if(inthour == 12){ // if exactly 12
            inthour = 12;
            printf("Time: %d:%d:%d AM", inthour, intmin, intsec);
        }
       
    else{ //if not 24h
        printf("Time: %d:%d:%d AM", inthour, intmin, intsec);
    }
}    
   
void GetLat(char *dest, const char *sou){
    
    char strDD[5], strMM[10], strSS[10]; //space for each int
    float floatSS, floatDeg, floatDD, floatMM;
    int intDD, intMM;
    
    strncpy(strDD, sou, 2); //save 2 places 11402.3003
    strncpy(strMM, sou + 2, 2); //save 4 places 11402.3003
    strncpy(strSS, sou + 4, 5); //save 9 places 11402.3003
   
    intDD = atoi(strDD); //convert to int
    intMM = atoi(strMM); //convert to int
    floatSS = atof(strSS); //convert to float
    floatDD = atof(strDD); //convert to float
    floatMM = atoi(strMM); //convert to float
    
    //math
    float floatSec = floatSS*60;
    floatDeg = floatDD + (floatMM / 60) + (floatSS / 3600);
    
    printf("\n\nLatitude: %d° %s' %2.2f\"\n%f", intDD, strMM, floatSec, floatDeg);
   
}


void GetLon(char *dest, const char *sou){
    
    char strDD[5], strMM[10], strSS[10]; //space for each int
    float floatSS, floatDeg, floatDD, floatMM;
    int intDD, intMM;
    
    strncpy(strDD, sou, 3); //save 2 places 11402.3003
    strncpy(strMM, sou + 3, 2); //save 4 places 11402.3003
    strncpy(strSS, sou + 5, 5); //save 9 places 11402.3003
   
    intDD = atoi(strDD); //convert to int
    intMM = atoi(strMM); //convert to int
    floatSS = atof(strSS); //convert to float
    floatDD = atof(strDD); //convert to float
    floatMM = atoi(strMM); //convert to float
    
    //math
    float floatSec = floatSS*60;
    floatDeg = floatDD + (floatMM / 60) + (floatSS / 3600);
    
    printf("\n\nLongitude: %d° %s' %2.2f\"\n%f", intDD, strMM, floatSec, floatDeg);
   
   
}
   
   

void GetDir(char *dest, const char *sou){
    char strDeg[5];
    
    strncpy(strDeg, sou, 3);  
    printf(" %s", strDeg);
    
}

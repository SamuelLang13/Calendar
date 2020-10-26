#include <stdio.h>

int main() {

    int year;
    int leapYear;
    scanf("%d",&year);

    if(year%4000!=0 && year%4==0 && (( year % 100 != 0 || year % 400 == 0 )))
    {
        //Prestupny
        leapYear=1;
        printf("0");
    }
    else
    {
        //Neprestupny
        leapYear=0;
        printf("1");
    }
    return 0;
}

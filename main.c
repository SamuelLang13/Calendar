#ifndef __PROGTEST__
#include <stdio.h>
#include <assert.h>
#endif /* __PROGTEST__ */

int dateToIndex(int day, int month, int year, int *idx)
{
    int leapYear=1;
    int passedDays=0;
    //Kontrola vstupu
    if((year<2000)|| (month<1 || month>12)||(day<1 || day>31))
    {
        return 0;
    }
    if(day==1 && month==1)
    {
        *idx=1;
        return 1;
    }
    if(year%4000!=0 && year%4==0 && (( year % 100 != 0 || year % 400 == 0 )))
    {
        //Prestupny
        leapYear=1;
        switch (month)
        {
            case 1:
            {
                *idx=day;
                break;


            }
            case 2:
            {
                if(day>29)
                {
                    return 0;
                }
                *idx=day+31;
                break;
            }
            case 3:
            {
                *idx=day+31+29;
                break;
            }
            case 4:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+29+31;
                break;
            }
            case 5:
            {
                *idx=day+31+29+31+30;
                break;
            }
            case 6:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+29+31+30+31;
                break;

            }
            case 7:
            {
                *idx=day+31+29+31+30+31+30;
                break;

            }
            case 8:
            {
                *idx=day+31+29+31+30+31+30+31;
                break;

            }
            case 9:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+29+31+30+31+30+31+31;
                break;

            }
            case 10:
            {
                *idx=day+31+29+31+30+31+30+31+31+30;
                break;
            }
            case 11:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+29+31+30+31+30+31+31+30+31;
                break;

            }
            case 12:
            {
                *idx=day+31+29+31+30+31+30+31+31+30+31;
                break;
            }

        }
    }
    else
    {
        //Neprestupny
        leapYear=0;
        if(day==29 && month==2)
        {
            return 0;
        }
        switch (month)
        {
            case 1:
            {
                *idx=day;
                break;


            }
            case 2:
            {
                if(day>28)
                {
                    return 0;
                }
                *idx=day+31;
                break;
            }
            case 3:
            {
                *idx=day+31+28;
                break;
            }
            case 4:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+28+31;
                break;
            }
            case 5:
            {
                *idx=day+31+28+31+30;
                break;
            }
            case 6:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+28+31+30+31;
                break;

            }
            case 7:
            {
                *idx=day+31+28+31+30+31+30;
                break;

            }
            case 8:
            {
                *idx=day+31+28+31+30+31+30+31;
                break;

            }
            case 9:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+28+31+30+31+30+31+31;
                break;

            }
            case 10:
            {
                *idx=day+31+28+31+30+31+30+31+31+30;
                break;
            }
            case 11:
            {
                if(day>30)
                {
                    return 0;
                }
                *idx=day+31+28+31+30+31+30+31+31+30+31;
                break;

            }
            case 12:
            {
                *idx=day+31+28+31+30+31+30+31+31+30+31;
                break;
            }

        }
    }

}

#ifndef __PROGTEST__
int main (int argc, char * argv []) {
    int idx;
    assert(dateToIndex( 1,  1, 2000, &idx) == 1 && idx == 1);
    assert(dateToIndex( 1,  2, 2000, &idx) == 1 && idx == 32);
    assert(dateToIndex(29,  2, 2000, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 2001, &idx) == 0);
    assert(dateToIndex( 1, 12, 2000, &idx) == 1 && idx == 336);
    assert(dateToIndex(31, 12, 2000, &idx) == 1 && idx == 366);
    assert(dateToIndex( 1,  1, 1999, &idx) == 0);
    assert(dateToIndex( 6,  7, 3600, &idx) == 1 && idx == 188);
    assert(dateToIndex(29,  2, 3600, &idx) == 1 && idx == 60);
    assert(dateToIndex(29,  2, 4000, &idx) == 0);
    return 0;
}
#endif /* __PROGTEST__ */

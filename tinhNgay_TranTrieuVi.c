#include <stdio.h>
#include <stdint.h>

#define true 1
#define false 0

typedef uint8_t bool ;

typedef enum dayOFweek
{
    SATURDAY = 0,
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
} dayOFweek;

typedef enum month
{
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
}month;

typedef struct time
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
}time;

static const time org_time = {1,1,1};
static const dayOFweek org_dayOFweek = 2;

bool leapYear_check(time input_Time)
{
    if((input_Time.year % 400 == 0) || (input_Time.year % 100 != 0 && input_Time.year % 4 == 0))
    {
        return true;
    }
    return false;
}

uint8_t num_dayOFmonth(time temp_Time)
{
    uint8_t dayOFmonth = 0;

    switch (temp_Time.month)
    {
    case FEBRUARY:
        if(leapYear_check(temp_Time) == 1)
        {
            dayOFmonth = 29;
        }
        else dayOFmonth = 28;
        break;
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        dayOFmonth = 30;
        break;
    default:
        dayOFmonth = 31;
        break;
    }
    return dayOFmonth;
}

uint32_t Calc_day(time input_Time)
{
    time temp_Time = org_time;
    uint32_t num_day = 0;
    int m = 0;
    int n = 0;
    for(temp_Time.year = org_time.year; temp_Time.year < input_Time.year; temp_Time.year++)
    {
        if(leapYear_check(temp_Time) == 1)
        {
            num_day += 366;
        } 
        else num_day += 365;    
    }
    for(temp_Time.month = org_time.month; temp_Time.month < input_Time.month; temp_Time.month++)
    {
        num_day += num_dayOFmonth(temp_Time);
    }
    num_day += input_Time.day - org_time.day;
    return num_day;
}
bool check_date(time input_Time)
{
    if(input_Time.year < 1) return false;
    if(input_Time.month < 1 || input_Time.month > 12) return false;

    switch (input_Time.month)
    {
        case FEBRUARY:
            if(leapYear_check(input_Time))
            {
                if(input_Time.day < 1 || input_Time.day > 29) return false;
            }
            else
            {
                if(input_Time.day < 1 || input_Time.day > 28) return false;
            }
            break;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            if(input_Time.day < 1 || input_Time.day > 30) return false;
        default:
            if(input_Time.day < 1 || input_Time.day > 31) return false;
            break;
    }
    return true;
}
void enter_date(time *input_Time)
{
    while (true)
    {
        printf("Enter day:");
        scanf("%d",(int *)(&input_Time->day));
        printf("Enter month:");
        scanf("%d",(int *)(&input_Time->month));
        printf("Enter year:");
        scanf("%d",(int *)(&input_Time->year));
        if(check_date(*input_Time)) break;
        printf("Wrong date!!! Enter again!\n");
    } 
}
dayOFweek calc_dayOFweek(time input_Time)
{
    return ((Calc_day(input_Time) + org_dayOFweek)%7);
}
void show(time input_Time)
{
    switch (calc_dayOFweek(input_Time))
    {
        case MONDAY:
        {
            printf("MONDAY");
            break;
        }
        case TUESDAY:
        {
            printf("TUESDAY");
            break;
        }
        case WEDNESDAY:
        {
            printf("WEDNESDAY");
            break;
        }
        case THURSDAY:
        {
            printf("THURSDAY");
            break;
        } 
        case FRIDAY:
        {
            printf("FRIDAY");
            break;
        }
        case SATURDAY:
        {
            printf("SATURDAY");
            break;
        }
        case SUNDAY:
        {
            printf("SUNDAY");
            break;
        }     
    }
}
int main(void)
{
    time input_time;
    enter_date(&input_time);
    show(input_time);
    return 0;
}
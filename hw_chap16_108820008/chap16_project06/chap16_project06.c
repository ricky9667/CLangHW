#include<stdio.h>

struct date{
    int month, day, year;
};

int compare_dates(struct date d1, struct date d2)
{
    // return -1 if d1 is earlier, else return 1
    if(d1.year != d2.year)
        return (d1.year < d2.year) ? -1 : 1;
    if(d1.month != d2.month)
        return (d1.month < d2.month) ? -1 : 1;
    if(d1.day != d2.day)
        return (d1.day < d2.day) ? -1 : 1;
    return 0;
}

void put_date(struct date d)
{ 
    // print date
    printf("%d/%d/%.2d", d.month, d.day, d.year);
}

int main()
{
    struct date d1, d2;

    // input
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    // compare and output
    if(compare_dates(d1, d2) < 0)
    {
        put_date(d1);
        printf(" is earlier than ");
        put_date(d2);
        puts("");
    }
    else
    {
        put_date(d2);
        printf(" is earlier than ");
        put_date(d1);
        puts("");
    }
    return 0;
}
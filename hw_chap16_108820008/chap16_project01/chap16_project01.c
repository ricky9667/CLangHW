#include<stdio.h>
#define LEN(x) ((int) (sizeof(x)) / sizeof(x[0])) 

// define and save country information
const struct {
    char str[100];
    int ccode;
} country_codes[] = 
    {{"Argentina",            54}, {"Bangladesh",     889},
     {"Brazil",               55}, {"Burma (Myanmar)", 95},
     {"China",                86}, {"Columbia",        57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
     {"Ethiopia",            251}, {"France",          33},
     {"Germany",              49}, {"India",           91},
     {"Indonesia",            62}, {"Iran",            98},
     {"Italy",                39}, {"Japan",           81},
     {"Mexico",               52}, {"Nigeria",        234},
     {"Pakistan",             92}, {"Philippines",     63}, 
     {"Poland",               48}, {"Russia",           7},
     {"South Africa",         27}, {"South Korea",     82},
     {"Spain",                34}, {"Sudan",          249},
     {"Thailand",             66}, {"Turkey",          90}, 
     {"Ukraine",             380}, {"United Kingdom",  44},
     {"United States",         1}, {"Vietnam",         84}};

int main()
{
    int i, code;
    int size = LEN(country_codes); // get the size of country codes

    // input
    printf("Enter an international dialing code: ");
    scanf("%d", &code);

    // find country and output
    for(i=0;i<size;i++)
    {
        if(code == country_codes[i].ccode)
        {
            printf("%d is the code for %s.\n", country_codes[i].ccode, country_codes[i].str);
            return 0;
        }
    }
    // notify an error if there is no country related
    printf("Error: %d is not a valid country code.\n", code);
    
    return 0;
}
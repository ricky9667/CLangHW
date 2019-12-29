#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define PART_MAX 100
int num_parts=0;

struct part {
    int num, on_hand;
    char name[NAME_LEN+1];
    float price;
} inventory[PART_MAX];

// find an object if it exists
int find_part(int num)
{
    int i;
    for(i=0;i<num_parts;i++)
        if(inventory[i].num == num)
            return i;
    return -1;
}

// insert an object to the list
void insert()
{
    int part_num;
    if(num_parts == PART_MAX)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &part_num);
    if(find_part(part_num) >= 0)
    {
        printf("Part already exists.\n");
        return;
    }

    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter price: ");
    scanf("%f", &inventory[num_parts].price);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    inventory[num_parts++].num = part_num;
}

// get a part number of an object
void search()
{
    int i, num;

    printf("Enter part number: ");
    scanf("%d", &num);
    i = find_part(num);

    if(i >= 0)
    {
        printf("Part name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else printf("Part not found.\n");
}

// change the price of an object
void change()
{
    int i, num;
    float new_price;
    
    printf("Enter part number: ");
    scanf("%d", &num);
    i = find_part(num);

    if(i >= 0)
    {
        printf("Enter new price: ");
        scanf("%f", &new_price);
    }
    else printf("Part not found.\n");
}

// change the quantity of an object
void update()
{
    int i, num, change;

    printf("Enter part number: ");
    scanf("%d", &num);
    i = find_part(num);
    
    if(i >= 0)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
    }
    else printf("Part not found.\n");
}

// print the list of objects
void print()
{
    int i;

    printf("Part number \t Part name \t\t "
                "Price \t\t Quantity on Hand\n");
    for(i=0;i<num_parts;i++)
        printf("%7d          %-25s $%2.2f     %9d\n", 
            inventory[i].num, inventory[i].name,inventory[i].price, inventory[i].on_hand);
}

int main()
{
    char code;

    for(;;)
    {
        // input
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n');

        // execute the input function
        switch(code)
        {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'c': change(); break;
            case 'u': update(); break;
            case 'p': print();  break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        puts("");
    }
    return 0;
}
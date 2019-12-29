#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define LEN 25

struct part {
    int num, on_hand;
    char name[LEN+3];
    struct part *next;
} *inventory = NULL;

int read_line(char str[], int n)
{
    int i=0, ch;
    while(isspace(ch = getchar()));
    while(ch != '\n' && ch != EOF)
    {
        if(i<n) str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

// find an object if it exists
struct part *find_part(int num)
{
    struct part *p;
    for(p=inventory;
        p!=NULL && num > p->num;
        p=p->next);

    if(p!=NULL && num == p->num)
        return p;
    return NULL;
}

// insert an object to the list
void insert()
{
    struct part *cur, *prev, *new_node;

    new_node = malloc(sizeof(struct part));
    if(new_node == NULL) 
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf("%d", &new_node->num);

    for(cur = inventory, prev = NULL;
        cur != NULL && new_node->num > cur->num;
        prev = cur, cur = cur->next);

    if(cur != NULL && new_node->num == cur->num)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    
    new_node->next = cur;
    if(prev == NULL)
        inventory = new_node;
    else 
        prev->next = new_node;
}

// erase an object from the list
void erase()
{
    int n;
    struct part *prev, *cur;

    printf("Enter part number: ");
    scanf("%d", &n);

    for(cur = inventory;
        cur->num != n;
        prev = cur, cur = cur->next);

    if(cur != NULL)
    {
        if(cur->num == inventory->num)
            inventory = inventory->next;
        else 
            prev->next = cur->next;
        free(cur);
    }    
    else printf("Part number %d not found in database\n", n);
}

// get the part number of an object
void search()
{
    int num;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &num);
    
    p = find_part(num);
    if(p != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    }
    else printf("Part not found.\n");
}

// change the quantity of an object
void update()
{
    int num, change;
    struct part *p;

    printf("Enter part number: ");
    scanf("%d", &num);
    p = find_part(num);

    if(p != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand = change;
    }
    else printf("Part not found.\n");
}

// print the list of objects
void print()
{
    struct part *p;

    printf("Part Number   Part Name"
           "\t\t\tQuantity on Hand\n");
    for(p = inventory;p != NULL;p = p->next)
        printf("%7d       %-25s%11d\n", p->num, p->name, p->on_hand);
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
            case 'e': erase();  break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'p': print();  break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        puts("");
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_WORDS 50
#define WORD_LEN 20

int read_line(char str[], int n)
{
    int ch, i=0;
    while((ch = getchar()) != '\n')
        if(i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

// get the mid value of an array
char **split(char **low, char **high)
{
    char *part_element = *low;
    for(;;)
    {
        while(low < high && strcmp(part_element, *high) <= 0)
           high--;
        if(low >= high)
            break;
        *low++ = *high;

        while(low < high && strcmp(*low, part_element) <= 0)
            low++;
        if(low >= high)
            break;
        *high-- = *low;
    }

    *high = part_element;
    return high;
}

void quicksort(char **low, char **high)
{
    if(low >= high) return;

    /* gets the middle number of the array and 
    classify numbers that are larger or smaller tham a[mid] */
    char **mid = split(low, high);

    // sort the rest by using divide and conquer
    quicksort(low, mid-1);
    quicksort(mid+1, high);
}

int main()
{
    char *words[MAX_WORDS], word[WORD_LEN+1];
    int i, num_words = 0;

    for(;;)
    {
        if(num_words >= MAX_WORDS)
        {
            printf(" -- No space left --\n");
            break;
        }

        // input
        printf("Enter word: ");
        read_line(word, WORD_LEN);
        if(!strlen(word))
            break;

        // assign new space to words
        words[num_words] = (char *)malloc(strlen(word)+1); 
        if(words[num_words] == NULL)
        {
            printf(" -- No space left --\n");
            break;
        }
        
        // copy the input to words
        strcpy(words[num_words++], word);
    }

    // sort the strings
    quicksort(words, words+(num_words-1));

    // output
    printf("\nIn sorted order: ");
    for(i=0;i<num_words;i++)
        printf(" %s", words[i]);
    puts("");

    return 0;
}
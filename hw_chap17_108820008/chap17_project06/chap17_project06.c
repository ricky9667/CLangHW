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

int compare_strings(const void *p, const void *q)
{
    return strcmp(*(char **)p, *(char **)q);
}

int main()
{
    char *words[MAX_WORDS], word[WORD_LEN];
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
    qsort(words, num_words, sizeof(char *), compare_strings);

    // output
    printf("\nIn sorted order: ");
    for(i=0;i<num_words;i++)
        printf(" %s", words[i]);
    puts("");
    
    return 0;
}
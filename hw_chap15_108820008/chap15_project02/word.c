#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch = getchar();
    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len)
{
    const int max_len = len-1;
    int ch, pos = 0;
    while ((ch = read_char()) == ' ');
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        if(pos > max_len)
            word[max_len] = '*';
        ch = read_char();
    }
    word[pos] = '\0';
}
/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 胡紹宇                                                */
/* ID: 108820008                                                 */
/* Date: 2019.12.23                                              */
/* Purpose:                                                      */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include <string.h>
#include "line.h"
#include "word.h"
#define MAX_WORD_LEN 20

int main(int argc, char *argv[]) 
{
    char word[MAX_WORD_LEN + 2];
    int word_len;
    clear_line();

    for(;;)
    {
        read_word(word, MAX_WORD_LEN + 1); // input word
        word_len = strlen(word); // get string length
        if (word_len == 0) {
            flush_line(); // exit
            return 0;
        }
        // if (word_len > MAX_WORD_LEN)
        //     word[MAX_WORD_LEN] = '*';
        if (word_len+1 > space_remaining()) 
        {
            write_line(); // put word to string
            clear_line(); // clear word
        }
        add_word(word); // put the word to string array
    }
    return 0;
}
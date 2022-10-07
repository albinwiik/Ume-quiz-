
#ifndef __QUESTION_H
#define __QUESTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *question;
    int correct_answer;
    char *alternative_1, *alternative_2, *alternative_3, *alternative_4;
} Question_t;

Question_t *create_new_question(char *quesiton, int correct_answer,  char *a1, char *a2, char *a3, char *a4);
int destroy_question(Question_t *question);

int ask_question(Question_t *question);
void print_question(Question_t *question);
int read_answer(int lo, int hi);
void str_allocate_copy(char *dest, char *source);


#endif
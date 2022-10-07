#ifndef __QUESTION_LIST_H
#define __QUESTION_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "question.h"

#define MAX_NUMBER_QUESTIONS 100

typedef struct
{
    Question_t **questions;
    int lenght;
} Question_list_t;

Question_list_t *create_question_list();
int destroy_question_list(Question_list_t *question_list);

void question_list_add(Question_list_t *question_list, Question_t *question);
Question_t *question_list_get_quesiton(Question_list_t *question_list, int index);
int question_list_get_length(Question_list_t *question_list);

#endif
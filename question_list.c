#include "question_list.h"

Question_list_t *create_question_list()
{
    Question_list_t *question_list = malloc(sizeof(Question_list_t) * 1);
    question_list->questions = malloc(sizeof(Question_t*) * MAX_NUMBER_QUESTIONS);
    question_list->lenght = 0;

    return question_list;
}

int destroy_question_list(Question_list_t *question_list)
{
    if(question_list == NULL) {
        return 0;
    }
    else {
        for(int i = 0; i < question_list->lenght; i++) {
            destroy_question(question_list->questions[i]);
        }
        free(question_list);
        question_list = NULL;
        return 1;
    }
}

void question_list_add(Question_list_t *question_list, Question_t *new_question)
{
    
    int index = question_list->lenght;
    question_list->questions[index] = new_question;
    question_list->lenght++;
}

Question_t *question_list_get_quesiton(Question_list_t *question_list, int index)
{
    return question_list->questions[index];
}

int question_list_get_length(Question_list_t *question_list) {
    return question_list->lenght;
}






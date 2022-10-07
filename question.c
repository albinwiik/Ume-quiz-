#include "question.h"


Question_t *create_new_question(char *quesiton, int correct_answer, char *a1, char *a2, char *a3, char *a4)
{

    Question_t *q = malloc(sizeof(Question_t) * 1);

    if(q == NULL) {
        return NULL;
    }

    q->correct_answer = correct_answer;

    // Allokeringen och kopieringen borde ske i en hjälpfunktion.
    q->question = malloc(sizeof(char) * (strlen(quesiton) + 1));
    strcpy(q->question, quesiton);

    q->alternative_1 = malloc(sizeof(char) * (strlen(a1) + 1));
    strcpy(q->alternative_1, a1);

    q->alternative_2 = malloc(sizeof(char) * (strlen(a2) + 1));
    strcpy(q->alternative_2, a2);
    
    q->alternative_3 = malloc(sizeof(char) * (strlen(a3) + 1));
    strcpy(q->alternative_3, a3);

    q->alternative_4 = malloc(sizeof(char) * (strlen(a4) + 1));
    strcpy(q->alternative_4, a4);

    return q;
}

int destroy_question(Question_t *question)
{
    if (question == NULL) {
        return 0;
    }
    else {
        free(question->question);
        free(question->alternative_1);
        free(question->alternative_2);
        free(question->alternative_3);
        free(question->alternative_4);
        free(question);
        return 1;
    }
}

int ask_question(Question_t *question)
{

    int answer;

    print_question(question);

    answer = read_answer(1, 4);

    if(answer == question->correct_answer) {
        return 1;
    }
    else {
        return 0;
    }
}

void print_question(Question_t *question)
{
    printf("%s\n", question->question);
    printf("\t1. %s\n", question->alternative_1);
    printf("\t2. %s\n", question->alternative_2);
    printf("\t3. %s\n", question->alternative_3);
    printf("\t4. %s\n", question->alternative_4);
}

int read_answer(int lo, int hi)
{
    int num;

    do {
        printf("Ditt svar: ");
        scanf("%d", &num);
        fflush(stdin);

        if(num < lo || num > hi) {
            printf("Svaret måste ligga i intervallet [%d - %d]\n", lo, hi);
        } 

    } while(num < lo || num > hi);

    return num;
}




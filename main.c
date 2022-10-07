
#include "question.h"
#include "question_list.h"

#include <stdio.h>

void print_instructions(void);
void print_result(int points, int number_of_questions);
void populate_question_list(Question_list_t *question_list);

int main(void)
{
    int points;
    Question_t *current_question;
    Question_list_t *question_list;
    int number_of_questions;
    int question_result;

    points = 0;
    question_list = create_question_list();
    populate_question_list(question_list);
    number_of_questions = question_list_get_length(question_list);

    print_instructions();

    for(int i = 0; i < number_of_questions; i++) {
        current_question = question_list_get_quesiton(question_list, i);
        question_result = ask_question(current_question);
        points += question_result;
    }

    print_result(points, number_of_questions);

    destroy_question_list(question_list);
    question_list = NULL;

    return 0;
}

void print_instructions(void)
{
    printf("================================================\n");
    printf("En frågesport om Umeå för att fira Umeå 400 år.\n");
    printf("================================================\n\n");
    printf("Tryck Enter för att fortsätta...");

    scanf("d");
    fflush(stdin);          

    printf("\n");
}

void print_result(int points, int number_of_quesitons)
{
    printf("======================\n");
    printf("Du fick %d / %d rätt!\n", points, number_of_quesitons);
    printf("======================\n");
}

// Lägg till frågor här!
void populate_question_list(Question_list_t *question_list)
{
    question_list_add(question_list, create_new_question("Hur många invånare har Umeå?", 4, 
                                                        "40000", "100000", "76000", "89000"));

    question_list_add(question_list, create_new_question("Vilket år grundades umeå?", 3, 
                                                        "1846", "1571", "1622", "1732"));

    question_list_add(question_list, create_new_question("Vilket år bränndes Umeå ner av Ryssarna?", 3,
                                                        "1814", "1798", "1714", "1692"));
    

}


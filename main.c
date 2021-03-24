#include <stdio.h>
#include <stdlib.h>
#include "structure-header.h"

List LIST;

int menu(){
    int option;

    printf("\n  ### Options Menu ###");
    printf("\n  | 1 - Create a List");
    printf("\n  | 2 - Insert");
    printf("\n  | 3 - Remove");
    printf("\n  | 4 - Consult by Name");
    printf("\n  | 5 - Consult by Position");
    printf("\n  | 6 - Quantity on List");
    printf("\n  | 7 - Show List");
    printf("\n  | 8 - Update List");
    printf("\n  | 9 - Exit");
    printf("\n  ### Your Choice > ");
    scanf("%d",&option);

    if(option < 1 || option > 9){
        printf("\n\n   ### Wrong Choice ###\n\n");
        return(menu());
    }
    else
        return (option);

}

void handleOption(int option){
    People people;
    int position, quantity;

    switch(option){

        case 1: createList(&LIST);
                printf("\n\n  ### New List Created! ###\n\n");
                break;

        case 2: printf("\n\n  # Enter the person's data > \n");

                fflush(stdin);

                printf("\n  | Name: ");
                gets(people.name);

                printf("\n  | Birth Day: ");
                scanf("%d",&(people.birthDate.day));

                printf("\n  | Birth Month: ");
                scanf("%d",&(people.birthDate.month));

                printf("\n  | Birth Year: ");
                scanf("%d",&(people.birthDate.year));

                printf("\n  | Identity Document: ");
                scanf("%d",&(people.id));

                fflush(stdin);

                printf("\n  | Profession: ");
                gets(people.profession);

                printf("\n  | Salary: ");
                scanf("%f", &people.salary);

                insertList(&LIST, people);

                printf("\n\n  ### Inserted Person ###\n\n");

                break;

        case 3: if (emptyList(LIST))
                    printf("\n\n  ### Empty List! ###\n\n");
                else
                {
                    printf("\n\n  # Enter the person's name to remove > \n");
                    printf("\n  | Name: ");
                    fflush(stdin);
                    gets(people.name);
                    if (removeList(&LIST, &people))
                    {
                        printf("\n  ### Person Removed: \n");
                        printf("\n  | Name: %s",people.name);
                        printf("\n  | Birth Day: %d", people.birthDate.day);
                        printf("\n  | Birth Month: %d", people.birthDate.month);
                        printf("\n  | Birth Year: %d", people.birthDate.year);
                        printf("\n  | Identity Document: %d", people.id);
                        printf("\n  | Profession: %s", people.profession);
                        printf("\n  | Salary: %.2f\n\n", people.salary);
                    }
                    else printf("\n\n ### Person not registed ###!\n\n");
                }
                break;
        case 4: if (emptyList(LIST))
                    printf("\n\n  ### Empty List! Person not consulted! ###\n");
                else
                {
                    printf("\n  # Enter the person's name to consult > \n");
                    printf("\n  | Name: ");
                    fflush(stdin);
                    gets(people.name);
                    if (consultName(LIST,&people))
                    {
                        printf("\n  ### Person Consulted: \n");
                        printf("\n  | Name: %s",people.name);
                        printf("\n  | Birth Day: %d", people.birthDate.day);
                        printf("\n  | Birth Month: %d", people.birthDate.month);
                        printf("\n  | Birth Year: %d", people.birthDate.year);
                        printf("\n  | Identity Document: %d", people.id);
                        printf("\n  | Profession: %s", people.profession);
                        printf("\n  | Salary: %.2f\n\n", people.salary);
                    }
                    else printf("\n\n ### Person not registed ###!\n\n");
                }
                break;

        case 5: if (emptyList(LIST))
                    printf("\n\n  ### Empty List! Person not consulted! ###\n");
                else
                {
                    printf("\n\n  # Enter the position of the person to be consulted > \n");
                    printf("\n  | Position: ");
                    scanf("%d", &position);
                    if (consultPosition(LIST,position,&people))
                    {
                        printf("\n  ### Person Consulted: \n");
                        printf("\n  | Position: %d", position);
                        printf("\n  | Name: %s",people.name);
                        printf("\n  | Birth Day: %d", people.birthDate.day);
                        printf("\n  | Birth Month: %d", people.birthDate.month);
                        printf("\n  | Birth Year: %d", people.birthDate.year);
                        printf("\n  | Identity Document: %d", people.id);
                        printf("\n  | Profession: %s", people.profession);
                        printf("\n  | Salary: %.2f\n\n", people.salary);
                    }
                    else printf("\n ### Non-existent Position! ###");
                }
                break;

        case 6: printf("\n\n  # Amount of people on the list = %d\n\n", quantityList(LIST));
                break;

        case 7: if (emptyList(LIST))
                    printf("\n\n  ### Empty List! ###\n\n");
                else
                {
                    printf("\n\n  ### List Elements:\n");
                    quantity = quantityList(LIST);
                    for (position=1; position<=quantity; position++)
                    {
                        consultPosition(LIST,position,&people);
                        printf("\n  ### Person No %d:", position);
                        printf("\n  | Name: %s",people.name);
                        printf("\n  | Birth Day: %d", people.birthDate.day);
                        printf("\n  | Birth Month: %d", people.birthDate.month);
                        printf("\n  | Birth Year: %d", people.birthDate.year);
                        printf("\n  | Identity Document: %d", people.id);
                        printf("\n  | Profession: %s", people.profession);
                        printf("\n  | Salary: %.2f\n\n", people.salary);

                    }
                }
                break;

        case 8: if (emptyList(LIST))
                    printf("\n\n  ### Empty List! ###\n\n");
                else{
                    printf("\n\n  # Enter the person's name to update his register > \n");
                    printf("\n  | Name: ");
                    fflush(stdin);
                    gets(people.name);

                    if(consultName(LIST, &people)){
                        printf("\n  | Birth Day: ");
                        scanf("%d",&(people.birthDate.day));

                        printf("\n  | Birth Month: ");
                        scanf("%d",&(people.birthDate.month));

                        printf("\n  | Birth Year: ");
                        scanf("%d",&(people.birthDate.year));

                        printf("\n  | Identity Document: ");
                        scanf("%d",&(people.id));

                        fflush(stdin);

                        printf("\n  | Profession: ");
                        gets(people.profession);

                        printf("\n  | Salary: ");
                        scanf("%f", &people.salary);

                        updateList(&LIST, &people);

                        printf("\n\n  ### Register updated successfully!\n\n");
                        fflush(stdin);
                    }
                    else
                        printf("\n\n  ### Register not found!\n\n");
                }
                break;
        }
}

void main() {
    int option;

    printf("\n");
    printf("\n***********************************");
    printf("\n**         Basic App of a        **");
    printf("\n**       Ordered and Chained     **");
    printf("\n**          Dynamic List         **");
    printf("\n***********************************");
    printf("\n");

    do{
        option = menu();
        handleOption(option);
    } while (option != 9);
}
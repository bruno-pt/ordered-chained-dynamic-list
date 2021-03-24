#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define maxName 75


typedef struct BirthDate{
    int day, month, year;
} BirthDate;


typedef struct People{
    char name[maxName];
    BirthDate birthDate;
    int id;
    char profession[maxName];
    float salary;
} People;


typedef struct Element{
    People people;
    struct Element *next;
} Element;


typedef Element *elementPointer;


typedef struct List{
    elementPointer list;
    int quantity;
} List;

void createList(List *list);
int emptyList(List list);
int quantityList(List list);
int searchList(List list, char name[], elementPointer *previousElement);
int insertList(List *list, People people);
int consultName(List list, People *people);
int consultPosition(List list, int pos, People *people);
int removeList(List *list, People *people);
int updateList(List *list, People *people);

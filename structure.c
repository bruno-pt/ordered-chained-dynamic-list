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


void createList(List *list){
    list -> quantity = 0;
    list -> list = NULL;
}


int emptyList(List list){
    if(list.quantity == 0)
        return(true);
    else
        return(false);
}


int quantityList(List list){
    return(list.quantity);
}


int searchList(List list, char name[], elementPointer *previousElement){
    elementPointer nextElement;
    int hasMore;

    *previousElement = NULL;

    if(emptyList(list))
        return(false); //if list is empty, return false;
    else{
        nextElement = list.list;

        if(nextElement->next!=NULL) //if next isn't NULL, the list has more elements!
            hasMore = true;
        else
            hasMore = false;
        
        while(strcmp(nextElement->people.name, name) == -1 && hasMore){
            *previousElement = nextElement;
            nextElement = nextElement->next;

            if(nextElement->next!=NULL) //if next isn't NULL, the list has more elements!
                hasMore = true;
            else
                hasMore = false;
        }

        if(strcmp(nextElement->people.name, name) == 0)
            return (true); //find the element
        else if(strcmp(nextElement->people.name, name) == +1)
                return(false); //didn't find the element
        else{
            *previousElement = nextElement;
            return(false);
        }
    }
}


int insertList(List *list, People people){
    elementPointer previousElement, nextElement, aux;

    if(searchList(*list, people.name, &previousElement))
        return(false);

    else{
        aux = malloc(sizeof(Element));

        aux->people = people;

        if(previousElement == NULL){ //first element
            aux->next = list-> list;
            list-> list = aux;
        }
        else{
            nextElement = previousElement->next;
            aux->next = nextElement;
            previousElement->next = aux;
        }

        list->quantity++;
        return(true); 
    }
}


int consultName(List list, People *people){
    elementPointer previousElement, nextElement;

    if(emptyList(list))
        return(false);
    else{

        if(searchList(list, people->name, &previousElement)){
            if(previousElement == NULL)
                *people = list.list->people; //first element
            else{
                nextElement = previousElement->next;
                *people = nextElement->people;
            }
            return(true);
        }
        else
            return(false);
    }
}


int consultPosition(List list, int pos, People *people){
    int count;
    elementPointer aux;

    if(emptyList(list) || (pos>list.quantity))
        return(false);
    else{
        count = 1;
        aux = list.list;

        while(count<pos){
            count++;
            aux = aux->next;
        }

        *people = aux->people;
        return (true);
    }
}


int removeList(List *list, People *people){
    elementPointer previousElement, nextElement;

    if(emptyList(*list))
        return(0);
    else{
        if(searchList(*list, people->name, &previousElement)){
            if(previousElement == NULL){
                nextElement = list->list;
                *people = nextElement->people;
                list-> list = nextElement->next;
            }
            else{
                nextElement = previousElement->next;
                *people = nextElement->people;
                previousElement->next = nextElement->next;
            }

            free(nextElement);
            list->quantity--;
            return(true);
        }
        else
            return(false);
    }
}


void updateList(List *list, People *people){
    People *aux = malloc(sizeof(*aux));

    strcpy(aux->name, people->name);
    aux->birthDate.day = people->birthDate.day;
    aux->birthDate.month = people->birthDate.month;
    aux->birthDate.year = people->birthDate.year;
    aux->id = people->id;
    strcpy(aux->profession, people->profession);
    aux->salary = people->salary;

    removeList(list, people);
    insertList(list, *aux);

    free(aux);
}
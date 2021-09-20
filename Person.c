#include <stdio.h>
#include <string.h>
#include "Person.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
}

void init_SAL(PersonStaticArrayList *list){
    PersonStaticArrayList PList = *list;
}

void insert_first_SAL(PersonStaticArrayList *list, Person p){
	if(MAX_LIST > *list->count){
        int i;
		for(i = *list->count-1; i >= 0; i--){
			*list->data[i+1] = *list->data[i];
		}
		*list->data[0] = p;
	}
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
    if(MAX_LIST > *list->count){
        *list->data[*list->count] = p;
    }
}

void insert_at_SAL(PersonStaticArrayList *list, Person p, int index){
    if(MAX_LIST > *list->count){
        int i;
        for(i = MAX_LIST - 1 ; i >= 0; i--){
            if(i >= index){
                *list->data[i] = *list->data[i - 1];
            }
        }
        *list->data[index] = p;
    }
}

void delete_first_SAL(PersonStaticArrayList *list){
    if(*list->count > 0){
        int i;
        for(i = 0; i < *list->count; i++){
            *list->data[i] = *list->data[i + 1];
        }
    }
}

void delete_last_SAL(PersonStaticArrayList *list){
    if(*list->count > 1){
        *list->data[*list->count - 1] = NULL;
    }
}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){
    if(*list->count > 0){
        int i, j;
        for(i = 0;i < *list->count; i++){

            if(*list->data[i].sex == sex){

                for(j = i; j < *list->count; j++){
                    *list->data[j]  = *list->data[j + 1];
                }
            }
        }
    }
}

void display_SAL(PersonStaticArrayList list){
    if(*list->count > 0){
        for(i = 0;i < *list->count; i++){
            printf("%s, %c, %s\n", *list->data[i].name, *list->data[i].sex, *list->data[i].city);
        }
    }
}

void init_DAL(PersonDynamicArrayList *list){
    PersonDynamicArrayList PDList = *list;
}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
    if(*list->max > *list->count){
        int i;
		for(i = *list->count-1; i >= 0; i--){
			*list->data->prsn[i+1] = *list->data->prsn[i];
		}
		*list->data->prsn[0] = p;

        if(*list->count == *list->max){
            *list->max*2;
        }
	}
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){
    if(*list->max > *list->count){
        *list->data->prsn[*list->count] = p;

        if(*list->count == *list->max){
            *list->max*2;
        }
    }
}

void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
    if(*list->max > *list->count){
        int i;
        for(i = *list->max - 1 ; i >= 0; i--){
            if(i >= index){
                *list->data->prsn[i] = *list->data->prsn[i - 1];
            }
        }
        *list->data->prsn[index] = p;

        if(*list->count == *list->max){
            *list->max*2;
        }
    }
}

void delete_first_DAL(PersonDynamicArrayList *list){
    if(*list->count > 0){
        int i;
        for(i = 0; i < *list->count; i++){
            *list->data->prsn[i] = *list->data->prsn[i + 1];
        }
    }
}

void delete_last_DAL(PersonDynamicArrayList *list){
    if(*list->count > 1){
        *list->data->prsn[*list->count - 1] = NULL;
    }
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){
    if(*list->count > 0){
        int i, j;
        for(i = 0;i < *list->count; i++){

            if(*list->data->prsn[i].city == city){

                for(j = i; j < *list->count; j++){
                    *list->data->prsn[j]  = *list->data->prsn[j + 1];
                }
            }
        }
    }
}

void display_DAL(PersonDynamicArrayList list){
    if(*list->count > 0){
        for(i = 0;i < *list->count; i++){
            printf("%s, %c, %s\n", *list->data->prsn[i].name, *list->data->prsn[i].sex, *list->data->prsn[i].city);
        }
    }
}

void init_DAL_2(PersonDynamicArrayList **list){
    PersonDynamicArrayList PList = (PersonDynamicArrayList*) malloc(sizeof(PersonDynamicArrayList));
    PersonDynamicArrayList *PListptr = &PList;
}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){
    if(*list->max > *list->count){
        int i;
		for(i = *list->count-1; i >= 0; i--){
			*list->data->prsn[i+1] = *list->data->prsn[i];
		}
		*list->data->prsn[0] = p;

        if(*list->count == *list->max){
            list = (PersonDynamicArrayList*) = realloc(list,*list->max*2);
        }
	}
}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){
    if(*list->max > *list->count){
        *list->data->prsn[*list->count] = p;

        if(*list->count == *list->max){
            list = (PersonDynamicArrayList*) = realloc(list,*list->max*2);
        }
    }
}

void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){
    if(*list->max > *list->count){
        int i;
        for(i = *list->max - 1 ; i >= 0; i--){
            if(i >= index){
                *list->data->prsn[i] = *list->data->prsn[i - 1];
            }
        }
        *list->data->prsn[index] = p;

        if(*list->count == *list->max){
            list = (PersonDynamicArrayList*) = realloc(list,*list->max*2);
        }
    }
}

void delete_first_DAL_2(PersonDynamicArrayList *list){
    if(*list->count > 0){
        int i;
        for(i = 0; i < *list->count; i++){
            *list->data->prsn[i] = *list->data->prsn[i + 1];
        }
    }
}

void delete_last_DAL_2(PersonDynamicArrayList *list){
    if(*list->count > 1){
        *list->data->prsn[*list->count - 1] = NULL;
    }
}

void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){
    if(*list->count > 0){
        int i, j;
        for(i = 0;i < *list->count; i++){

            if(*list->data->prsn[i].name == name){

                for(j = i; j < *list->count; j++){
                    *list->data->prsn[j]  = *list->data->prsn[j + 1];
                }
            }
        }
    }
}

void display_DAL_2(PersonDynamicArrayList list){
    if(*list->count > 0){
        for(i = 0;i < *list->count; i++){
            printf("%s, %c, %s\n", *list->data->prsn[i].name, *list->data->prsn[i].sex, *list->data->prsn[i].city);
        }
    }
}

void insert_first_LL(PersonLinkedList *list, Person p){
    PersonNode newNode;

    newNode = (PersonNode) malloc(sizeof(PersonNode));
    newNode->elem = p;
    newNode->next = *list; 
    *list = &newNode;
}

void insert_last_SAL(PersonStaticArrayList *list, Person p){
    PersonNode newNode;
    PersonLinkedList trav;

    newNode = (PersonNode) malloc(sizeof(PersonNode));
    newNode->elem = p;
    for(trav = list;trav->next != NULL;trav=trav->next){}
    trav->next = &newNode;
}

void insert_after_LL(PersonLinkedList *list, Person p, String name);{
    PersonNode newNode;
    PersonLinkedList trav;

    int i=0;

    newNode = (PersonNode) malloc(sizeof(PersonNode));
    newNode->elem = p;
    for(trav = list;trav->next != NULL && trav->elem.name != name; trav=trav->next){}
    if(trav->elem.name == name){
        newNode = trav->next;
        trav->next = &newNode;
    }
}

void delete_first_LL(PersonLinkedList *list){
    PersonLinkedList temp;

    temp = list;
    list = temp->next;
    free(temp);
}

void delete_last_LL(PersonLinkedList *list){
    PersonLinkedList trav;

    for(trav = list;trav->next != NULL;trav=trav->next){}
    free(trav);
}

void delete_by_city_LL(PersonLinkedList *list, String city){
    PersonLinkedList trav;

    for(trav = list;trav->next != NULL && trav->next->elem.city != city; trav=trav->next){}
    if(trav->elem.city == city){
        trav->next = trav->next->next;
        free(trav->next);
    }
}

void display_LL(PersonLinkedList list){
    PersonLinkedList trav;

    for(trav=list; trav->next != NULL; trav=trav->next){
        printf("%s, %c, %s\n", trav->elem.name, trav->elem.sex, trav->elem.city);
    }
}

void init_vspace(VSpace *vs){
    int i;
    for(i=MAX_VSPACE-1; i >= 0; --i){
        vs->data[i].next = i-1;
    }
    vs->avail = MAX_VSPACE - 1
}

Position alloc_space(VSpace *vs){
    Position avail = vs->avail;

    if(avail != -1){
        vs->avail = vs->data[avail].next
    }

    return avail;
}

void free_space(VSpace *vs, Position index){
    free(vs->data[index]);
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position temp = alloc_space(vs);

    if(temp != -1){
        vs->data[temp].elem = p;
        vs->data[temp].next = *list;
        *list = temp;
    }
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    Position temp = alloc_space(vs);
    int i;

    if(temp != -1){
        for(i=*list; vs->data[i].next != -1; i=vs->data[i].next){}
        vs->data[i].next = temp;
        vs->data[temp].elem = p;
    }
}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
    Position temp = alloc_space(vs);
    CNode newNode;

    if(temp != -1){
        newNode->data[temp] = vs->data[index];

        vs->data[index].elem = p;
        vs->data[index].next = temp;
    }
}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){
    CNode *temp;
    temp = vs->data[*list];
    free(data->elem[*list]);
    *list = temp.next;
    free(temp);
}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){
    int i;

    for(i=*list; vs->data[i].next != -1; i=vs->data[i].next){}
    if(vs->data[i].next == -1){
        free(vs->data[i]);
    }
}

void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){
    for(i=*list; vs->data[i].next != -1; i=vs->data[i].next){
        if(vs->data[i].elem.sex == sex){
            free(vs->data[i]);
        }
    }
}
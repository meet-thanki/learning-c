/*Today, I will be making 2 mini projects on Dynamic Memory Management with structs, the ultimate test
of the theory I have learnt over the past few days.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mini-project: Dynamic Contact Management System
/* I have used a lot of hints in making this project. The behaviour is very abstract, and I would need
more and more practice to get working without hints on intuition.*/

typedef struct{
    char name[20];
    char phone[15];
    int age;
} Contact;

typedef struct{
    Contact *items;
    int count;
    int capacity;
} ContactList;

void init_list(ContactList *list, int initial_capacity);
void add_contact(ContactList *list, const char *name, const char *phone, int age);
void free_list(ContactList *list);

int main(){
    ContactList list;

    init_list(&list, 2);
    add_contact(&list, "ABC", "9999", 17);
    add_contact(&list, "DEF", "9989", 17);
    add_contact(&list, "GHI", "9899", 17);
    add_contact(&list, "JKL", "9899", 17);
    add_contact(&list, "MNO", "9899", 17);
    add_contact(&list, "PQR", "9899", 17);

    printf("Saved Contacts: \n");
    for(int i = 0; i< list.count; i++){
        printf("\nContact %d:\n %s | %s | %d", i+1, list.items[i].name, list.items[i].phone, list.items[i].age);
    }

    free_list(&list);
    return 0;
}

void init_list(ContactList *list, int initial_capacity){
    list->count = 0;
    list->capacity = initial_capacity;
    list->items = (Contact*) calloc(initial_capacity, sizeof(Contact));
}

void add_contact(ContactList *list, const char *name, const char *phone, int age){
    if(list->count == list->capacity){
        int newCapacity = 2*list->capacity;
        Contact *temp = (Contact*)realloc(list->items, newCapacity*sizeof(Contact));

        if(temp == NULL){
            printf("Could not allocate more memory.\n");
        }
            list->items = temp;
            list->capacity = newCapacity;
            printf("Capacity resized to %d.\n", list->capacity);
        }
        strcpy(list->items[list->count].name, name);
        strcpy(list->items[list->count].phone, phone);
        list->items[list->count].age = age;

        list->count++;
}

void free_list(ContactList *list){
    free(list->items);
    list->items = NULL;
    list->count = 0;
    list->capacity = 0;
}
/*Today, I have used structs and dynamic memory management again to build an RPG game. These projects
are helping me to understand and remember these concepts permanently.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
// mini project: RPG game in which a character requests memory slots for inventory slots and buys items accordingly.

typedef struct{
    char item_name[20];
    int gold_value;
    int item_id;
} Item;

typedef struct{
    char name[20];
    int current_gold;
    int total_slots;
    int count;
    Item *bag;
} Character;

void init_player(Character *c1, const char *name, int current_gold, int total_slots);
void increase_capacity(Character *c1, int newCapacity);
void add_item(Character *c1, const char *item_name, int gold_value, int item_id);
void free_item(Character *c1);

int main(){
    Character c1;
    init_player(&c1, "MesitylOxide", 2000, 3);

    add_item(&c1, "Pickaxe", 2000, 123);
    add_item(&c1, "Axe", 1020, 234);
    add_item(&c1, "Sword", 700, 567);
    add_item(&c1, "Apple", 80, 891);

    printf("Items are as follows in the inventory:\n\n");
    for(int i = 0; i < c1.count; i++){
        printf("%s | Cost: %d | Item ID: %d\n", c1.bag[i].item_name, c1.bag[i].gold_value, c1.bag[i].item_id);
    }

    free_item(&c1);
    return 0;
}

void init_player(Character *c1, const char *name, int current_gold, int total_slots){
    strcpy(c1->name, name);
    c1->count = 0;
    c1->current_gold = current_gold;
    c1->total_slots = total_slots;
    c1->bag = (Item*) calloc(total_slots, sizeof(Item));
}

void increase_capacity(Character *c1, int newCapacity){
    c1->total_slots = c1->total_slots + newCapacity;
    Item *temp = (Item*) realloc(c1->bag, c1->total_slots*sizeof(Item));

    if(temp == NULL){
        printf("Memory reallocation failed.");
        return;
    }

    c1->bag = temp; // capacity has been updated.
    printf("Inventory increased to %d.\n", c1->total_slots);
}

void add_item(Character *c1, const char *item_name, int gold_value, int item_id){
    // check if the player has gold first
    if((c1->current_gold < gold_value)){ // here directly the functional parameter has been used for comparison. direct member access through pointer would give uninitialised data.
        printf("Insufficient funds. Cannot add item %s.\nRequired: %d | Has: %d\n", item_name, gold_value, c1->current_gold);
        return;
    }    
  
    // check if there is a slot in the inventory
    int ask;
    if(c1->count == c1->total_slots){
        printf("Maximum capacity reached inside your inventory.\n");
        printf("By how many slots would you like to increase your inventory? ");
        scanf("%d", &ask);
        
        if(ask == 0){
            printf("The allocation cannot be zero.");
            return;
        }
        increase_capacity(c1, ask);
    }

    // deduct gold
    c1->current_gold = c1->current_gold - gold_value;

    // store the item
    strcpy(c1->bag[c1->count].item_name, item_name);
    c1->bag[c1->count].gold_value = gold_value;
    c1->bag[c1->count].item_id = item_id;

    printf("The gold left with you is: %d after buying %s.\n", c1->current_gold, c1->bag[c1->count].item_name);

    c1->count++;
}

void free_item(Character *c1){
    free(c1->bag);
    c1->bag = NULL;
}
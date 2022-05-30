#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define TEST() printf("TEST\n")
#undef DEBUG

#define ANIMALS_TYPE_COUNT 4

#define NL() printf("\n")

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char code[5+1];
    Date bornDate;
    int race;
    float weight;
    Date sellingDate;
} Animal;

typedef struct {
    Animal *a;
    int size;
} Farm;

#define NEW_ITEM_PROMPT "Insert new registry item"
#define REMOVE_ITEM_PROMPT "Remove item from registry"
#define SEARCH_PROMPT "Search item by code"
#define UPDATE_ITEM_PROMPT "Update an item by code"
#define PRINT_ALL_PROMPT "Print all items in the registry"

#define MENU_HEADER "-- MENU -- "
#define MENU_TXT "1) " NEW_ITEM_PROMPT "\n2) " REMOVE_ITEM_PROMPT "\n3) " SEARCH_PROMPT "\n4) " UPDATE_ITEM_PROMPT "\n5) " PRINT_ALL_PROMPT
#define MENU MENU_HEADER "\n\n" MENU_TXT "\n0) Exit\n\n-- Choice: --\n > "

const char races[ANIMALS_TYPE_COUNT][32] = {
        "Unknown",
        "Cow",
        "Sheep",
        "Pig",
};

int main();
Animal input(Farm f);
void printAll(Farm *farm);
void printItem(Animal a);
void reallocate(Farm *f, int newSize);
int getMenu();
void shiftArray(Farm *farm, int i);
int findIndex(Farm farm, char query[]);
#include "menu.c"
#include "functions.c"
#include "main.h"

int main() {
    //Allocate a new farm
    //Create a "shortcut" to the list of animals
    Farm farm;
    farm.size = 0;
    farm.a = NULL;
    int choice;

//Handle the menu selection
    do {
        choice = getMenu();
        NL();
        NL();
        switch (choice) {
            case 1: {
                //Add an item to the array (reallocating the size)
                reallocate(&farm, farm.size + 1);
                farm.a[farm.size-1] = input(farm);
                printf("Added new item (new size: %d)\n", farm.size);
                break;
            }
            case 2: {
                //Find an item by its code and remove it by shifting the array
                char query[5+1];
                printf("Input search code to remove: ");
                scanf("%s", query);
                int idx = findIndex(farm, query);
                if (idx == -1) {
                    printf("Not found!\n");
                    break;
                }
                shiftArray(&farm, idx);
                printf("%s has been removed!\n", query);
                break;
            }
            case 3: {
                //Search an item by code and print its information
                char query[5+1];
                printf("Input search code: ");
                scanf("%s", query);
                int idx = findIndex(farm, query);
                if (idx == -1) {
                    printf("Not found!\n");
                    break;
                }
                printf("Found!\n");
                NL();
                printItem(farm.a[idx]);
                NL();
                break;
            }
            case 4: {
                //Search an item by code and modify it
                char query[5+1];
                printf("Input code to modify: ");
                scanf("%s", query);
                int idx = findIndex(farm, query);
                if (idx == -1) {
                    printf("Not found!\n");
                    break;
                }
                printf("Input new data:\n");
                farm.a[idx] = input(farm);
                NL();
                break;
            }
            case 5: {
                //Print everything in the registry
                printAll(&farm);
                break;
            }
            default:break;
        }
        NL();
        NL();
        NL();
        NL();
    } while (choice);

    return 0;
}

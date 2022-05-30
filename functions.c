/*
 * Function to reallocate (recreate) the dynamic array (with a new size) and clear up the old one (free memory)
 */
void reallocate(Farm *f, int newSize) {
    (*f).size = newSize;

    if ((*f).a == NULL) {
//Create a new array because it doesn't exist (NULL POINTER)
        Animal *newAllocator = malloc(newSize * sizeof(Animal));
        (*f).a = newAllocator;
        return;
    }

    (*f).a = realloc((*f).a, newSize * sizeof (Animal));
}


/*
 * Function to get an animal from input
 */
Animal input(Farm f) {
    Animal a = {};
    int flg, i;
//The code must be unique
    do {
        flg = 0;
        printf("Please input the unique code: [<string> code]\n > ");
        scanf("%s", a.code);
        for (i = 0; i < f.size && flg == 0; i++) {
            if (strcmp(f.a[i].code, a.code) == 0) {
                printf("The code must be unique!\n");
                flg = 1;
            }
        }
    } while (flg!=0);

//Input the data
    printf("Please input the data separated by spaces: [<float> weight, <int> race]\n > ");
    scanf("%f %d", &a.weight, &a.race);
    printf("Please input the born date separated by spaces: [<int> dd <int> mm <int> yyyy]\n > ");
    scanf("%d %d %d", &a.bornDate.day, &a.bornDate.month, &a.bornDate.year);
    printf("Please input the selling date separated by spaces: [<int> dd <int> mm <int> yyyy]\n > ");
    scanf("%d %d %d", &a.sellingDate.day, &a.sellingDate.month, &a.sellingDate.year);
    NL();

    if (a.race >= ANIMALS_TYPE_COUNT || a.race <= 0) a.race = 0;
    return a;
}


/*
 * Function to print all the items in the registry
 */
void printAll(Farm *farm) {
    int i = 0;
#ifdef DEBUG
    printf("Printing: %d\n", (*farm).size);
#endif
    NL();
    for (; i < (*farm).size; i++) printItem((*farm).a[i]);
}


/*
 * Print a single item
 */
void printItem(Animal a) {
//Print all the fields of the animal
    printf("Animal [%s]:\n"
           "> Weight: %0.2f\n"
           "> Race: %s\n"
           "> Born: %d-%d-%d\n"
           "> Selling: %d-%d-%d\n",
           a.code, a.weight, races[a.race], a.bornDate.day, a.bornDate.month, a.bornDate.year,
           a.sellingDate.day, a.sellingDate.month, a.sellingDate.year);
    NL();
}


/*
 * Allows to find an item index by code string
 */
int findIndex(Farm farm, char query[]) {
    int i = 0;
    for (; i < farm.size; i++) {
        if (strcmp(farm.a[i].code, query) == 0) return i;
    }
    return -1;
}


/*
 * Shift array to fill the deleted element
 */
void shiftArray(Farm *farm, int i) {
    //shift a array to the left from I index
    for (; i < (*farm).size - 1; i++) {
        (*farm).a[i] = (*farm).a[i + 1];
    }

//Claim back the memory
    reallocate(farm, (*farm).size-1);
}

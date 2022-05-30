/*
 * Print the menu and get an input (only allowed entries)
 */
int getMenu() {
    int choice = 0;
    do {
        printf(MENU);
        scanf("%d", &choice);
    } while (choice < 0 || choice > 5);
    return choice;
}

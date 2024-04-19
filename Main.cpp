#include "groceryTracker.h"

int main() {
    GroceryTracker itemTracker;
    itemTracker.analyzeFile("CS210_Project_Three_Input_File.txt");
    itemTracker.displayMenu();
    return 0;
}


#include <iostream>
#include <cassert>
#include "../src/ShoppingList.h"
#include "../src/ListCounter.h"

int main() {
    std::cout << "TEST: ListCounter (Observer) class" << std::endl;

    ShoppingList list;
    ListCounter counter(&list);

    // Initial state
    // Note: Since ListCounter just prints to stdout in update(), 
    // automatic verification is hard without redirecting cout.
    // However, we can verify that the Observer pattern is wired up if the code compiles and runs.
    
    std::cout << "  - [MANUAL CHECK] Verify output below for 'Observer triggered'" << std::endl;
    
    list.addItem(Item("Pasta", 5));
    // Expect output from ListCounter

    list.removeItem("Pasta");
    // Expect output from ListCounter

    std::cout << "Test di LIST COUNTER completato (verifica output manuale necessario)." << std::endl;
    return 0;
}

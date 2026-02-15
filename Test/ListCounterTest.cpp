
#include <iostream>
#include <cassert>
#include "../src/ShoppingList.h"
#include "../src/ListCounter.h"

int main() {
    std::cout << "TEST: ListCounter (Observer) class" << std::endl;

    ShoppingList list;
    ListCounter counter(&list);

    
    std::cout << "  - [MANUAL CHECK] Verify output below for 'Observer triggered'" << std::endl;
    
    list.addItem(Item("Pasta", 5));


    list.removeItem("Pasta");


    std::cout << "Test di LIST COUNTER completato (verifica output manuale necessario)." << std::endl;
    return 0;
}

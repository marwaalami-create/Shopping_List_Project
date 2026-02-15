
#include <iostream>
#include <cassert>
#include "../src/Item.h"

int main() {
    std::cout << "TEST: Item class" << std::endl;

    // Test 1: Constructor and getters
    Item item("Latte", 2);
    assert(item.getName() == "Latte");
    assert(item.getQuantity() == 2);
    assert(item.isBought() == false);
    std::cout << "  - Constructor & Getters: OK" << std::endl;

    // Test 2: modify state
    item.setBought(true);
    assert(item.isBought() == true);
    std::cout << "  - setBought: OK" << std::endl;

    std::cout << "Tutti i test di ITEM superati!" << std::endl;
    return 0;
}

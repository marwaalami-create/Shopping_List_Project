
#include <iostream>
#include <cassert>
#include "../src/ShoppingList.h"

int main() {
    std::cout << "TEST: ShoppingList class" << std::endl;

    ShoppingList list;

    // Test 1: Empty list
    assert(list.getItems().empty());
    assert(list.getUnboughtCount() == 0);
    std::cout << "  - Empty list check: OK" << std::endl;

    // Test 2: Add item
    list.addItem(Item("Pane", 1));
    assert(list.getItems().size() == 1);
    assert(list.getUnboughtCount() == 1);
    assert(list.getItems()[0].getName() == "Pane");
    std::cout << "  - Add item: OK" << std::endl;

    // Test 3: Set bought
    list.setItemBought("Pane", true);
    assert(list.getUnboughtCount() == 0);
    assert(list.getItems()[0].isBought() == true);
    std::cout << "  - Set bought: OK" << std::endl;

    // Test 4: Remove item
    list.removeItem("Pane");
    assert(list.getItems().empty());
    std::cout << "  - Remove item: OK" << std::endl;

    std::cout << "Tutti i test di SHOPPING LIST superati!" << std::endl;
    return 0;
}

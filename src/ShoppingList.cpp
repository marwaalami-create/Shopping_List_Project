#include "ShoppingList.h"
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}
const std::vector<Item>& ShoppingList::getItems() const {
    return items;
}
void ShoppingList::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            items.erase(it);
            notify();
            break;
        }
    }
}
void ShoppingList::setItemBought(const std::string& itemName, bool status) {
    for (auto& item : items) {
        if (item.getName() == itemName) {
            item.setBought(status);
            notify();
            return;
        }
    }
}
int ShoppingList::getUnboughtCount() const {
    int count = 0;
    for (const auto& item : items) {
        if (!item.isBought()) {
            count++;
        }
    }
    return count;
}

#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H
#include <vector>
#include "Item.h"
#include "Subject.h" // 1. Includiamo il Subject
class ShoppingList : public Subject {
public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void setItemBought(const std::string& itemName, bool status);
    const std::vector<Item>& getItems() const;
    int getUnboughtCount() const;
private:
    std::vector<Item> items;
};
#endif
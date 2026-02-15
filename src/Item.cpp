#include "Item.h"
Item::Item(std::string name, int quantity)
: name(name), quantity(quantity), bought(false) {}
std::string Item::getName() const {
    return name;
}
int Item::getQuantity() const {
    return quantity;
}
bool Item::isBought() const {
    return bought;
}
void Item::setBought(bool status) {
    bought = status;
}
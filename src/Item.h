#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
public:
    Item(std::string name, int quantity = 1);
    std::string getName() const;
    int getQuantity() const;
    bool isBought() const;
    void setBought(bool status);
private:
    std::string name;
    int quantity;
    bool bought;
};
#endif
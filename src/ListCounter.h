#ifndef LISTCOUNTER_H
#define LISTCOUNTER_H
#include <iostream>
#include "Observer.h"
#include "ShoppingList.h"
class ListCounter : public Observer {
public:
    ListCounter(ShoppingList* s) : list(s) {
        list->addObserver(this);
    }
    virtual void update() override {
        std::cout << "\n>>> [NOTIFICA]: La lista e cambiata!" << std::endl;
        std::cout << ">>> Prodotti ancora da comprare: " << list->getUnboughtCount() << std::endl;
    }
private:
    ShoppingList* list;
};
#endif

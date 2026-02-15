#ifndef LISTCOUNTER_H // Protezione
#define LISTCOUNTER_H
#include <iostream> // Per stampare la notifica
#include "Observer.h" // Perché è un Observer
#include "ShoppingList.h" // Perché deve leggere i dati della lista
class ListCounter : public Observer { // Eredita da Observer
public:
    ListCounter(ShoppingList* s) : list(s) { // Costruttore
        list->addObserver(this); // Si registra come osservatore appena nasce
    }
    virtual void update() override { // Cosa fare quando la lista cambia
        std::cout << "\n>>> [NOTIFICA]: La lista e cambiata!" << std::endl;
        std::cout << ">>> Prodotti ancora da comprare: " << list->getUnboughtCount() << std::endl;
    }
private:
    ShoppingList* list; // Puntatore alla lista che sta osservando
};
#endif

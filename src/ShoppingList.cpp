#include "ShoppingList.h" // Include l'header della classe
void ShoppingList::addItem(const Item& item) { // Metodo per aggiungere un prodotto
    items.push_back(item); // Aggiunge l'oggetto al vettore
    notify(); // NOTIFICA: avvisa gli osservatori che abbiamo aggiunto un elemento
}
const std::vector<Item>& ShoppingList::getItems() const { // Metodo per leggere i prodotti
    return items; // Restituisce il riferimento al vettore
}
void ShoppingList::removeItem(const std::string& itemName) { // Metodo per rimuovere un prodotto
    for (auto it = items.begin(); it != items.end(); ++it) { // Ciclo per cercare il prodotto
        if (it->getName() == itemName) { // Se il nome corrisponde
            items.erase(it); // Cancella l'elemento
            notify(); // NOTIFICA: avvisa gli osservatori che un elemento è stato rimosso
            break; // Esce dal ciclo
        }
    }
}
void ShoppingList::setItemBought(const std::string& itemName, bool status) { // Metodo per cambiare stato
    for (auto& item : items) { // Ciclo di ricerca (senza const per poter modificare)
        if (item.getName() == itemName) { // Se trova il prodotto col nome giusto
            item.setBought(status); // Imposta il nuovo stato (true o false)
            notify(); // NOTIFICA: avvisa gli osservatori che lo stato è cambiato
            return; // Esce subito
        }
    }
}
int ShoppingList::getUnboughtCount() const { // Metodo per contare i mancanti
    int count = 0; // Contatore iniziale
    for (const auto& item : items) { // Scorre la lista
        if (!item.isBought()) { // Se NON è comprato
            count++; // Incrementa
        }
    }
    return count; // Restituisce il totale
}
//1_push_back: Spiega che è il metodo standard dei vettori per inserire dati.
//2_Il ciclo for (riga 13): È un "iteratore".
//Serve per scansionare la lista dall'inizio (begin) alla fine (end).
//3_items.erase(it): È il comando che cancella fisicamente l'elemento dalla memoria della lista.
//4_!item.isBought(): L'operatore punto esclamativo è l'operatore logico NOT.
//Trasforma false in true, permettendoci di contare solo ciò che non è stato comprato.

#include <iostream>
#include <string>
#include "ShoppingList.h"
#include "ListCounter.h"
int main() {
    ShoppingList miaLista;
    ListCounter contatore(&miaLista);
    int scelta;
    std::string nome;
    int quantita;
    do {
        std::cout << "\n--- MENU LISTA ---" << std::endl;
        std::cout << "1. Aggiungi prodotto" << std::endl;
        std::cout << "2. Visualizza lista" << std::endl;
        std::cout << "3. Segna come COMPRATO" << std::endl;
        std::cout << "4. Esci" << std::endl;
        std::cout << "Scelta: ";
        std::cin >> scelta;
        switch (scelta) {
            case 1:
                std::cout << "Nome: ";
            std::cin >> nome;
            std::cout << "Quantita: ";
            std::cin >> quantita;
            miaLista.addItem(Item(nome, quantita));
            break;
            case 2:
                for (const auto& item : miaLista.getItems()) {
                    std::cout << "- " << item.getName() << " (x" << item.getQuantity() << ") ";
                    std::cout << (item.isBought() ? "[PRESO]" : "[DA COMPRARE]") << std::endl;
                }
            break;
            case 3:
                std::cout << "Cosa hai comprato? ";
            std::cin >> nome;
            miaLista.setItemBought(nome, true);
            break;
            case 4:
                std::cout << "Ciao!" << std::endl;
            break;
            default:
                std::cout << "Opzione non valida!" << std::endl;
        }
    } while (scelta != 4);
    return 0;
}


#include <iostream>
#include <string>
#include "ShoppingList.h"
#include "ListCounter.h"
int main() { // Inizio del programma
    ShoppingList miaLista; // Creiamo l'oggetto lista (il nostro Subject)
    ListCounter contatore(&miaLista); // Creiamo l'osservatore e lo colleghiamo alla lista
    int scelta; // Per memorizzare il numero del menu
    std::string nome; // Per memorizzare temporaneamente il nome del prodotto
    int quantita; // Per memorizzare la quantità
    do { // Ciclo del menu
        std::cout << "\n--- MENU LISTA ---" << std::endl;
        std::cout << "1. Aggiungi prodotto" << std::endl;
        std::cout << "2. Visualizza lista" << std::endl;
        std::cout << "3. Segna come COMPRATO" << std::endl;
        std::cout << "4. Esci" << std::endl;
        std::cout << "Scelta: ";
        std::cin >> scelta; // Legge la scelta dell'utente
        switch (scelta) { // Gestisce le diverse opzioni
            case 1: // AGGIUNGI
                std::cout << "Nome: ";
            std::cin >> nome;
            std::cout << "Quantita: ";
            std::cin >> quantita;
            miaLista.addItem(Item(nome, quantita)); // Questa riga farà scattare l'Observer!
            break;
            case 2: // VISUALIZZA
                for (const auto& item : miaLista.getItems()) {
                    std::cout << "- " << item.getName() << " (x" << item.getQuantity() << ") ";
                    std::cout << (item.isBought() ? "[PRESO]" : "[DA COMPRARE]") << std::endl;
                }
            break;
            case 3: // COMPRA
                std::cout << "Cosa hai comprato? ";
            std::cin >> nome;
            miaLista.setItemBought(nome, true); // Anche questa riga farà scattare l'Observer!
            break;
            case 4: // ESCI
                std::cout << "Ciao!" << std::endl;
            break;
            default:
                std::cout << "Opzione non valida!" << std::endl;
        }
    } while (scelta != 4); // Ripete finché non si preme 4
    return 0;
}

//std::cin: È il "canale" di input. Attenzione: legge fino allo spazio. Se scrivi "Pane integrale", leggerebbe solo "Pane".
//switch: È più ordinato di usare mille if...else. Rende il codice più leggibile (Clean Code).
//do-while: È perfetto per i menu perché garantisce che l'utente veda il menu almeno una volta prima che il programma decida se chiudersi

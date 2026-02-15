#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector> // Serve per tenere una lista di osservatori
#include "Observer.h" // Ogni Subject deve conoscere gli Observer
class Subject {
public:
    virtual ~Subject() {}
    void addObserver(Observer* o) { // Metodo per aggiungere qualcuno che vuole "guardare" la lista
        observers.push_back(o);
    }
    void removeObserver(Observer* o) { 
        for (auto it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                break;
            }
        }
    }
    void notify() { // IL CUORE: avvisa tutti che qualcosa è cambiato!
        for (auto observer : observers) { // Ciclo su tutti gli osservatori registrati
            observer->update(); // Chiama il metodo update() di ognuno di loro
        }
    }
private:
    std::vector<Observer*> observers; // La lista segreta degli osservatori registrati
};
#endif
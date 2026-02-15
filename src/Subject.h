#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include "Observer.h"
class Subject {
public:
    virtual ~Subject() {}
    void addObserver(Observer* o) {
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
    void notify() {
        for (auto observer : observers) {
            observer->update();
        }
    }
private:
    std::vector<Observer*> observers;
};
#endif
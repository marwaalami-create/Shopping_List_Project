
#include <iostream>
#include <cassert>
#include "../src/Subject.h"
#include "../src/Observer.h"


class MockObserver : public Observer {
public:
    int updateCallCount = 0;
    void update() override {
        updateCallCount++;
    }
};

class ConcreteSubject : public Subject {

};

int main() {
    std::cout << "TEST: Subject class logic" << std::endl;

    ConcreteSubject subject;
    MockObserver observer1;
    MockObserver observer2;


    subject.addObserver(&observer1);
    subject.notify();
    assert(observer1.updateCallCount == 1);
    std::cout << "  - Add & Notify: OK" << std::endl;


    subject.addObserver(&observer2);
    subject.notify();
    assert(observer1.updateCallCount == 2);
    assert(observer2.updateCallCount == 1);
    std::cout << "  - Multiple Observers: OK" << std::endl;


    subject.removeObserver(&observer1);
    subject.notify();
    assert(observer1.updateCallCount == 2);
    assert(observer2.updateCallCount == 2);
    std::cout << "  - Remove Observer: OK" << std::endl;

    std::cout << "Tutti i test di SUBJECT superati!" << std::endl;
    return 0;
}

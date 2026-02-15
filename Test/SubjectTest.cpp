
#include <iostream>
#include <cassert>
#include "../src/Subject.h"
#include "../src/Observer.h"

// Mock Observer for testing
class MockObserver : public Observer {
public:
    int updateCallCount = 0;
    void update() override {
        updateCallCount++;
    }
};

class ConcreteSubject : public Subject {
    // Just a concrete implementation to instantiate Subject
};

int main() {
    std::cout << "TEST: Subject class logic" << std::endl;

    ConcreteSubject subject;
    MockObserver observer1;
    MockObserver observer2;

    // Test 1: Add observer and notify
    subject.addObserver(&observer1);
    subject.notify();
    assert(observer1.updateCallCount == 1);
    std::cout << "  - Add & Notify: OK" << std::endl;

    // Test 2: Multiple observers
    subject.addObserver(&observer2);
    subject.notify();
    assert(observer1.updateCallCount == 2);
    assert(observer2.updateCallCount == 1);
    std::cout << "  - Multiple Observers: OK" << std::endl;

    // Test 3: Remove observer
    subject.removeObserver(&observer1);
    subject.notify();
    assert(observer1.updateCallCount == 2); // Should NOT increase
    assert(observer2.updateCallCount == 2); // Should increase
    std::cout << "  - Remove Observer: OK" << std::endl;

    std::cout << "Tutti i test di SUBJECT superati!" << std::endl;
    return 0;
}

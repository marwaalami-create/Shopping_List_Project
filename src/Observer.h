#ifndef OBSERVER_H // Protezione contro inclusioni multiple
#define OBSERVER_H
class Observer { // La classe "base" per chi vuole osservare la lista
public:
    virtual ~Observer() {} // Distruttore virtuale: fondamentale per la gestione della memoria
    virtual void update() = 0; // Metodo "astratto": ogni osservatore deciderà cosa fare quando viene avvisato
};
#endif

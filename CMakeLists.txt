cmake_minimum_required(VERSION 3.20)
project(ShoppingList_UltimaProva)

set(CMAKE_CXX_STANDARD 17)

# Sorgenti comuni (libreria principale)
set(COMMON_SOURCES
    src/Item.cpp
    src/Item.h
    src/ShoppingList.cpp
    src/ShoppingList.h
    src/Observer.h
    src/Subject.h
    src/ListCounter.h
)

# Applicazione principale
add_executable(ShoppingList_App src/main.cpp ${COMMON_SOURCES})

# --- TEST UNITARI SINGOLI ---

# 1. Test Item
add_executable(TestItem Test/ItemTest.cpp ${COMMON_SOURCES})

# 2. Test ShoppingList
add_executable(TestShoppingList Test/ShoppingListTest.cpp ${COMMON_SOURCES})

# 3. Test ListCounter (Observer)
add_executable(TestListCounter Test/ListCounterTest.cpp ${COMMON_SOURCES})

# 4. Test Subject (Logica base)
add_executable(TestSubject Test/SubjectTest.cpp ${COMMON_SOURCES})

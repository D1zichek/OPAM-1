#include "list.hpp"
#include <iostream>
#include <cassert>

void test_default_constructor() {
    blgt::list lst;
    assert(lst.empty());
    assert(lst.size() == 0);
    std::cout << "test_default_constructor passed\n";
}

void test_insert_front() {
    blgt::list lst;
    lst.insert_front(10);
    assert(!lst.empty());
    assert(lst.size() == 1);
    assert(*lst.begin() == 10);

    lst.insert_front(20);
    assert(lst.size() == 2);
    assert(*lst.begin() == 20);
    std::cout << "test_insert_front passed\n";
}

void test_insert_back() {
    blgt::list lst;
    lst.insert_back(10);
    assert(!lst.empty());
    assert(lst.size() == 1);
    assert(*lst.begin() == 10);

    lst.insert_back(20);
    assert(lst.size() == 2);
    auto it = lst.begin();
    assert(*it == 10);
    assert(*++it == 20);
    std::cout << "test_insert_back passed\n";
}

void test_erase_front() {
    blgt::list lst;
    lst.insert_front(10);
    lst.insert_front(20);

    lst.erase_front();
    assert(lst.size() == 1);
    assert(*lst.begin() == 10);

    lst.erase_front();
    assert(lst.empty());
    std::cout << "test_erase_front passed\n";
}

void test_erase_back() {
    blgt::list lst;
    lst.insert_back(10);
    lst.insert_back(20);

    lst.erase_back();
    assert(lst.size() == 1);
    assert(*lst.begin() == 10);

    lst.erase_back();
    assert(lst.empty());
    std::cout << "test_erase_back passed\n";
}

void test_iterator() {
    blgt::list lst;
    lst.insert_back(10);
    lst.insert_back(20);
    lst.insert_back(30);

    auto it = lst.begin();
    assert(*it == 10);
    assert(*++it == 20);
    assert(*++it == 30);
    assert(++it == lst.end());

    
    it = lst.begin();
    assert(*it++ == 10);
    assert(*it++ == 20);
    assert(*it == 30);
    std::cout << "test_iterator passed\n";
}

void test_empty() {
    blgt::list lst;
    assert(lst.empty());

    lst.insert_front(1);
    assert(!lst.empty());

    lst.erase_front();
    assert(lst.empty());
    std::cout << "test_empty passed\n";
}

void test_size() {
    blgt::list lst;
    assert(lst.size() == 0);

    lst.insert_front(1);
    assert(lst.size() == 1);

    lst.insert_back(2);
    assert(lst.size() == 2);

    lst.erase_back();
    assert(lst.size() == 1);

    lst.erase_front();
    assert(lst.size() == 0);
    std::cout << "test_size passed\n";
}

void test_edge_cases() {
    blgt::list lst;
    lst.erase_front();  
    lst.erase_back();   
    assert(lst.empty());

    lst.insert_front(42);
    lst.erase_front();
    assert(lst.empty());

    lst.insert_back(42);
    lst.erase_back();
    assert(lst.empty());
    std::cout << "test_edge_cases passed\n";
}

void test_iterator_equality() {
    blgt::list lst;
    lst.insert_back(1);
    lst.insert_back(2);

    auto it1 = lst.begin();
    auto it2 = lst.begin();
    assert(it1 == it2);

    ++it1;
    assert(it1 != it2);

    ++it2;
    assert(it1 == it2);

    assert(lst.end() == lst.end());
    std::cout << "test_iterator_equality passed\n";
}

int main() {
    std::cout << "=== Running Linked List Tests ===\n";
    
    test_default_constructor();
    test_insert_front();
    test_insert_back();
    test_erase_front();
    test_erase_back();
    test_iterator();
    test_empty();
    test_size();
    test_edge_cases();
    test_iterator_equality();
    
    std::cout << "=== All Tests Passed ===\n";
    return 0;
}
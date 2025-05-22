#include "list.hpp"
#include <iostream>
#include <cassert> 

void test_insert_front() {
    blgt::list my_list;
    my_list.insert_front(10);
    assert(my_list.size() == 1);
    assert(*my_list.begin() == 10);
    my_list.insert_front(20);
    assert(my_list.size() == 2);
    assert(*my_list.begin() == 20);
    std::cout << "test_insert_front passed" << std::endl;
}

void test_insert_back() {
    blgt::list my_list;
    my_list.insert_back(10);
    assert(my_list.size() == 1);
    assert(*my_list.begin() == 10);
    my_list.insert_back(20);
    assert(my_list.size() == 2);
    blgt::list::iterator it = my_list.begin();
    ++it;
    assert(*it == 20);
    std::cout << "test_insert_back passed" << std::endl;
}

void test_erase_front() {
    blgt::list my_list;
    my_list.insert_front(10);
    my_list.insert_front(20);
    my_list.erase_front();
    assert(my_list.size() == 1);
    assert(*my_list.begin() == 10);
    my_list.erase_front();
    assert(my_list.empty());
    std::cout << "test_erase_front passed" << std::endl;
}

void test_erase_back() {
    blgt::list my_list;
    my_list.insert_back(10);
    my_list.insert_back(20);
    my_list.erase_back();
    assert(my_list.size() == 1);
    assert(*my_list.begin() == 10);
    my_list.erase_back();
    assert(my_list.empty());
    std::cout << "test_erase_back passed" << std::endl;
}

void test_empty_and_size() {
    blgt::list my_list;
    assert(my_list.empty());
    assert(my_list.size() == 0);
    my_list.insert_front(10);
    assert(!my_list.empty());
    assert(my_list.size() == 1);
    my_list.erase_front();
    assert(my_list.empty());
    assert(my_list.size() == 0);
    std::cout << "test_empty_and_size passed" << std::endl;
}

void test_iterator() {
    blgt::list my_list;
    my_list.insert_back(1);
    my_list.insert_back(2);
    my_list.insert_back(3);

    int expected_value = 1;
    for (blgt::list::iterator it = my_list.begin(); it != my_list.end(); ++it) {
        assert(*it == expected_value);
        expected_value++;
    }
    assert(expected_value == 4); 

    
    blgt::list::iterator it_post = my_list.begin();
    assert(*(it_post++) == 1);
    assert(*it_post == 2);
    std::cout << "test_iterator passed" << std::endl;
}

int main() {
    test_insert_front();
    test_insert_back();
    test_erase_front();
    test_erase_back();
    test_empty_and_size();
    test_iterator();

    std::cout << "\nAll tests passed!" << std::endl;

    return 0;
}


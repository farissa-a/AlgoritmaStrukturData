#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

bool SingleLinkedList::is_empty() {
    return (this->size == 0);
}

void SingleLinkedList::add_front(int val) {
    Node* newNode = new Node{val, nullptr};

    if (head == nullptr) {
        head = tail = newNode;
        newNode->next = head; // Sirkular
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    if (is_empty()) {
        add_front(val);
        return;
    }

    Node* newNode = new Node{val, head};
    tail->next = newNode;
    tail = newNode;
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Indeks di luar jangkauan");
    }

    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* helper = head;
        int currentPos = 0;
        
        while (currentPos < idx - 1) {
            helper = helper->next;
            currentPos++;
        }

        Node* newNode = new Node{val, helper->next};
        helper->next = newNode;
        size++;
    }
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::out_of_range("List masih kosong");

    Node* targetNode = head;
    
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }

    delete targetNode;
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::out_of_range("List masih kosong");

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        size = 0;
    } else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        
        delete tail;
        tail = prev;
        tail->next = head;
        size--;
    }
}

void SingleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Indeks tidak valid");

    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node* curr = head;
        for (int i = 0; i < idx - 1; ++i) {
            curr = curr->next;
        }

        Node* trash = curr->next;
        curr->next = trash->next;
        delete trash;
        size--;
    }
}

void SingleLinkedList::display() {
    if (is_empty()) return;

    Node* pointer = head;
    int count = 0;
    
    while (count < size) {
        std::cout << pointer->data << " ";
        pointer = pointer->next;
        count++;
    }
    std::cout << std::endl;
}

int SingleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Akses indeks ilegal");

    Node* pointer = head;
    for (int i = 0; i < idx; ++i) {
        pointer = pointer->next;
    }
    return pointer->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Akses indeks ilegal");

    Node* pointer = head;
    int i = 0;
    while (i < idx) {
        pointer = pointer->next;
        i++;
    }
    pointer->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}
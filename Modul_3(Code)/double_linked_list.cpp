#include "double_linked_list.h"
#include <iostream>
using namespace std;

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return head == nullptr;
}

void DoubleLinkedList::add_front(char val) {
    Node* node = new Node();
    node->data = val;

    if (is_empty()) {
        node->next = node;
        node->prev = node;
        head = node;
        tail = node;
    } else {
        node->next  = head;
        node->prev  = tail;
        head->prev  = node;
        tail->next  = node;
        head = node;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* node = new Node();
    node->data = val;

    if (is_empty()) {
        node->next = node;
        node->prev = node;
        head = node;
        tail = node;
    } else {
        node->prev  = tail;
        node->next  = head;
        tail->next  = node;
        head->prev  = node;
        tail = node;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return;
    if (idx == 0)    { add_front(val); return; }
    if (idx == size) { add_back(val);  return; }

    Node* node = new Node();
    node->data = val;

    Node* curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;

    Node* prev_node  = curr->prev;
    node->prev       = prev_node;
    node->next       = curr;
    prev_node->next  = node;
    curr->prev       = node;
    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;

    Node* to_del = head;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
        delete to_del;
        size = 0;
        return;
    }

    to_del->prev->next = to_del->next;
    to_del->next->prev = to_del->prev;
    head = to_del->next;
    delete to_del;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;

    Node* to_del = tail;

    if (size == 1) {
        head = nullptr;
        tail = nullptr;
        delete to_del;
        size = 0;
        return;
    }

    to_del->next->prev = to_del->prev;
    to_del->prev->next = to_del->next;
    tail = to_del->prev;
    delete to_del;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (is_empty() || idx < 0 || idx >= size) return;
    if (idx == 0)        { delete_front(); return; }
    if (idx == size - 1) { delete_back();  return; }

    Node* curr;
    if (idx < size / 2) {
        curr = head;
        for (int i = 0; i < idx; i++)
            curr = curr->next;
    } else {
        curr = tail;
        for (int i = size - 1; i > idx; i--)
            curr = curr->prev;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size--;
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        cout << "List kosong\n";
        return;
    }
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        cout << curr->data;
        if (i < size - 1) cout << " <-> ";
        curr = curr->next;
    }
    cout << " <-> (head)\n";
}

char DoubleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) return '\0';

    Node* curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) return;

    Node* curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;
    curr->data = val;
}

void DoubleLinkedList::clear() {
    while (!is_empty())
        delete_front();
}
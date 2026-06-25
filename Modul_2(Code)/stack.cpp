#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    s->top = nullptr;
}

bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

bool isFull(const Stack* s) {
    return (s->top != nullptr && (s->top - s->data) >= MAX - 1);
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        throw std::runtime_error("Stack Overflow");
    }
    if (isEmpty(s)) {
        s->top = s->data;
    } else {
        s->top++;
    }
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) {
        throw std::runtime_error("Stack Underflow");
    }
    if (s->top == s->data) {
        s->top = nullptr;
    } else {
        s->top--;
    }
}

int peek(const Stack* s) {
    if (isEmpty(s)) {
        throw std::runtime_error("Stack is Empty");
    }
    return *(s->top);
}
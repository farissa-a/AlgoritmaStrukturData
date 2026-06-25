#include "queue.h"
#include <stdexcept>

void init(Queue* q){
    q->front = q->data;
    q->rear = q->data - 1;
}

bool isEmpty(const Queue* q){
    return q->front == q->data && q->rear == q->data - 1;
}

bool isFull(const Queue* q){
    if (isEmpty(q)) return false;
    
    const int* nextRear;

    if (q->rear == q->data + MAX - 1)
        nextRear = q->data;
    else
        nextRear = q->rear + 1;
    return nextRear == q->front;
}

void enqueue(Queue* q, int value){
    if (isFull(q))
        throw std::overflow_error("Queue penuh!");

    if (isEmpty(q)){
        q->front = q->data;
        q->rear = q->data;
    } else {
        if (q->rear == q->data + MAX - 1)
            q->rear = q->data;
        else
            q->rear++;
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong!");

    if (q->front == q->rear){
        q->front = q->data;
        q->rear = q->data - 1;
    } else {
        if (q->front == q->data + MAX - 1)
            q->front = q->data;
        else
            q->front++;
    }
}

int front(const Queue* q){
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong!");

    return *(q->front);
}

int back(const Queue* q){
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong!");

    return *(q->rear);
}
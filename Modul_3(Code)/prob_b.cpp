#include "double_linked_list.h"
#include <iostream>
using namespace std;

Node* move_forward(Node* node, long long steps) {
    for (long long i = 0; i < steps; i++)
        node = node->next;
    return node;
}

Node* move_backward(Node* node, long long steps) {
    for (long long i = 0; i < steps; i++)
        node = node->prev;
    return node;
}

bool is_adjacent(Node* alpha, Node* beta, DoubleLinkedList& list) {
    if (alpha->next == beta && alpha != list.tail) return true;
    if (beta->next  == alpha && beta  != list.tail) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R;
    cin >> N >> R;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        list.add_back(c);
    }

    Node* alpha = list.head;
    Node* beta  = list.tail;

    for (int i = 0; i < R; i++) {
        long long X, Y;
        cin >> X >> Y;

        if (list.is_empty()) continue;

        long long move_alpha = X % list.size;
        long long move_beta  = Y % list.size;

        alpha = move_forward(alpha, move_alpha);
        beta  = move_backward(beta, move_beta);

        if (alpha == beta) {
            Node* next_node = alpha->next;
            Node* prev_node = alpha->prev;

            if (list.size == 1) {
                delete alpha;
                list.head = nullptr;
                list.tail = nullptr;
                list.size = 0;
                alpha = nullptr;
                beta  = nullptr;
            } else {
                alpha->prev->next = alpha->next;
                alpha->next->prev = alpha->prev;
                if (alpha == list.head) list.head = alpha->next;
                if (alpha == list.tail) list.tail = alpha->prev;
                delete alpha;
                list.size--;

                if (list.size == 1) {
                    alpha = list.head;
                    beta  = list.head;
                } else {
                    alpha = next_node;
                    beta  = prev_node;
                }
            }
        } else if (is_adjacent(alpha, beta, list)) {
            char temp   = alpha->data;
            alpha->data = beta->data;
            beta->data  = temp;
        }
    }

    if (list.is_empty()) {
        cout << "EMPTY\n";
    } else {
        Node* curr = list.head;
        for (int i = 0; i < list.size; i++) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << "\n";
    }

    list.clear();
    return 0;
}
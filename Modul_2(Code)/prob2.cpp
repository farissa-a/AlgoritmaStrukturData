#include <iostream>
#include "queue.h"

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    Queue q;
    init(&q);

    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;

        enqueue(&q, val);
        current_sum += val;

        if (i >= k) {
            current_sum -= front(&q);
            dequeue(&q);
        }

        if (i >= k - 1) {
            std::cout << current_sum << (i == n - 1 ? "" : " ");
        }
    }
    std::cout << std::endl;

    return 0;
}
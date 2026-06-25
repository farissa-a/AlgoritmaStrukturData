#include "sorting_algorithms.h"
#include <algorithm>
#include <chrono>

using Clock = std::chrono::high_resolution_clock;

void bubble_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            m.comparisons++;
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void selection_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            std::swap(data[i], data[min_idx]);
            m.swaps++;
        }
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void insertion_sort(std::vector<int>& data, Metrics& m) {
    int n = data.size();
    auto start = Clock::now();

    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            m.comparisons++;
            data[j + 1] = data[j];
            m.shifts++;
            j--;
        }
        if (j >= 0) m.comparisons++;
        data[j + 1] = key;
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void merge_helper(std::vector<int>& data, int left, int right, Metrics& m) {
    m.recursive_calls++;

    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_helper(data, left, mid, m);
    merge_helper(data, mid + 1, right, m);

    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        m.comparisons++;
        if (data[i] <= data[j]) {
            temp.push_back(data[i++]);
        } else {
            temp.push_back(data[j++]);
        }
    }
    while (i <= mid) temp.push_back(data[i++]);
    while (j <= right) temp.push_back(data[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        data[left + k] = temp[k];
    }
}

void merge_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty())
        merge_helper(data, 0, (int)data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

int partition(std::vector<int>& data, int low, int high, Metrics& m) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m.comparisons++;
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
            m.swaps++;
        }
    }
    std::swap(data[i + 1], data[high]);
    m.swaps++;
    return i + 1;
}

void quick_helper(std::vector<int>& data, int low, int high, Metrics& m) {
    m.recursive_calls++;

    if (low < high) {
        int pi = partition(data, low, high, m);
        quick_helper(data, low, pi - 1, m);
        quick_helper(data, pi + 1, high, m);
    }
}

void quick_sort(std::vector<int>& data, Metrics& m) {
    auto start = Clock::now();

    if (!data.empty())
        quick_helper(data, 0, (int)data.size() - 1, m);

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}

void counting_sort_by_digit(std::vector<int>& data, int exp, Metrics& m) {
    int n = data.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (data[i] / exp) % 10;
        count[digit]++;
        m.array_accesses++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        output[count[digit] - 1] = data[i];
        count[digit]--;
        m.array_accesses++;
    }

    for (int i = 0; i < n; i++) {
        data[i] = output[i];
        m.array_accesses++;
    }
}

void radix_sort(std::vector<int>& data, Metrics& m) {
    if (data.empty()) return;
    auto start = Clock::now();

    int max_val = *std::max_element(data.begin(), data.end());

    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        counting_sort_by_digit(data, exp, m);
    }

    m.time_ms = std::chrono::duration<double, std::milli>(Clock::now() - start).count();
}
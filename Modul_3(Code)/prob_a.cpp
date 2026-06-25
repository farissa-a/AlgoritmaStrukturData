#include "single_linked_list.h"
#include <iostream>

using namespace std;

int main() {
    int N;
    long long K_awal;
    
    if (!(cin >> N >> K_awal)) return 0;

    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        int nilai;
        cin >> nilai;
        list.add_back(nilai);
    }

    long long K_sekarang = K_awal;
    int index_sekarang = 0;

    while (list.size > 1) {
        
        index_sekarang = (index_sekarang + K_sekarang - 1) % list.size;
        
        if (index_sekarang < 0) index_sekarang += list.size;

        int nilai_batu = list.get(index_sekarang);

        if (nilai_batu % 2 == 0) {
            K_sekarang++; 
        } else {
            K_sekarang--;
        }

        if (K_sekarang <= 0) {
            K_sekarang = K_awal;
        }

        list.delete_idx(index_sekarang);

        if (list.size > 0) {
            index_sekarang %= list.size;
        }
    }

    cout << list.get(0) << endl;
    list.clear();

    return 0;
}
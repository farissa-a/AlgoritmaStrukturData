#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<char> labels(N);
    for (int i = 0; i < N; i++) cin >> labels[i];

    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];

    cout << "Adjacency List:\n";
    for (int i = 0; i < N; i++) {
        cout << labels[i] << " -> ";
        bool hasEdge = false;
        for (int j = 0; j < N; j++) {
            if (mat[i][j] > 0) {
                if (hasEdge) cout << ", ";
                cout << "(" << labels[j] << "," << mat[i][j] << ")";
                hasEdge = true;
            }
        }
        if (!hasEdge) cout << "-";
        cout << "\n";
    }

    return 0;
}
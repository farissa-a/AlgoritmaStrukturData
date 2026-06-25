#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<char> labels(N);
    map<char, int> idx;
    for (int i = 0; i < N; i++) {
        cin >> labels[i];
        idx[labels[i]] = i;
    }

    vector<vector<int>> mat(N, vector<int>(N, 0));

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        mat[idx[u]][idx[v]] = w;
    }

    cout << "Adjacency Matrix:\n";

    cout << " ";
    for (int i = 0; i < N; i++) {
        cout << " " << labels[i];
    }
    cout << "\n";

    for (int i = 0; i < N; i++) {
        cout << labels[i];
        for (int j = 0; j < N; j++) {
            cout << " " << mat[i][j];
        }
        cout << "\n";
    }

    return 0;
}
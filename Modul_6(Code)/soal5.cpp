#include <bits/stdc++.h>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    result.push_back(node->key);
    preorder(node->left, nil, result);
    preorder(node->right, nil, result);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    inorder(node->left, nil, result);
    result.push_back(node->key);
    inorder(node->right, nil, result);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil, vector<int>& result) {
    if (node == nil) return;
    postorder(node->left, nil, result);
    postorder(node->right, nil, result);
    result.push_back(node->key);
}

void printTraversal(const string& label, const vector<int>& v) {
    cout << label << " :";
    for (int x : v) cout << " " << x;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    RedBlackTree rbt;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (!rbt.contains(a)) {
            rbt.insert(a);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        const RedBlackTree::Node* r = rbt.root();
        const RedBlackTree::Node* nil = rbt.nil();

        if (query == "PREORDER") {
            vector<int> res;
            preorder(r, nil, res);
            printTraversal("[Preorder]", res);
        } else if (query == "INORDER") {
            vector<int> res;
            inorder(r, nil, res);
            printTraversal("[Inorder]", res);
        } else if (query == "POSTORDER") {
            vector<int> res;
            postorder(r, nil, res);
            printTraversal("[Postorder]", res);
        } else if (query == "ALL") {
            vector<int> pre, in, post;
            preorder(r, nil, pre);
            inorder(r, nil, in);
            postorder(r, nil, post);
            printTraversal("[Preorder]", pre);
            printTraversal("[Inorder]", in);
            printTraversal("[Postorder]", post);
        }
    }

    return 0;
}
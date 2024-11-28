/*
  Erik Paperniuk
  s1123540
  28.11.2024
*/
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* build(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1)
        return NULL;

    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < vals.size()) {
        Node* current = q.front();
        q.pop();

        if (i < vals.size() && vals[i] != -1) {
            current->left = new Node(vals[i]);
            q.push(current->left);
        }
        i++;

        if (i < vals.size() && vals[i] != -1) {
            current->right = new Node(vals[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int heightCalc(Node* node, int& dia) {
    if (!node)
        return 0;

    int left = heightCalc(node->left, dia);
    int right = heightCalc(node->right, dia);

    // Update diameter if path through this node is longer
    dia = max(dia, left + right + 1);

    return 1 + max(left, right);
}

int diameter(Node* root) {
    int dia = 0;
    heightCalc(root, dia);
    return dia;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> vals;
    string num = "";

    for(char c : s){
        if(isdigit(c) || c == '-'){
            num += c;
        }
        else{
            if(!num.empty()){
                vals.push_back(stoi(num));
                num = "";
            }
        }
    }
    if(!num.empty()){
        vals.push_back(stoi(num));
    }

    Node* root = build(vals);
    cout << diameter(root);

    return 0;
}


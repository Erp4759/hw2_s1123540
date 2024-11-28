/*
Erik Paperniuk
  s1123540
  28.11.2024
*/
#include <bits/stdc++.h>
using namespace std;

struct Elem {
    int val;
    int arrIdx;
    int elemIdx;
    bool operator<(const Elem& other) const {
        return val > other.val; // Min heap based on val
    }
};

int main(){
    int K;
    cin >> K;
    cin.ignore();
    vector<vector<int>> arrays(K, vector<int>());
    for(int i = 0; i < K; ++i){
        string line;
        getline(cin, line);
        if(line.empty()){
            --i;
            continue;
        }
        stringstream ss(line);
        int num;
        while(ss >> num){
            arrays[i].push_back(num);
        }
    }

    priority_queue<Elem> pq;
    for(int i = 0; i < K; ++i){
        if(!arrays[i].empty()){
            pq.push(Elem{arrays[i][0], i, 0});
        }
    }

    vector<int> merged;
    while(!pq.empty()){
        Elem current = pq.top();
        pq.pop();
        merged.push_back(current.val);
        // Check if there is a next element in the same array
        if(current.elemIdx + 1 < arrays[current.arrIdx].size()){
            pq.push(Elem{arrays[current.arrIdx][current.elemIdx + 1], current.arrIdx, current.elemIdx + 1});
        }
    }

    cout << "Merged Array: [";
    for(int i = 0; i < merged.size(); ++i){
        cout << merged[i];
        if(i != merged.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}


/*
Erik Paperniuk
  s1123540
  28.11.2024
*/
#include <bits/stdc++.h>
using namespace std;

struct Task {
    string name;
    int priority;

    Task(string n, int p) : name(n), priority(p) {}
};

struct Compare {
    bool operator()(const Task& a, const Task& b) {
        return a.priority < b.priority; // Max heap based on priority
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore the newline after N

    priority_queue<Task, vector<Task>, Compare> pq;

    for(int i = 0; i < N; ++i){
        string line;
        getline(cin, line);
        if(line.empty()){
            --i; // Skip empty lines
            continue;
        }

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if(cmd == "ADD"){
            string taskName;
            int prio;
            ss >> taskName >> prio;
            pq.emplace(taskName, prio);
        }
        else if(cmd == "GET"){
            if(!pq.empty()){
                Task topTask = pq.top();
                pq.pop();
                cout << topTask.name << "\n";
            }
            else{
                cout << "No tasks available\n";
            }
        }
    }

    // Collect remaining tasks
    vector<Task> rem;
    while(!pq.empty()){
        rem.push_back(pq.top());
        pq.pop();
    }

    // Sort in descending
    sort(rem.begin(), rem.end(), [&](const Task& a, const Task& b) -> bool {
        return a.priority > b.priority;
    });

    cout << "Remaining tasks: [";
    for(int i = 0; i < rem.size(); ++i){
        cout << "('" << rem[i].name << "', " << rem[i].priority << ")";
        if(i != rem.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}


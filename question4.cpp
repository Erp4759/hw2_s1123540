/*
Erik Paperniuk
  s1123540
  28.11.2024
*/
#include <bits/stdc++.h>
using namespace std;

struct Task {
  int profit;
  int deadline;
};

struct Compare {
  bool operator()(const Task& a, const Task& b) {
    return a.profit < b.profit; // Max heap
  }
};

int main(){
  int N;
  cin >> N;
  cin.ignore();

  priority_queue<Task, vector<Task>, Compare> pq;
  int max_deadline = 0;

  for(int i = 0; i < N; ++i){
    int p, d;
    cin >> p >> d;
    pq.push(Task{p, d});
    if(d > max_deadline)
      max_deadline = d;
  }

  // Initialize slots, -1 indicates a free slot
  vector<int> slots(max_deadline + 1, -1);
  int total_profit = 0;
  vector<int> scheduled; // Storing scheduled tasks here

  // Schedule tasks to maximize profit
  while(!pq.empty()){
    Task current = pq.top();
    pq.pop();
    // Find a free slot for the current task
    for(int j = current.deadline; j > 0; --j){
      if(slots[j] == -1){
        slots[j] = current.profit;
        total_profit += current.profit;
        scheduled.push_back(current.profit); // Record the scheduled task
        break;
      }
    }
  }

  cout << "Maximum Profit: " << total_profit << "\n";
  cout << "Scheduled Tasks: [";
  for(int i = 0; i < scheduled.size(); ++i){
    cout << scheduled[i];
    if(i != scheduled.size() - 1){
      cout << ", ";
    }
  }
  cout << "]";

  return 0;
}

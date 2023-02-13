#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct record {
  int end;
  int weight;
  bool operator<(const record& a)const{
    return a.weight < this->weight;
  }
};


vector<record> adj[20001]; //
int dp[20001];
const int INF = 1e9+10;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int V,E; // vertex, edge
  int K; // start vertext
  cin >> V >> E >> K;
  for(int i = 0; i < E; i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }
  for(int i = 0; i <= V; i++)  dp[i] = INF; 
  priority_queue<record,vector<record>> pq;
  dp[K] = 0;
  pq.push({K,dp[K]});

  while(!pq.empty()){
    int cur = pq.top().end;
    int curWeight = pq.top().weight;
    if(dp[cur] != curWeight) continue;
    pq.pop();
    for(auto next:adj[cur]){
      if(dp[next.end] > dp[cur] + next.weight){
        dp[next.end] = dp[cur] + next.weight;
        pq.push({next.end,dp[next.end]});
      }
    }
  }

  for(int i = 1; i <= V; i++){
    if(dp[i] == INF){
      cout << "INF" << '\n';
    }else{
      cout << dp[i] << '\n';
    }
  }

  return 0;
}
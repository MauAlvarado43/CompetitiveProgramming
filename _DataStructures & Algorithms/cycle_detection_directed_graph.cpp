#include <bits/stdc++.h>

using namespace std;

bool hasCycle(int me, vector<int> &state, vector<vector<int>> &graph) {
	
	if(state[me] == 1)
		return true;
	
	if(state[me] == 2)
		return false;
	
	state[me] = 1;

	bool sol = false;
	
	for(auto child : graph[me])
		sol = sol || hasCycle(child, state, graph);
	
	state[me] = 2;

	return sol;

}

int main() {
	
	int n, k, v;
	cin >> n;
	
	vector<vector<int>> graph(n);
	vector<int> state(n, 0);

	for(int i = 0; i < n; i++) {
		
		cin >> k;
		
		while(k--) {
			cin >> v; 
			v--;
			graph[i].push_back(v);
		}

	}

	bool ans = false;

	for(int i = 0; i < n; i++)
		if(state[i] == 0) 
			ans = ans || hasCycle(i, state, graph);
	
	cout << (ans ? "YES" : "NO") << endl;

}

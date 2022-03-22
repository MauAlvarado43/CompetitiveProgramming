#include <bits/stdc++.h>

using namespace std;

void printGraph(vector<vector<int>> &graph){
	
	for(int i = 0; i < graph.size(); i++){
		
		cout << i << " -> ";
		
		for(auto nbr : graph[i])
			cout << nbr << " ";
		
		cout << endl;

	}

}

int main(){
	
	int n, m, u, v; 
	cin >> n >> m;
	
	vector<vector<int>> graph(n);

	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printGraph(graph);

	return 0;
}

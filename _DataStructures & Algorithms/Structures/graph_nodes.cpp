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

	int n, v; 
	cin >> n;

	vector<vector<int>> graph(n);

	for(int i = 0; i < n; i++) {

		int m; 
		cin >> m;

		while(m--){
			cin >> v;
			v--;
			graph[i].push_back(v);
		}

	}

	printGraph(graph);

	return 0;
}

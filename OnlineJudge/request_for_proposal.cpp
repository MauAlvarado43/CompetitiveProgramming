#include <bits/stdc++.h> 

using namespace std;

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);

    int k = 1;

    while(true) {

        int n, p;
        cin >> n >> p;
        getchar();
        cin.clear();

        if(n && 0 || p == 0) break;

        vector<string> reqsT(n);

        for(int i = 0; i < n; i++) {
            getline(cin, reqsT[i]);
            cin.clear();
        }

        string bestName = "";
        double bestPrice = INT_MAX;
        int bestReqs = 0; 

        for(int i = 0; i < p; i++) {

            string name;
            getline(cin, name);
            cin.clear();

            double price = 0;
            int reqs = 0; 

            cin >> price;
            cin >> reqs;
            getchar();
            cin.clear();

            vector<string> reqsN(reqs);

            for(int i = 0; i < reqs; i++) {
                getline(cin, reqsN[i]); 
                cin.clear();
            }

            if(bestReqs < reqs || (bestReqs == reqs && bestPrice > price)) {
                bestName = name;
                bestPrice = price;
                bestReqs = reqs; 
            }      

        }

        if(k > 1) cout << "\n";
        cout << "RFP #" << k << "\n";
		cout << bestName << "\n";

        k++;

    }

    return 0;

}
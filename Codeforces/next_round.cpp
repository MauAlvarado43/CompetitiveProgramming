#include <iostream>
#include <vector>

using namespace std;

int main() {

    int mostScore = 0, qContestant = 0, contestantsAcepted = 0;

    cin >> qContestant >> mostScore;

    vector<int> contestants(qContestant);

    for(auto& contestant : contestants) cin >> contestant;

    mostScore = contestants[mostScore - 1];

    for(auto& contestant : contestants) 
        if(contestant >= mostScore && contestant != 0) contestantsAcepted++;
    

    cout << contestantsAcepted;

    return 0;

}
#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    bool stop = false;

    while(true) { 

        vector<vector<pair<char, char>>> cards;
        int piles = 0;

        for(int i = 0; i < 52; i++) {

            string aux;
            cin >> aux;

            if(aux[0] == '#') {
                stop = true;
                break;
            }

            cards.push_back(vector<pair<char, char>>(1, make_pair(aux[0], aux[1])));

            if(i == 0) 
                continue;

            piles++;

            bool move = true;

            while(move) {

                move = false;

                for(int j = 0; j <= piles; j++) {

                    if(j >= 3 && (cards[j - 3].back().first == cards[j].back().first || cards[j - 3].back().second == cards[j].back().second))
                        cards[j - 3].push_back(cards[j].back());
                    else if(j >= 1 && (cards[j - 1].back().first == cards[j].back().first || cards[j - 1].back().second == cards[j].back().second))
                        cards[j - 1].push_back(cards[j].back());
                    else
                        continue;

                    cards[j].pop_back();

                    if(cards[j].size() == 0) {
                        piles--;
                        cards.erase(cards.begin() + j);
                    }

                    move = true;
                    break;

                }

            }

        }

        if(stop)
            break;

        piles++;

        if(piles > 1)
            cout << piles << " piles remaining: ";
        else
            cout << piles << " pile remaining: ";

        for(int i = 0; i < piles; i++) {

            cout << cards[i].size();

            if (i != piles - 1) 
                cout << " ";

        }

        cout << "\n";

    }

    return 0;

}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Dragon {
    int strength;
    int bonus;
} Dragon;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int player, dragons_q;
    cin >> player >> dragons_q;

    vector<Dragon> dragons(dragons_q);

    for(Dragon& dragon : dragons) cin >> dragon.strength >> dragon.bonus;

    sort(dragons.begin(), dragons.end(), [](Dragon dragon1, Dragon dragon2) {
        return dragon1.strength < dragon2.strength;
    });    

    for(Dragon dragon : dragons) {

        if(player > dragon.strength) {
            player += dragon.bonus;
        }
        else {
            cout << "NO";
            exit(0);
        }
    } 

    cout << "YES";

    return 0;

}
// #include <bits/stdc++.h>
// using namespace std;

// void solve(int sum, int n, int a, int b, int c, int carry, int &cuts) {

// 	if(sum > n) return;
// 	if(sum == n && carry > cuts) cuts = carry;

// 	solve(sum + a, n, a, b, c, carry + 1, cuts);
// 	solve(sum + b, n, a, b, c, carry + 1, cuts);
// 	solve(sum + c, n, a, b, c, carry + 1, cuts);

// }

// int main() {

// 	int n, a, b, c, cuts = 0;
// 	cin >> n >> a >> b >> c;
	
// 	solve(0, n, a, b, c, 0, cuts);
	
// 	cout << cuts << endl;

// 	return 0;
// }

#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int maximum = 0;

    for(int i = 0; i <= n; i++) {

        if(i * a > n) break;

        for(int j = 0; j <= n; j++) {

            if(i * j > n) break;

            for(int k = 0; k <= n; k++) {
                
                int sum = (i * a) + (j * b) + (k * c);

                if(sum == n) {
                    sum = 0;
                    maximum = max(maximum, i + j + k);
                    break;
                }
                else if(sum > n) {
                    sum = 0;
                    break;
                }

            }   
        }
    }

    cout << maximum;

    return 0;

}
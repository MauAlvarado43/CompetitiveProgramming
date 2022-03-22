#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool giveMeBit(int n, int k) {
    return (n >>= k) & 1;
}

void setBit(int &n, int k) {
    n |= (1 << k);
}

void clearBit(int &n, int k) {
    n &= ~(1 << k);
}

void toggleBit(int &n, int k) {
    n ^= (1 << k);
}

void changeBitTo(int &n, int k, int b) {
    n ^= (-b ^ n) & (1 << k);
}

template<typename T>
void printBin(const T& t) {
    for(int i = sizeof(T) * 8 - 1; i >= 0; i--)
        cout << giveMeBit(t, i);
    cout << "\n";
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    bitset<32> bset1;
    bitset<32> bset2(20);
    bitset<32> bset3(string("1100"));

    cout << bset1 << "\n"; // 00000000000000000000000000000000
    cout << bset2 << "\n"; // 00000000000000000000000000010100
    cout << bset3 << "\n"; // 00000000000000000000000000001100

    bitset<8> set8;
    set8[1] = 1; // 00000010
    set8[4] = set8[1]; // 00010010
    cout << set8 << "\n";
    cout << set8.count() << "\n"; // 1's in the set
    cout << set8.size() - set8.count() << "\n"; // 0's in the set

    if(set8.any())
        cout << "There are 1's in the set\n";

    if(set8.none())
        cout << "There are no 1's in the set\n";

    cout << set8.set() << "\n"; // set all bits to 1
    cout << set8.set(4, 0) << "\n"; // set bit 4 to 0
    cout << set8.set(4) << "\n"; // set bit 4 to 1

    cout << set8.reset() << "\n"; // set all bits to 0
    cout << set8.reset(4) << "\n"; // set bit 4 to 0

    cout << set8.flip() << "\n"; // flip all bits
    cout << set8.flip(4) << "\n"; // flip bit 4

    cout << 100 << " = " << bitset<8>(100) << "\n"; // 100 in binary

    bitset<4> bset1(9); // bset1 contains 1001
    bitset<4> bset2(3); // bset2 contains 0011
  
    // comparison operator
    cout << (bset1 == bset2) << endl; // false 0
    cout << (bset1 != bset2) << endl; // true  1
  
    // bitwise operation and assignment
    cout << (bset1 ^= bset2) << endl; // 1010
    cout << (bset1 &= bset2) << endl; // 0010
    cout << (bset1 |= bset2) << endl; // 0011
  
    // left and right shifting
    cout << (bset1 <<= 2) << endl; // 1100
    cout << (bset1 >>= 1) << endl; // 0110
  
    // not operator
    cout << (~bset2) << endl; // 1100
  
    // bitwise operator
    cout << (bset1 & bset2) << endl; // 0010
    cout << (bset1 | bset2) << endl; // 0111
    cout << (bset1 ^ bset2) << endl; // 0101

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}
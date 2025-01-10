#include <bits/stdc++.h>
using namespace std;

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  unordered_map<char, int> mp;

  for (auto c : s)
    mp[c]++;
    
  string p = "";
  vector<string> keys = {"1", "2", "3"};
  
  for(auto key : keys)
    while (mp[key[0]]--) 
        p += key + "+";

  p.pop_back();
  cout << p << "\n";

  return 0;
  
}  
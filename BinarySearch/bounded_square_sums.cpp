int solve(vector<int>& a, vector<int>& b, int lower, int upper) {
    
    for(int i = 0; i < a.size(); i++)
        a[i] = a[i] * a[i];

    for(int i = 0; i < b.size(); i++)
        b[i] = b[i] * b[i];

    sort(a.begin(), a.end());

    int ans = 0;

    for(int i = 0; i < b.size(); i++) {

        int low = upper_bound(a.begin(), a.end(), lower - b[i] - 1) - a.begin();
        int upp = upper_bound(a.begin(), a.end(), upper - b[i]) - a.begin();

        ans += upp - low;
    }

    return ans;

}
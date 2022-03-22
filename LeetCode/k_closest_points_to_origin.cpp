class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double,vector<int>>> pq;
        vector<vector<int>> ans;
        
        for(int i = 0; i < k; i++)
            pq.push({sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])), points[i]});
                
        for(int i = k; i < points.size(); i++) 
            if(pq.top().first > sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]))){
                pq.pop();
                pq.push({sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1])), points[i]});
            }

        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};
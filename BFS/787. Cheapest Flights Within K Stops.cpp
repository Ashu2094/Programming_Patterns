class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int, int>>> adj(n);
            for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        
        vector<long>dist(n,INT_MAX);
        queue<pair<int,long>>q;
        q.push({src,0});
        int stops=0;
        while(q.size() and stops<=k){
            int size = q.size();
            for(int i=1;i<=size;i++){
                auto node = q.front().first;
                auto distance = q.front().second;
                q.pop();
                for(auto x:adj[node]){ //x is pair
                    int y = x.first;
                    int dist_to_y = x.second;
                    if((long)((long)dist_to_y + (long)distance)>=dist[y]) continue;
                    dist[y] = dist_to_y + distance;
                    q.push({y,dist[y]});
                }
            }
            stops++;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

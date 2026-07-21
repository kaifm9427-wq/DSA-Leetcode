class Solution {
public:
    typedef pair<int,pair<int,int>> P;

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
        }

        queue<P> pq;

        // {stops, {node, cost}}
        pq.push({0,{src,0}});

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        while(!pq.empty()){
            int stop = pq.front().first;
            int node = pq.front().second.first;
            int d = pq.front().second.second;
            pq.pop();

            if(stop > k) continue;

            for(auto it : adj[node]){
                int newD = it.second;
                int newNode = it.first;

                if(d + newD < dist[newNode]){
                    dist[newNode] = d + newD;
                    pq.push({stop + 1,{newNode,d + newD}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
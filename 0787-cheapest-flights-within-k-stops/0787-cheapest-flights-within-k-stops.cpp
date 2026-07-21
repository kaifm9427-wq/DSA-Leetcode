class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{src,k+1}});
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        dist[src][k+1]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second.first;
            int stop=pq.top().second.second;
            pq.pop();
            if(node==dst){
                return d;
            }
            if(d>dist[node][stop]) continue;
            if(stop==0) continue;
            if(stop){
                for(auto it:adj[node]){
                    int newD=it.second;
                    int newNode=it.first;
                    if(newD+d<dist[newNode][stop-1]){
                        dist[newNode][stop-1]=d+newD;
                        pq.push({d+newD,{newNode,stop-1}});
                    }
                }
            }
        }
        return -1;
    }
};
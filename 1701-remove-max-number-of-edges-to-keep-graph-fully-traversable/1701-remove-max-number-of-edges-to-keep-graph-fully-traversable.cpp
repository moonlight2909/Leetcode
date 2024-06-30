class DSU {
public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int Find(int x){
        return parent[x] = parent[x]==x?x:Find(parent[x]);
    }
    bool Union(int x,int y){
        int xset = Find(x),yset=Find(y);
        if(xset!=yset){
            rank[xset] < rank[yset] ? parent[xset] = yset : parent[yset] = xset;
            rank[xset] += rank[xset] == rank[yset];
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[&](auto const &a, auto const &b){
            return a[0]>b[0];
        });
        DSU dsu_alice(n+1);
        DSU dsu_bob(n+1);
        int remove_edge = 0;
        int alice_count = 0;
        int bob_count = 0;
        for(auto ele : edges){
            if(ele[0]==3){
                if(dsu_alice.Union(ele[1],ele[2])){
                    dsu_bob.Union(ele[1],ele[2]);
                    alice_count++;
                    bob_count++;
                }
                else{
                    remove_edge++;
                }
            }
            else if(ele[0]==2){
                if(dsu_bob.Union(ele[1],ele[2])){
                    bob_count++;
                }
                else{
                    remove_edge++;
                }
            }
            else{
                if(dsu_alice.Union(ele[1],ele[2])){
                    alice_count++;
                }
                else{
                    remove_edge++;
                }
            }
        }
        return (bob_count == n-1 and alice_count == n-1) ? remove_edge : -1;
    }
};
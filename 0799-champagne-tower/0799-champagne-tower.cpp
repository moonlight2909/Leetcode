class Solution {
public:
    double champagneTower(int poured, int n, int m) {
        if(n==0 && m==0) return min(poured,1);
        vector<double> v;
        v.push_back(poured);
        for(int i=0;i<n;i++){
            v.push_back(0);
            for(int j=i;j>=0;j--){
                v[j+1] = v[j+1] + max(0.0,(v[j]-1)/2);
                v[j] = max(0.0,(v[j]-1)/2);
            }
           
            if(i==n-1) return min(1.0,v[m]);
        }
        return 0;
    }
};
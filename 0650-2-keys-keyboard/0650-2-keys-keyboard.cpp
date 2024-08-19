class Solution {
public:
    int f(int i,int n,int paste){
        if(i==n){
            return 0;
        }
        if(i>n){
            return 1e9;
        }
        return 1+min(1+f(2*i,n,i),f(i+paste,n,paste));
    }
    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }
        return f(1,n,1)+1;
    }
};
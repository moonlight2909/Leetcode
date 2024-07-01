class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int k = 3;
        int n = arr.size();
        int count = 0;
        for(int i=0;i<=n-k;i++){
            for(int j=i;j<k+i;j++){
                if(arr[j]%2!=0){
                    count++;
                }
            }
            if(count==3){
                return true;
            }
            count = 0;
        }
        return false;
        // int n = arr.size();
        // int count = 0;
        // for(int i=0;i<n;i++){
        //     if(arr[i]%2!=0){
        //         count++;
        //     }
        //     else if(count<3 and arr[i]%2==0){
        //         count=0;
        //     }
        // }
        // if(count>=3){
        //     return true;
        // }
        // return false;
    }
};
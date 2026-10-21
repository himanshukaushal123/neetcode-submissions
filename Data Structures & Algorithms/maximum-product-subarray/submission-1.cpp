class Solution {
public:
    //The key insight is that a negative number at either end can make a prefix or suffix product negative, even when the elements between it and the other end have a large positive product.


    int maxProduct(vector<int>& nums) {
       int res=INT_MIN;
       int n=nums.size();
       int curr=1;
       for(int i=0;i<n;i++){
            curr=curr*nums[i];
            res=max(res,curr);
            if(curr==0)curr=1;
        }
        curr=1;
        for(int i=n-1;i>=0;i--){
            curr=curr*nums[i];
            res=max(res,curr);
            if(curr==0)curr=1;
        }
        return res;
    }
};

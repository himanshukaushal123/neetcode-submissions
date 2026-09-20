class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>>maxHeap;
        for(auto num:stones){
            maxHeap.push(num);
        }
        while(maxHeap.size()>1){
            int frist=maxHeap.top();
            maxHeap.pop();
            int second=maxHeap.top();
            maxHeap.pop();
            int diff=frist-second;
            if(diff){
                maxHeap.push(diff);
            }
        }
        if(maxHeap.size()==1)return maxHeap.top();
        else return 0;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char, int> ump;
        priority_queue<int> maxHeap;

        // Count frequency of each task
        for (char task : tasks) {
            ump[task]++;
        }

        // Put frequencies into max heap
        for (auto it = ump.begin(); it != ump.end(); ++it) {
            maxHeap.push(it->second);
        }

        int time=0;

        while(!maxHeap.empty()){
            vector<int>temp;
            // Process at most n + 1 different tasks
            for(int i=0;i<=n;i++){
                if(!maxHeap.empty()){
                    int count=maxHeap.top();
                    maxHeap.pop();
                    count--;
                    // One CPU slot is consumed
                    time++;
                    if(count>0){
                        temp.push_back(count);
                    }
                }else{
                    // no task available sit idle
                    if(!temp.empty()){
                        time++;
                    }
                    else{
                        break;
                    }
                }
            }
            // put the remaining tasks back
            for(int count : temp){
                maxHeap.push(count);
            }
        }
        return time;
    }
};
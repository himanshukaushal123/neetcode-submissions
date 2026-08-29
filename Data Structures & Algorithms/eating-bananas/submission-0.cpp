class Solution {
public:
    long long total_hours_needed(const vector<int>&piles, int k){
        long long total_hours=0;
        for(auto pile:piles){
            total_hours+=ceil(double(pile)/k);
        }
        return total_hours;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //find the max value in the piles array
        int max_speed=INT_MIN;
        for(auto pile:piles){
            max_speed=max(max_speed,pile);
        }

        int left=1;
        int right=max_speed;
        int min_speed=0;
        while(left<=right){
            int mid=left+(right-left)/2;

            long long total_hours=total_hours_needed(piles,mid);
            if(total_hours<=h){
                min_speed=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return min_speed;
    }
};

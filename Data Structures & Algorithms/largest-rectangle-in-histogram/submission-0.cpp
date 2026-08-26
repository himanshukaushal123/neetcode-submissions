class Solution {
public:
    vector<int>next_smallest_to_right(vector<int> & heights){
        stack<int>st;
        vector<int>ans;
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() &&  heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())ans.push_back(st.top());
            else ans.push_back(n);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int>next_smallest_to_left(vector<int> & heights){
        stack<int>st;
        vector<int>ans;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())ans.push_back(st.top());
            else ans.push_back(-1);
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>NSR;
        vector<int>NSL;
        NSR=next_smallest_to_right(heights);
        NSL=next_smallest_to_left(heights);
        int n=heights.size();
        int max_area=0;
        for(int i=0;i<n;i++){
            max_area=max(max_area,heights[i]*(NSR[i]-NSL[i]-1));
        }       
        return max_area;
    }
};

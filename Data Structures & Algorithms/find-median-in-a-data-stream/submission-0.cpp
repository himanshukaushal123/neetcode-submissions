class MedianFinder {
public:
    priority_queue<int> maxHeap;  // smaller half
    priority_queue<int, vector<int>, greater<int>> minHeap;  // larger half

    MedianFinder() {
    }
    
    void addNum(int num) {
        // Add to maxHeap first
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

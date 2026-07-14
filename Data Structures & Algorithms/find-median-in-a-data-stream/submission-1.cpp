class MedianFinder {
public:
    priority_queue<int> mxhp;   // smaller half
    priority_queue<int, vector<int>, greater<int>> mnhp; // larger half

    MedianFinder() {}

    void addNum(int num) {

        if (mxhp.empty() || num <= mxhp.top())
            mxhp.push(num);
        else
            mnhp.push(num);

        // Balance heaps
        if (mxhp.size() > mnhp.size() + 1) {
            mnhp.push(mxhp.top());
            mxhp.pop();
        }
        else if (mnhp.size() > mxhp.size() + 1) {
            mxhp.push(mnhp.top());
            mnhp.pop();
        }
    }

    double findMedian() {

        if (mxhp.size() == mnhp.size())
            return (mxhp.top() + mnhp.top()) / 2.0;

        if (mxhp.size() > mnhp.size())
            return mxhp.top();

        return mnhp.top();
    }
};
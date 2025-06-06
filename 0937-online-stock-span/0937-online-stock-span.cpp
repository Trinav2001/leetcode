class StockSpanner {

private:
    vector<int> arr;

public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int i = arr.size() - 2;
        while(i >= 0 && arr[i] <= price) --i;
        return arr.size() - 1 - i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
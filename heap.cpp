class Solution {
public:
    void up(vector<int>& heap,int i){
        while(i>=0&&heap[i]<heap[(i-1)/2])
        {
            swap(heap[i],heap[(i-1)/2]);
            i=(i-1)/2;
        }
        if (i<=0) return;
    }
    void down(vector<int>& heap,int i){
        while(true)
        {
            int left = i*2+1<heap.size()? heap[i*2+1]:10001; // 小根堆 大根堆的时候 设置为 INT_MIN；
            int right = i*2+2<heap.size()? heap[i*2+2]:10001;
            if(left<=right){
                if (heap[i]>left) {
                    swap(heap[i],heap[i*2+1]);
                    i=i*2+1;
                } else{
                    break;
                }
            }else
            {
                if (heap[i]>right) {
                    swap(heap[i],heap[i*2+2]);
                    i=i*2+2;
                } else{
                    break;
                }
            }
        }
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> heap;
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            heap.push_back(arr[i]);
            up(heap,i);
        }
        int count=0;
        while(count<k)
        {   
            int n=heap.size()-1;
            ans.push_back(heap[0]);
            count++;
            swap(heap[0],heap[n]);
            heap.pop_back();
            down(heap,0);
        }
        return ans;
    }
};
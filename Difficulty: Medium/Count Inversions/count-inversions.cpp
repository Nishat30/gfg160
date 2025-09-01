class Solution {
  public:
    void merge(vector<int> &arr,int left,int mid,int right,int &count)
    {
        int j = mid+1;
        for(int i=left;i<=mid;i++)
        {
            while(j<=right && arr[i] > arr[j])
                j++;
            count +=(j-(mid+1));
        }
        sort(arr.begin()+left,arr.begin()+right+1);
    }
    
    void mergeSort(vector<int> &arr,int start,int end,int &count)
    {
        if(start >= end) return;
        
        int mid = start + (end - start)/2;
        mergeSort(arr,start,mid,count);
        mergeSort(arr,mid+1,end,count);
        merge(arr,start,mid,end,count);
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int count = 0;
        mergeSort(arr,0,arr.size()-1,count);
        return count;
    }
};

class Solution {
public:
    void swapEl(vector<int>& nums1, vector<int>& nums2,int l, int r){
        if(nums1[l]>nums2[r]){
            swap(nums1[l], nums2[r]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=(m+n);
        int gap=(len/2)+(len%2);
        while(gap>0){
            int l=0;
            int r=l+gap;
            while(r<len){
                if(l<m && r>=m){ //arr1 and arr2
                    swapEl(nums1, nums2, l, r-m);
                }else if(l>=m){ //arr2 and arr2
                    swapEl(nums2, nums2, l-m,r-m);
                }else{
                    swapEl(nums1, nums1, l, r);
                }
                l++;
                r++;
            }
            if(gap==1) break;
            gap=(gap/2)+(gap%2);
        }
        for(int i=m; i<m+n; i++){
            nums1[i]=nums2[i-m];
        }
    }
};
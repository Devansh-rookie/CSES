double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    long long n_check= nums2[0];
    long long s=0,l,mid,index;
    l=nums1Size;
    mid =(s+l)/2;
    while(l>=s){
        if(nums1[mid]>n_check) l=mid-1;
        else if (nums1[mid]<n_check) s=mid+1;
        else{
            index= mid;
            break;
        }
        mid = (s+l)/2;
    }
    
    for(long long i=nums1Size;i>index;i++){
        
    }

    if ((nums1Size+nums2Size)%2==0) return(nums1[(nums1Size+nums2Size)/2-1]+nums1[(nums1Size+nums2Size)/2]);
    else return(nums1[nums1Size+nums2Size]);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int i;
    int *arr=(int*)malloc(numsSize*sizeof(int));
    arr[0]=nums[0];
    *returnSize = numsSize;
    for(i=0;i<numsSize;i++)
    {       
            if(i!=0)
            arr[i]=nums[i]+arr[i-1];
    }
    
    
    
    return arr;

}
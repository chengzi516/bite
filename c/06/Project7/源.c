#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
int removeDuplicates(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] == nums[j])
            {
                k++;
                for (int r = j; r < numsSize; r++)
                {
                    if (r == numsSize - 1)
                    {
                        nums[r]=10001;
                    }
                    else
                    {
                        nums[r] = nums[r + 1];
                    }
                }
            }
        }
    }
    return numsSize - k;
}
int main()
{
    int arr[] = { 0,0,1,1,1,2,2,3,3,4 };

    int a = removeDuplicates(arr, 3);


}
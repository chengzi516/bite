#define _CRT_SECURE_NO_WARNINGS 1
/*
����˼·��ʹ��������ת������������תk��
1. ��������ת
2. ��ת������[0, k - 1]
3. ��ת������[k, size - 1]
*/
void reverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;

        ++begin;
        --end;
    }
}

// �������õ���˼·
void rotate(int* nums, int numsSize, int k) {
    if (k > numsSize)
    {
        k %= numsSize;
    }

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}
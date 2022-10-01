#include "algorithm.h"

// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int *result= (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    memset(result, -1, 2 * sizeof(int));

    int left = 0, right = numsSize - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target)
            break;
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (left > right)
        return result;


    for (left = mid-1; left >= 0; left--) {
        if (nums[left] < target)
            break;
    }
    for (right = mid+1; right < numsSize; right++) {
        if (nums[right] > target)
            break;
    }

    result[0] = left + 1;
    result[1] = right - 1;

    return result;
}
// 704. Binary Search
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid;

    if (NULL == nums || numsSize < 1)
        return -1;

    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}
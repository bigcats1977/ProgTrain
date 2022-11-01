#pragma once

#include "general.h"

// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
// 20. Valid Parentheses
bool isValid(char* s);
// 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head);
// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize);
// 27. Remove Element
int removeElement(int* nums, int numsSize, int val);
// 28. Find the Index of the First Occurrence in a String
int strStr(char* haystack, char* needle);
// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
// 35. Search Insert Position
int searchInsert(int* nums, int numsSize, int target);
// 49. Group Anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes);
// 53. Maximum Subarray
int maxSubArray(int* nums, int numsSize);
// 69. Sqrt(x)
int mySqrt(int x);
// 76. Minimum Window Substring
char* minWindow(char* s, char* t);
// 88. Merge Sorted Array
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
// 142. Linked List Cycle II
struct ListNode* detectCycle(struct ListNode* head);
// 151. Reverse Words in a String
char* reverseWords(char* s);
// 160. Intersection of Two Linked Lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);
// 167. Two Sum II - Input Array Is Sorted
int* twoSumII(int* numbers, int numbersSize, int target, int* returnSize);
// 189. Rotate Array
void rotate(int* nums, int numsSize, int k);
// 202. Happy Number
bool isHappy(int n);
// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val);
// 205. Isomorphic Strings
bool isIsomorphic(char* s, char* t);
// 206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head);
// 209. Minimum Size Subarray Sum
int minSubArrayLen(int target, int* nums, int numsSize);
// 217. Contains Duplicate
bool containsDuplicate(int* nums, int numsSize);
// 242. Valid Anagram
bool isAnagram(char* s, char* t);
// 278. First Bad Version
int firstBadVersion(int n);
// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize);
// 344. Reverse String
void reverseString(char* s, int sSize);
// 349. Intersection of Two Arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
// 350. Intersection of Two Arrays II
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
// 367. Valid Perfect Square
bool isPerfectSquare(int num);
// 383. Ransom Note
bool canConstruct(char* ransomNote, char* magazine);
// 392. Is Subsequence
bool isSubsequence(char* s, char* t);
// 523. Continuous Subarray Sum
bool checkSubarraySum(int* nums, int numsSize, int k);
// 541. Reverse String II
char* reverseStr(char* s, int k);
// 704. Binary Search
int search(int* nums, int numsSize, int target);
// 707. Design Linked List
// MyLinkedList
// 724. Find Pivot Index
int pivotIndex(int* nums, int numsSize);
// 766. Toeplitz Matrix
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize);
// 844. Backspace String Compare
bool backspaceCompare(char* s, char* t);
// 904. Fruit Into Baskets
int totalFruit(int* fruits, int fruitsSize);
// 977. Squares of a Sorted Array
int* sortedSquares(int* nums, int numsSize, int* returnSize);
// 1047. Remove All Adjacent Duplicates In String
char* removeDuplicates(char* s);
// 1239. Maximum Length of a Concatenated String with Unique Characters
int maxLength(char** arr, int arrSize);
// 1480. Running Sum of 1d Array
int* runningSum(int* nums, int numsSize, int* returnSize);
// 1662. Check If Two String Arrays are Equivalent
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size);
// 1832. Check if the Sentence Is Pangram
bool checkIfPangram(char* sentence);
// ½£Ö¸ Offer 58 - II.×óÐý×ª×Ö·û´®
string reverseLeftWords(string s, int n);
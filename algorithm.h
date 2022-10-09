#pragma once

#include "general.h"

// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
// 20. Valid Parentheses
bool isValid(char* s);
// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head);
// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize);
// 27. Remove Element
int removeElement(int* nums, int numsSize, int val);
// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
// 35. Search Insert Position
int searchInsert(int* nums, int numsSize, int target);
// 69. Sqrt(x)
int mySqrt(int x);
// 76. Minimum Window Substring
char* minWindow(char* s, char* t);
// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val);
// 206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head);
// 209. Minimum Size Subarray Sum
int minSubArrayLen(int target, int* nums, int numsSize);
// 242. Valid Anagram
bool isAnagram(char* s, char* t);
// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize);
// 367. Valid Perfect Square
bool isPerfectSquare(int num);
// 383. Ransom Note
bool canConstruct(char* ransomNote, char* magazine);
// 704. Binary Search
int search(int* nums, int numsSize, int target);
// 707. Design Linked List
// MyLinkedList
// 844. Backspace String Compare
bool backspaceCompare(char* s, char* t);
// 904. Fruit Into Baskets
int totalFruit(int* fruits, int fruitsSize);
// 977. Squares of a Sorted Array
int* sortedSquares(int* nums, int numsSize, int* returnSize);
#pragma once

#include "general.h"

// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s);
// 5. Longest Palindromic Substring
char* longestPalindromeI(char* s);
// 7. Reverse Integer
int reverse(int x);
// 11. Container With Most Water
int maxArea(int* height, int heightSize);
// 15. 3Sum
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 17. Letter Combinations of a Phone Number
char** letterCombinations(char* digits, int* returnSize);
// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
// 20. Valid Parentheses
bool isValid(char* s);
// 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head);
// 25. Reverse Nodes in k - Group
struct ListNode* reverseKGroup(struct ListNode* head, int k);
// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize);
// 27. Remove Element
int removeElement(int* nums, int numsSize, int val);
// 28. Find the Index of the First Occurrence in a String
int strStr(char* haystack, char* needle);
// 33. Search in Rotated Sorted Array
int searchRotated(int* nums, int numsSize, int target);
// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
// 35. Search Insert Position
int searchInsert(int* nums, int numsSize, int target);
// 36. Valid Sudoku
bool isValidSudoku(char** board, int boardSize, int* boardColSize);
// 39. Combination Sum
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
// 40. Combination Sum II
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
// 43. Multiply Strings
char* multiply(char* num1, char* num2);
// 46. Permutations
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 48. Rotate Image
void rotate(int** matrix, int matrixSize, int* matrixColSize);
// 49. Group Anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes);
// 53. Maximum Subarray
int maxSubArray(int* nums, int numsSize);
// 56. Merge Intervals
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
// 59. Spiral Matrix II
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);
// 62. Unique Paths
int uniquePaths(int m, int n);
// 63. Unique Paths II
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
// 69. Sqrt(x)
int mySqrt(int x);
// 70. Climbing Stairs
int climbStairs(int n);
// 74. Search a 2D Matrix
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);
// 75. Sort Colors
void sortColors(int* nums, int numsSize);
// 76. Minimum Window Substring
char* minWindow(char* s, char* t);
// 77. Combinations
int** combine(int n, int k, int* returnSize, int** returnColumnSizes);
// 78. Subsets
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 79. Word Search
bool exist(char** board, int boardSize, int* boardColSize, char* word);
// 82. Remove Duplicates from Sorted List II
struct ListNode* deleteDuplicatesII(struct ListNode* head);
// 83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head);
// 88. Merge Sorted Array
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
// 94. Binary Tree Inorder Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize);
// 98. Validate Binary Search Tree
bool isValidBST(struct TreeNode* root);
// 101. Symmetric Tree
bool isSymmetric(struct TreeNode* root);
// 102. Binary Tree Level Order Traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
// 103. Binary Tree Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
// 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode* root);
// 105. Construct Binary Tree from Preorder and Inorder Traversal
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);
// 106. Construct Binary Tree from Inorder and Postorder Traversal
struct TreeNode* buildTree106(int* inorder, int inorderSize, int* postorder, int postorderSize);
// 108. Convert Sorted Array to Binary Search Tree
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
// 112. Path Sum
bool hasPathSum(struct TreeNode* root, int targetSum);
// 113. Path Sum II
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes);
// 116. Populating Next Right Pointers in Each Node
struct Node* connect(struct Node* root);
// 117. Populating Next Right Pointers in Each Node II
struct Node* connect2(struct Node* root);
// 118. Pascal's Triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes);
// 119. Pascal's Triangle II
int* getRow(int rowIndex, int* returnSize);
// 120. Triangle
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize);
// 121. Best Time to Buy and Sell Stock
int maxProfit(int* prices, int pricesSize);
// 130. Surrounded Regions
void solve(char** board, int boardSize, int* boardColSize);
// 131. Palindrome Partitioning
char*** partition(char* s, int* returnSize, int** returnColumnSizes);
// 134. Gas Station
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize);
// 136. Single Number
int singleNumber(int* nums, int numsSize);
// 141. Linked List Cycle
bool hasCycle(struct ListNode* head);
// 142. Linked List Cycle II
struct ListNode* detectCycle(struct ListNode* head);
// 143. Reorder List
void reorderList(struct ListNode* head);
// 144. Binary Tree Preorder Traversal
int* preorderTraversal(struct TreeNode* root, int* returnSize);
// 145. Binary Tree Postorder Traversal
int* postorderTraversal(struct TreeNode* root, int* returnSize);
// 150. Evaluate Reverse Polish Notation
int evalRPN(char ** tokens, int tokensSize);
// 151. Reverse Words in a String
char* reverseWords(char* s);
// 153. Find Minimum in Rotated Sorted Array
int findMin(int* nums, int numsSize);
// 155. Min Stack

// 160. Intersection of Two Linked Lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);
// 162. Find Peak Element
int findPeakElement(int* nums, int numsSize);
// 167. Two Sum II - Input Array Is Sorted
int* twoSumII(int* numbers, int numbersSize, int target, int* returnSize);
// 169. Majority Element
int majorityElement(int* nums, int numsSize);
// 187. Repeated DNA Sequences
char** findRepeatedDnaSequences(char* s, int* returnSize);
// 189. Rotate Array
void rotate(int* nums, int numsSize, int k);
// 190. Reverse Bits
uint32_t reverseBits(uint32_t n);
// 191. Number of 1 Bits
int hammingWeight(uint32_t n);
// 198. House Robber
int rob(int* nums, int numsSize);
// 199. Binary Tree Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize);
// 200. Number of Islands
int numIslands(char** grid, int gridSize, int* gridColSize);
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
// 212. Word Search II
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize);
// 215. Kth Largest Element in an Array
int findKthLargest(int* nums, int numsSize, int k);
// 216. Combination Sum III
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes);
// 217. Contains Duplicate
bool containsDuplicate(int* nums, int numsSize);
// 222. Count Complete Tree Nodes
int countNodes(struct TreeNode* root);
// 223. Rectangle Area
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
// 226. Invert Binary Tree
struct TreeNode* invertTree(struct TreeNode* root);
// 230. Kth Smallest Element in a BST
int kthSmallest(struct TreeNode* root, int k);
// 231. Power of Two
bool isPowerOfTwo(int n);
// 232. Implement Queue using Stacks
// 235. Lowest Common Ancestor of a Binary Search Tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);
// 236. Lowest Common Ancestor of a Binary Tree
struct TreeNode* lowestCommonAncestorBT(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);
// 238. Product of Array Except Self
int* productExceptSelf(int* nums, int numsSize, int* returnSize);
// 239. Sliding Window Maximum
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);
// 240. Search a 2D Matrix II
//bool searchMatrixII(int** matrix, int matrixSize, int* matrixColSize, int target);
bool searchMatrixII(vector<vector<int>> matrix, int matrixSize, int* matrixColSize, int target);
// 242. Valid Anagram
bool isAnagram(char* s, char* t);
// 257. Binary Tree Paths
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
// 263. Ugly Number
bool isUgly(int n);
// 278. First Bad Version
int firstBadVersion(int n);
// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize);
// 290. Word Pattern
bool wordPattern(char* pattern, char* s);
// 297. Serialize and Deserialize Binary Tree
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root);
/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data);
// 299. Bulls and Cows
char* getHint(char* secret, char* guess);
// 344. Reverse String
void reverseString(char* s, int sSize);
// 345. Reverse Vowels of a String;
char* reverseVowels(char* s);
// 347. Top K Frequent Elements
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize);
// 349. Intersection of Two Arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
// 350. Intersection of Two Arrays II
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
// 367. Valid Perfect Square
bool isPerfectSquare(int num);
// 374. Guess Number Higher or Lower
int guessNumber(int n);
// 383. Ransom Note
bool canConstruct(char* ransomNote, char* magazine);
// 387. First Unique Character in a String
int firstUniqChar(char* s);
// 392. Is Subsequence
bool isSubsequence(char* s, char* t);
// 394. Decode String
char* decodeString(char* s);
// 404. Sum of Left Leaves
int sumOfLeftLeaves(struct TreeNode* root);
// 409. Longest Palindrome
int longestPalindrome(char* s);
// 415. Add Strings
char* addStrings(char* num1, char* num2);
// 424. Longest Repeating Character Replacement
int characterReplacement(char* s, int k);
// 435. Non - overlapping Intervals
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize);
// 438. Find All Anagrams in a String
int* findAnagrams(char* s, char* p, int* returnSize);
// 450. Delete Node in a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key);
// 501. Find Mode in Binary Search Tree
int* findMode(struct TreeNode* root, int* returnSize);
// 509. Fibonacci Number
int fib(int n);
// 523. Continuous Subarray Sum
bool checkSubarraySum(int* nums, int numsSize, int k);
// 530. Minimum Absolute Difference in BST
void traverse(struct TreeNode* root, int* array, int* count);
// 541. Reverse String II
char* reverseStr(char* s, int k);
// 542. 01 Matrix
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes);
// 547. Number of Provinces
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize);
// 557. Reverse Words in a String III
char* reverseWordsIII(char* s);
// 560. Subarray Sum Equals K
int subarraySum(int* nums, int numsSize, int k);
// 566. Reshape the Matrix
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes);
// 567. Permutation in String
bool checkInclusion(char* s1, char* s2);
// 572. Subtree of Another Tree
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot);
// 589. N - ary Tree Preorder Traversal
int* preorder(struct Node* root, int* returnSize);
// 617. Merge Two Binary Trees
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2);
// 653. Two Sum IV - Input is a BST
bool findTarget(struct TreeNode* root, int k);
// 654. Maximum Binary Tree
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize);
// 669. Trim a Binary Search Tree
struct TreeNode* trimBST(struct TreeNode* root, int low, int high);
// 695. Max Area of Island
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize);
// 700. Search in a Binary Search Tree
struct TreeNode* searchBST(struct TreeNode* root, int val);
// 701. Insert into a Binary Search Tree
struct TreeNode* insertIntoBST(struct TreeNode* root, int val);
// 704. Binary Search
int search(int* nums, int numsSize, int target);
// 706. Design HashMap
// myself HashMap
// 707. Design Linked List
// 713. Subarray Product Less Than K
int numSubarrayProductLessThanK(int* nums, int numsSize, int k);
// MyLinkedList
// 724. Find Pivot Index
int pivotIndex(int* nums, int numsSize);
// 733. Flood Fill
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes);
// 746. Min Cost Climbing Stairs
int minCostClimbingStairs(int* cost, int costSize);
// 763. Partition Labels
int* partitionLabels(char* s, int* returnSize);
// 766. Toeplitz Matrix
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize);
// 784. Letter Case Permutation
char** letterCasePermutation(char* s, int* returnSize);
// 797. All Paths From Source to Target
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes);
// 841. Keys and Rooms
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize);
// 844. Backspace String Compare
bool backspaceCompare(char* s, char* t);
// 876. Middle of the Linked List
struct ListNode* middleNode(struct ListNode* head);
// 904. Fruit Into Baskets
int totalFruit(int* fruits, int fruitsSize);
// 944. Delete Columns to Make Sorted
int minDeletionSize(char** strs, int strsSize);
// 977. Squares of a Sorted Array
int* sortedSquares(int* nums, int numsSize, int* returnSize);
// 986. Interval List Intersections
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes);
// 994. Rotting Oranges
int orangesRotting(int** grid, int gridSize, int* gridColSize);
// 997. Find the Town Judge
int findJudge(int n, int** trust, int trustSize, int* trustColSize);
// 1046. Last Stone Weight
int lastStoneWeight(int* stones, int stonesSize);
// 1047. Remove All Adjacent Duplicates In String
char* removeDuplicates(char* s);
// 1071. Greatest Common Divisor of Strings
char* gcdOfStrings(char* str1, char* str2);
// 1091. Shortest Path in Binary Matrix
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize);
// 1143. Longest Common Subsequence
int longestCommonSubsequence(char* text1, char* text2);
// 1239. Maximum Length of a Concatenated String with Unique Characters
int maxLength(char** arr, int arrSize);
// 1249. Minimum Remove to Make Valid Parentheses
char* minRemoveToMakeValid(char* s);
// 1323. Maximum 69 Number
int maximum69Number(int num);
// 1470. Shuffle the Array
int* shuffle(int* nums, int numsSize, int n, int* returnSize);
// 1480. Running Sum of 1d Array
int* runningSum(int* nums, int numsSize, int* returnSize);
// 1544. Make The String Great
char* makeGood(char* s);
// 1557. Minimum Number of Vertices to Reach All Nodes
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize);
// 1657. Determine if Two Strings Are Close
bool closeStrings(char* word1, char* word2);
// 1662. Check If Two String Arrays are Equivalent
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size);
// 1704. Determine if String Halves Are Alike
bool halvesAreAlike(char* s);
// 1823. Find the Winner of the Circular Game
int findTheWinner(int n, int k);
// 1832. Check if the Sentence Is Pangram
bool checkIfPangram(char* sentence);
// 2131. Longest Palindrome by Concatenating Two Letter Words
int longestPalindrome(char** words, int wordsSize);
// ½£Ö¸ Offer 05. Ìæ»»¿Õ¸ñ
char* replacespace(char* s);
// ½£Ö¸ Offer 58 - II.×óÐý×ª×Ö·û´®
string reverseLeftWords(string s, int n);
char* reverseLeftWords(char* s, int n);
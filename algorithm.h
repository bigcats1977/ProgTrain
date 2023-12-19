#pragma once

#include "general.h"

// 1. Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize);
// 2. Add Two Numbers
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2);
// 3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(char* s);
int lengthOfLongestSubstring(string s);
// 4. Median of Two Sorted Arrays
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);
// 5. Longest Palindromic Substring
char* longestPalindromeI(char* s);
string longestPalindromeI(string s);
string longestPalindromeDP(string s);
// 6. Zigzag Conversion
char* convert(char* s, int numRows);
// 7. Reverse Integer
int reverse(int x);
// 8. String to Integer (atoi)
int myAtoi(char* s);
// 9. Palindrome Number
bool isPalindrome(int x);
// 11. Container With Most Water
int maxArea(int* height, int heightSize);
int maxArea(vector<int>& height);
// 12. Integer to Roman
char* intToRoman(int num);
// 13. Roman to Integer
int romanToInt(char* s);
// 14. Longest Common Prefix
char* longestCommonPrefix(char** strs, int strsSize);
string longestCommonPrefix(vector<string>& strs);
// 15. 3Sum
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
vector<vector<int>> threeSum(vector<int>& nums);
// 16. 3Sum Closest
int threeSumClosest(int* nums, int numsSize, int target);
// 17. Letter Combinations of a Phone Number
char** letterCombinations(char* digits, int* returnSize);
vector<string> letterCombinations(string digits);
// 19. Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);
ListNode* removeNthFromEndII(ListNode* head, int n);
// 20. Valid Parentheses
bool isValid(char* s);
// 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
ListNode* mergeTwoListsI(ListNode* list1, ListNode* list2);
// 22. Generate Parentheses
char** generateParenthesis(int n, int* returnSize);
// 23. Merge k Sorted Lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize);
// 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head);
// 25. Reverse Nodes in k - Group
struct ListNode* reverseKGroup(struct ListNode* head, int k);
ListNode* reverseKGroup2(ListNode* head, int k);
// 26. Remove Duplicates from Sorted Array
int removeDuplicates(int* nums, int numsSize);
int removeDuplicates(vector<int>& nums);
// 27. Remove Element
int removeElement(int* nums, int numsSize, int val);
int removeElement(vector<int>& nums, int val);
// 28. Find the Index of the First Occurrence in a String
int strStr(char* haystack, char* needle);
int strStr(string haystack, string needle);
// 33. Search in Rotated Sorted Array
int searchRotated(int* nums, int numsSize, int target);
// 34. Find First and Last Position of Element in Sorted Array
int* searchRange(int* nums, int numsSize, int target, int* returnSize);
vector<int> searchRange(vector<int>& nums, int target);
// 35. Search Insert Position
int searchInsert(int* nums, int numsSize, int target);
// 36. Valid Sudoku
bool isValidSudoku(char** board, int boardSize, int* boardColSize);
bool isValidSudoku(vector<vector<char>>& board);
// 39. Combination Sum
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
// 40. Combination Sum II
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes);
// 42. Trapping Rain Water
int trap(int* height, int heightSize);
// 43. Multiply Strings
char* multiply(char* num1, char* num2);
// 45. Jump Game II
int jumpII(int* nums, int numsSize);
int jumpII(vector<int>& nums);
// 46. Permutations
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
vector<vector<int>> permute(vector<int>& nums);
// 47. Permutations II
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 48. Rotate Image
void rotate(int** matrix, int matrixSize, int* matrixColSize);
void rotate(vector<vector<int>>& matrix);
// 49. Group Anagrams
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes);
vector<vector<string>> groupAnagrams(vector<string>& strs);
// 50. Pow(x, n)
double myPow(double x, int n);
// 53. Maximum Subarray
int maxSubArray(int* nums, int numsSize);
// 54. Spiral Matrix
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
// 55. Jump Game
bool canJump(int* nums, int numsSize);
bool canJump(vector<int>& nums);
// 56. Merge Intervals
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);
vector<vector<int>> merge(vector<vector<int>>& intervals);
// 57. Insert Interval
int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes);
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);
// 58. Length of Last Word
int lengthOfLastWord(string s);
// 59. Spiral Matrix II
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes);
// 61. Rotate List
struct ListNode* rotateRight(struct ListNode* head, int k);
// 62. Unique Paths
int uniquePaths(int m, int n);
int uniquePaths2(int m, int n);
// 63. Unique Paths II
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize);
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
// 64. Minimum Path Sum
int minPathSum(int** grid, int gridSize, int* gridColSize);
// 66. Plus One
int* plusOne(int* digits, int digitsSize, int* returnSize);
// 67. Add Binary
char* addBinary(char* a, char* b);
// 68. Text Justification
vector<string> fullJustify(vector<string>& words, int maxWidth);
// 69. Sqrt(x)
int mySqrt(int x);
// 70. Climbing Stairs
int climbStairs(int n);
// 71. Simplify Path
string simplifyPath(string path);
// 72. Edit Distance
int minDistance(char* word1, char* word2);
// 73. Set Matrix Zeroes
void setZeroes(int** matrix, int matrixSize, int* matrixColSize);
// 74. Search a 2D Matrix
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);
// 75. Sort Colors
void sortColors(int* nums, int numsSize);
// 76. Minimum Window Substring
char* minWindow(char* s, char* t);
string minWindow(string s, string t);
// 77. Combinations
int** combine(int n, int k, int* returnSize, int** returnColumnSizes);
vector<vector<int>> combine(int n, int k);
// 78. Subsets
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 79. Word Search
bool exist(char** board, int boardSize, int* boardColSize, char* word);
// 80. Remove Duplicates from Sorted Array II
int removeDuplicatesII(int* nums, int numsSize);
// 82. Remove Duplicates from Sorted List II
struct ListNode* deleteDuplicatesII(struct ListNode* head);
ListNode* deleteDuplicatesIIP(ListNode* head);
// 83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head);
// 86. Partition List
struct ListNode* partition(struct ListNode* head, int x);
// 88. Merge Sorted Array
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
// 90. Subsets II
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);
// 91. Decode Ways
int numDecodings(char* s);
// 92. Reverse Linked List II
ListNode* reverseBetween(ListNode* head, int left, int right);
// 94. Binary Tree Inorder Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize);
vector<int> inorderTraversal(TreeNode* root);
// 96. Unique Binary Search Trees
int numTrees(int n);
// 97. Interleaving String
bool isInterleave(char* s1, char* s2, char* s3);
// 98. Validate Binary Search Tree
bool isValidBST(struct TreeNode* root);
bool isValidBSTI(TreeNode* root);
// 100. Same Tree
bool isSameTree(struct TreeNode* p, struct TreeNode* q);
bool isSameTree2(TreeNode* p, TreeNode* q);
// 101. Symmetric Tree
bool isSymmetric(struct TreeNode* root);
// 102. Binary Tree Level Order Traversal
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
vector<vector<int>> levelOrder(TreeNode* root);
// 103. Binary Tree Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
// 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode* root);
// 105. Construct Binary Tree from Preorder and Inorder Traversal
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);
// 106. Construct Binary Tree from Inorder and Postorder Traversal
struct TreeNode* buildTree106(int* inorder, int inorderSize, int* postorder, int postorderSize);
// 108. Convert Sorted Array to Binary Search Tree
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
// 110. Balanced Binary Tree
bool isBalanced(struct TreeNode* root);
// 112. Path Sum
bool hasPathSum(struct TreeNode* root, int targetSum);
bool hasPathSumI(TreeNode* root, int targetSum);
// 113. Path Sum II
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes);
// 114. Flatten Binary Tree to Linked List
void flatten(struct TreeNode* root);
// 116. Populating Next Right Pointers in Each Node
struct Node* connect(struct Node* root);
// 117. Populating Next Right Pointers in Each Node II
struct Node* connect2(struct Node* root);
Node* connectII(Node* root);
// 118. Pascal's Triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes);
vector<vector<int>> generate(int numRows);
// 119. Pascal's Triangle II
int* getRow(int rowIndex, int* returnSize);
vector<int> getRow(int rowIndex);
// 120. Triangle
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize);
int minimumTotal(vector<vector<int>>& triangle);
// 121. Best Time to Buy and Sell Stock
int maxProfit(int* prices, int pricesSize);
int maxProfit(vector<int>& prices);
int maxProfitdp(vector<int>& prices);
// 122. Best Time to Buy and Sell Stock II
int maxProfitII(int* prices, int pricesSize);
int maxProfitIIdp(vector<int>& prices);
// 123. Best Time to Buy and Sell Stock III
int maxProfitIII(vector<int>& prices);
// 124. Binary Tree Maximum Path Sum
int maxPathSum(struct TreeNode* root);
// 125. Valid Palindrome
bool isPalindrome(char* s);
// 128. Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums);
// 129. Sum Root to Leaf Numbers
int sumNumbers(struct TreeNode* root);
// 130. Surrounded Regions
void solve(char** board, int boardSize, int* boardColSize);
// 131. Palindrome Partitioning
char*** partition(char* s, int* returnSize, int** returnColumnSizes);
// 133. Clone Graph
GNode* cloneGraph(GNode* node);
// 134. Gas Station
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize);
int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
// 135. Candy
int candy(vector<int>& ratings);
int candy(int* ratings, int ratingsSize);
// 136. Single Number
int singleNumber(int* nums, int numsSize);
// 137. Single Number II
int singleNumberII(int* nums, int numsSize);
// 138. Copy List with Random Pointer
Node* copyRandomList(Node* head);
struct Node* copyRandomListI(struct Node* head);
// 139. Word Break
bool wordBreak(char* s, char** wordDict, int wordDictSize);
bool wordBreak(string s, vector<string>&wordDict);
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
// 146. LRU Cache

// 148. Sort List
struct ListNode* sortList(struct ListNode* head);
// 149. Max Points on a Line
int maxPoints(int** points, int pointsSize, int* pointsColSize);
// 150. Evaluate Reverse Polish Notation
int evalRPN(char ** tokens, int tokensSize);
int evalRPN(vector<string>& tokens);
// 151. Reverse Words in a String
char* reverseWords(char* s);
// 152. Maximum Product Subarray
int maxProduct(int* nums, int numsSize);
// 153. Find Minimum in Rotated Sorted Array
int findMin(int* nums, int numsSize);
// 155. Min Stack

// 160. Intersection of Two Linked Lists
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB);
// 162. Find Peak Element
int findPeakElement(int* nums, int numsSize);
// 167. Two Sum II - Input Array Is Sorted
int* twoSumII(int* numbers, int numbersSize, int target, int* returnSize);
vector<int> twoSum(vector<int>& numbers, int target);
// 169. Majority Element
int majorityElement(int* nums, int numsSize);
int majorityElement(vector<int>& nums);
// 172. Factorial Trailing Zeroes
int trailingZeroes(int n);
// 173. Binary Search Tree Iterator

// 187. Repeated DNA Sequences
char** findRepeatedDnaSequences(char* s, int* returnSize);
// 188. Best Time to Buy and Sell Stock IV
int maxProfit(int k, vector<int>&prices);
// 189. Rotate Array
void rotate(int* nums, int numsSize, int k);
void rotate(vector<int>& nums, int k);
// 190. Reverse Bits
uint32_t reverseBits(uint32_t n);
// 191. Number of 1 Bits
int hammingWeight(uint32_t n);
// 198. House Robber
int rob(int* nums, int numsSize);
int rob(vector<int>& nums);
// 199. Binary Tree Right Side View
int* rightSideView(struct TreeNode* root, int* returnSize);
vector<int> rightSideView(TreeNode* root);
// 200. Number of Islands
int numIslands(char** grid, int gridSize, int* gridColSize);
// 201. Bitwise AND of Numbers Range
int rangeBitwiseAnd(int left, int right);
// 202. Happy Number
bool isHappy(int n);
// 203. Remove Linked List Elements
ListNode* removeElements(ListNode* head, int val);
// 205. Isomorphic Strings
bool isIsomorphic(char* s, char* t);
bool isIsomorphic(string s, string t);
// 206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head);
ListNode* reverseList2(ListNode* head);
// 208. Implement Trie (Prefix Tree)

// 209. Minimum Size Subarray Sum
int minSubArrayLen(int target, int* nums, int numsSize);
int minSubArrayLen(int target, vector<int>& nums);
// 210. Course Schedule II
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize);
// 212. Word Search II
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize);
// 213. House Robber II
int rob2(int* nums, int numsSize);
int robCCC(vector<int>& nums);
// 215. Kth Largest Element in an Array
int findKthLargest(int* nums, int numsSize, int k);
// 216. Combination Sum III
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes);
vector<vector<int>> combinationSum3(int k, int n);
// 217. Contains Duplicate
bool containsDuplicate(int* nums, int numsSize);
// 219. Contains Duplicate II
bool containsNearbyDuplicate(vector<int>& nums, int k);
// 221. Maximal Square
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize);
// 222. Count Complete Tree Nodes
int countNodes(struct TreeNode* root);
// 223. Rectangle Area
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2);
// 224. Basic Calculator
int calculate(char* s);
// 226. Invert Binary Tree
struct TreeNode* invertTree(struct TreeNode* root);
// 227. Basic Calculator II
int calculateII(char* s);
// 228. Summary Ranges
char** summaryRanges(int* nums, int numsSize, int* returnSize);
// 229. Majority Element II
int* majorityElement(int* nums, int numsSize, int* returnSize);
// 230. Kth Smallest Element in a BST
int kthSmallest(struct TreeNode* root, int k);
// 231. Power of Two
bool isPowerOfTwo(int n);
// 232. Implement Queue using Stacks
// 234. Palindrome Linked List
bool isPalindrome(struct ListNode* head);
// 235. Lowest Common Ancestor of a Binary Search Tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);
// 236. Lowest Common Ancestor of a Binary Tree
struct TreeNode* lowestCommonAncestorBT(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);
// 238. Product of Array Except Self
int* productExceptSelf(int* nums, int numsSize, int* returnSize);
vector<int> productExceptSelf(vector<int>& nums);
// 239. Sliding Window Maximum
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize);
// 240. Search a 2D Matrix II
//bool searchMatrixII(int** matrix, int matrixSize, int* matrixColSize, int target);
bool searchMatrixII(vector<vector<int>> matrix, int matrixSize, int* matrixColSize, int target);
// 242. Valid Anagram
bool isAnagram(char* s, char* t);
bool isAnagram(string s, string t);
// 257. Binary Tree Paths
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
// 263. Ugly Number
bool isUgly(int n);
// 268. Missing Number
int missingNumber(int* nums, int numsSize);
// 274. H-Index
int hIndex(int* citations, int citationsSize);
// 278. First Bad Version
int firstBadVersion(int n);
// 283. Move Zeroes
void moveZeroes(int* nums, int numsSize);
// 287. Find the Duplicate Number
int findDuplicate(vector<int>&nums);
// 289. Game of Life
void gameOfLife(int** board, int boardSize, int* boardColSize);
// 290. Word Pattern
bool wordPattern(char* pattern, char* s);
bool wordPattern(string pattern, string s);
// 297. Serialize and Deserialize Binary Tree
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root);
/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data);
// 299. Bulls and Cows
char* getHint(char* secret, char* guess);
// 300. Longest Increasing Subsequence
int lengthOfLIS(int* nums, int numsSize);
int lengthOfLIS(vector<int>& nums);
// 316. Remove Duplicate Letters
char* removeDuplicateLetters(char* s);
// 322. Coin Change
int coinChange(int* coins, int coinsSize, int amount);
int coinChange(vector<int>&coins, int amount);
// 328. Odd Even Linked List
struct ListNode* oddEvenList(struct ListNode* head);
// 332. Reconstruct Itinerary
vector<string> findItinerary(vector<vector<string>>&tickets);
// 334. Increasing Triplet Subsequence
bool increasingTriplet(int* nums, int numsSize);
// 337. House Robber III
int rob(struct TreeNode* root);
// 338. Counting Bits
int* countBits(int n, int* returnSize);
// 341. Flatten Nested List Iterator

// 342. Power of Four
bool isPowerOfFour(int n);
// 343. Integer Break
int integerBreak(int n);
int integerBreak2(int n);
// 344. Reverse String
void reverseString(char* s, int sSize);
// 345. Reverse Vowels of a String;
char* reverseVowels(char* s);
string reverseVowels(string s);
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
// 380. Insert Delete GetRandom O(1)

// 383. Ransom Note
bool canConstruct(char* ransomNote, char* magazine);
bool canConstruct(string ransomNote, string magazine);
// 384. Shuffle an Array

// 387. First Unique Character in a String
int firstUniqChar(char* s);
// 389. Find the Difference
char findTheDifference(char* s, char* t);
// 392. Is Subsequence
bool isSubsequence(char* s, char* t);
bool isSubsequence(string s, string t);
// 394. Decode String
char* decodeString(char* s);
string decodeString(string s);
// 399. Evaluate Division
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries);
// 401. Binary Watch
char** readBinaryWatch(int turnedOn, int* returnSize);
// 404. Sum of Left Leaves
int sumOfLeftLeaves(struct TreeNode* root);
// 409. Longest Palindrome
int longestPalindrome(char* s);
// 413. Arithmetic Slices
int numberOfArithmeticSlices(int* nums, int numsSize);
// 415. Add Strings
char* addStrings(char* num1, char* num2);
// 416. Partition Equal Subset Sum
bool canPartition(int* nums, int numsSize);
bool canPartition(vector<int>& nums);
// 417. Pacific Atlantic Water Flow
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes);
// 424. Longest Repeating Character Replacement
int characterReplacement(char* s, int k);
// 433. Minimum Genetic Mutation
int minMutation(string startGene, string endGene, vector<string>& bank);
// 435. Non - overlapping Intervals
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize);
// 437. Path Sum III
int pathSumIII(struct TreeNode* root, int targetSum);
// 438. Find All Anagrams in a String
int* findAnagrams(char* s, char* p, int* returnSize);
// 443. String Compression
int compress(char* chars, int charsSize);
// 450. Delete Node in a BST
struct TreeNode* deleteNode(struct TreeNode* root, int key);
// 452. Minimum Number of Arrows to Burst Balloons
int findMinArrowShots(int** points, int pointsSize, int* pointsColSize);
// 458. Poor Pigs
int poorPigs(int buckets, int minutesToDie, int minutesToTest);
// 459. Repeated Substring Pattern
bool repeatedSubstringPattern(char* s);
// 477. Total Hamming Distance
int totalHammingDistance(int* nums, int numsSize);
// 485. Max Consecutive Ones
int findMaxConsecutiveOnes(int* nums, int numsSize);
// 494. Target Sum
int findTargetSumWays(int* nums, int numsSize, int target);
// 496. Next Greater Element I
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
// 501. Find Mode in Binary Search Tree
int* findMode(struct TreeNode* root, int* returnSize);
vector<int> findMode(TreeNode* root);
// 503. Next Greater Element II
int* nextGreaterElements(int* nums, int numsSize, int* returnSize);
// 509. Fibonacci Number
int fib(int n);
// 515. Find Largest Value in Each Tree Row
int* largestValues(struct TreeNode* root, int* returnSize);
// 516. Longest Palindromic Subsequence
int longestPalindromeSubseq(char* s);
// 523. Continuous Subarray Sum
bool checkSubarraySum(int* nums, int numsSize, int k);
// 530. Minimum Absolute Difference in BST
void traverse(struct TreeNode* root, int* array, int* count);
// 538. Convert BST to Greater Tree
struct TreeNode* convertBST(struct TreeNode* root);
// 541. Reverse String II
char* reverseStr(char* s, int k);
// 542. 01 Matrix
int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes);
// 543. Diameter of Binary Tree
int diameterOfBinaryTree(struct TreeNode* root);
// 547. Number of Provinces
int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize);
// 556. Next Greater Element III
int nextGreaterElement(int n);
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
// 583. Delete Operation for Two Strings
int minDelDistance(char* word1, char* word2);
// 589. N - ary Tree Preorder Traversal
int* preorder(struct Node* root, int* returnSize);
// 605. Can Place Flowers
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);
// 606. Construct String from Binary Tree
string tree2str(TreeNode* root);
// 617. Merge Two Binary Trees
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2);
// 621. Task Scheduler
int leastInterval(char* tasks, int tasksSize, int n);
// 637. Average of Levels in Binary Tree
double* averageOfLevels(struct TreeNode* root, int* returnSize);
// 643. Maximum Average Subarray I
double findMaxAverage(int* nums, int numsSize, int k);
// 647. Palindromic Substrings
int countSubstrings(string s);
// 649. Dota2 Senate
char* predictPartyVictory(char* senate);
// 653. Two Sum IV - Input is a BST
bool findTarget(struct TreeNode* root, int k);
// 654. Maximum Binary Tree
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize);
// 661. Image Smoother
vector<vector<int>> imageSmoother(vector<vector<int>>& img);
// 662. Maximum Width of Binary Tree
int widthOfBinaryTree(struct TreeNode* root);
// 669. Trim a Binary Search Tree
struct TreeNode* trimBST(struct TreeNode* root, int low, int high);
// 673. Number of Longest Increasing Subsequence
int findNumberOfLIS(int* nums, int numsSize);
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
// 714. Best Time to Buy and Sell Stock with Transaction Fee
int maxProfit(int* prices, int pricesSize, int fee);
// MyLinkedList
// 722. Remove Comments
char** removeComments(char** source, int sourceSize, int* returnSize);
// 724. Find Pivot Index
int pivotIndex(int* nums, int numsSize);
int pivotIndex(vector<int>& nums);
// 725. Split Linked List in Parts
vector<ListNode*> splitListToParts(ListNode* head, int k);
// 726. Number of Atoms
string countOfAtoms(string formula);
// 733. Flood Fill
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes);
// 735. Asteroid Collision
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize);
vector<int> asteroidCollision(vector<int>& asteroids);
// 739. Daily Temperatures
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);
// 746. Min Cost Climbing Stairs
int minCostClimbingStairs(int* cost, int costSize);
int minCostClimbingStairs(vector<int>& cost);
// 763. Partition Labels
int* partitionLabels(char* s, int* returnSize);
// 766. Toeplitz Matrix
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize);
// 779. K-th Symbol in Grammar
int kthGrammar(int n, int k);
// 784. Letter Case Permutation
char** letterCasePermutation(char* s, int* returnSize);
// 785. Is Graph Bipartite ?
bool isBipartite(int** graph, int graphSize, int* graphColSize);
// 792. Number of Matching Subsequences
int numMatchingSubseq(char* s, char** words, int wordsSize);
// 797. All Paths From Source to Target
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes);
// 799. Champagne Tower
double champagneTower(int poured, int query_row, int query_glass);
// 823. Binary Trees With Factors
int numFactoredBinaryTrees(int* arr, int arrSize);
// 841. Keys and Rooms
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize);
// 844. Backspace String Compare
bool backspaceCompare(char* s, char* t);
bool backspaceCompare(string s, string t);
// 872. Leaf - Similar Trees
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2);
// 876. Middle of the Linked List
struct ListNode* middleNode(struct ListNode* head);
// 904. Fruit Into Baskets
int totalFruit(int* fruits, int fruitsSize);
// 905. Sort Array By Parity
int* sortArrayByParity(int* nums, int numsSize, int* returnSize);
// 909. Snakes and Ladders
int snakesAndLadders(vector<vector<int>>& board);
int snakesAndLaddersI(vector<vector<int>>& board);
// 935. Knight Dialer
int knightDialer(int n);
// 944. Delete Columns to Make Sorted
int minDeletionSize(char** strs, int strsSize);
// 946. Validate Stack Sequences
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize);
// 947. Most Stones Removed with Same Row or Column
int removeStones(int** stones, int stonesSize, int* stonesColSize);
// 977. Squares of a Sorted Array
int* sortedSquares(int* nums, int numsSize, int* returnSize);
// 986. Interval List Intersections
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes);
// 994. Rotting Oranges
int orangesRotting(int** grid, int gridSize, int* gridColSize);
// 997. Find the Town Judge
int findJudge(int n, int** trust, int trustSize, int* trustColSize);
// 1004. Max Consecutive Ones III
int longestOnes(int* nums, int numsSize, int k);
// 1027. Longest Arithmetic Subsequence
int longestArithSeqLength(int* nums, int numsSize);
// 1035. Uncrossed Lines
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size);
// 1046. Last Stone Weight
int lastStoneWeight(int* stones, int stonesSize);
// 1047. Remove All Adjacent Duplicates In String
char* removeDuplicates(char* s);
// 1048. Longest String Chain
int longestStrChain(vector<string>& words);
// 1049. Last Stone Weight II
int lastStoneWeightII(int* stones, int stonesSize);
// 1071. Greatest Common Divisor of Strings
char* gcdOfStrings(char* str1, char* str2);
string gcdOfStrings(string str1, string str2);
// 1091. Shortest Path in Binary Matrix
int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize);
// 1095. Find in Mountain Array
class MountainArray {
public:
    int get(int index) { return 1; }
    int length() { return 1; }
};
int findInMountainArray(int target, MountainArray& mountainArr);
// 1143. Longest Common Subsequence
int longestCommonSubsequence(char* text1, char* text2);
// 1160. Find Words That Can Be Formed by Characters
int countCharacters(char** words, int wordsSize, char* chars);
// 1161. Maximum Level Sum of a Binary Tree
int maxLevelSum(struct TreeNode* root);
// 1207. Unique Number of Occurrences
bool uniqueOccurrences(int* arr, int arrSize);
// 1220. Count Vowels Permutation
int countVowelPermutation(int n);
// 1239. Maximum Length of a Concatenated String with Unique Characters
int maxLength(char** arr, int arrSize);
// 1249. Minimum Remove to Make Valid Parentheses
char* minRemoveToMakeValid(char* s);
// 1266. Minimum Time Visiting All Points
int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize);
// 1287. Element Appearing More Than 25% In Sorted Array
int findSpecialInteger(vector<int>& arr);
// 1323. Maximum 69 Number
int maximum69Number(int num);
// 1337. The K Weakest Rows in a Matrix
vector<int> kWeakestRows(vector<vector<int>>& mat, int k);
// 1356. Sort Integers by The Number of 1 Bits
int* sortByBits(int* arr, int arrSize, int* returnSize);
// 1361. Validate Binary Tree Nodes
bool validateBinaryTreeNodes(int n, int* leftChild, int leftChildSize, int* rightChild, int rightChildSize);
// 1424. Diagonal Traverse II
int* findDiagonalOrder(int** nums, int numsSize, int* numsColSize, int* returnSize);
// 1425. Constrained Subsequence Sum
int constrainedSubsetSum(int* nums, int numsSize, int k);
// 1431. Kids With the Greatest Number of Candies
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies);
// 1436. Destination City
string destCity(vector<vector<string>>& paths);
// 1441. Build an Array With Stack Operations
char** buildArray(int* target, int targetSize, int n, int* returnSize);
// 1448. Count Good Nodes in Binary Tree
int goodNodes(struct TreeNode* root);
// 1456. Maximum Number of Vowels in a Substring of Given Length
int maxVowels(char* s, int k);
// 1464. Maximum Product of Two Elements in an Array
int maxProduct(vector<int>& nums);
// 1470. Shuffle the Array
int* shuffle(int* nums, int numsSize, int n, int* returnSize);
// 1480. Running Sum of 1d Array
int* runningSum(int* nums, int numsSize, int* returnSize);
// 1491.Average Salary Excluding the Minimumand Maximum Salary
double average(int* salary, int salarySize);
// 1493. Longest Subarray of 1's After Deleting One Element
int longestSubarray(int* nums, int numsSize);
// 1503. Last Moment Before All Ants Fall Out of a Plank
int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize);
// 1512. Number of Good Pairs
int numIdenticalPairs(int* nums, int numsSize);
// 1535. Find the Winner of an Array Game
int getWinner(vector<int>& arr, int k);
// 1544. Make The String Great
char* makeGood(char* s);
// 1557. Minimum Number of Vertices to Reach All Nodes
int* findSmallestSetOfVertices(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize);
// 1561. Maximum Number of Coins You Can Get
int maxCoins(int* piles, int pilesSize);
// 1572. Matrix Diagonal Sum
int diagonalSum(int** mat, int matSize, int* matColSize);
// 1582. Special Positions in a Binary Matrix
int numSpecial(vector<vector<int>>& mat);
// 1611. Minimum One Bit Operations to Make Integers Zero
int minimumOneBitOperations(int n);
// 1630. Arithmetic Subarrays
bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize);
// 1647. Minimum Deletions to Make Character Frequencies Unique
int minDeletions(string s);
// 1657. Determine if Two Strings Are Close
bool closeStrings(char* word1, char* word2);
// 1662. Check If Two String Arrays are Equivalent
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size);
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2);
// 1685. Sum of Absolute Differences in a Sorted Array
int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize);
// 1688. Count of Matches in Tournament
int numberOfMatches(int n);
// 1704. Determine if String Halves Are Alike
bool halvesAreAlike(char* s);
// 1706. Where Will the Ball Fall
int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize);
// 1716. Calculate Money in Leetcode Bank
int totalMoney(int n);
// 1721. Swapping Nodes in a Linked List
struct ListNode* swapNodes(struct ListNode* head, int k);
// 1732. Find the Highest Altitude
int largestAltitude(int* gain, int gainSize);
// 1743. Restore the Array From Adjacent Pairs
vector<int> restoreArray(vector<vector<int>>& adjacentPairs);
// 1759. Count Number of Homogenous Substrings
int countHomogenous(char* s);
// 1768. Merge Strings Alternately
char* mergeAlternately(char* word1, char* word2);
// 1793. Maximum Score of a Good Subarray
int maximumScore(int* nums, int numsSize, int k);
// 1799. Maximize Score After N Operations
int maxScore(int* nums, int numsSize);
// 1814. Count Nice Pairs in an Array
int countNicePairs(vector<int>& nums);
// 1822. Sign of the Product of an Array
int arraySign(int* nums, int numsSize);
// 1823. Find the Winner of the Circular Game
int findTheWinner(int n, int k);
// 1832. Check if the Sentence Is Pangram
bool checkIfPangram(char* sentence);
// 1838. Frequency of the Most Frequent Element
int maxFrequency(int* nums, int numsSize, int k);
// 1845. Seat Reservation Manager
// 1846. Maximum Element After Decreasing and Rearranging
int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize);
// 1877. Minimize Maximum Pair Sum in Array
int minPairSum(int* nums, int numsSize);
// 1887. Reduction Operations to Make the Array Elements Equal
int reductionOperations(int* nums, int numsSize);
// 1903. Largest Odd Number in String
string largestOddNumber(string num);
// 1913. Maximum Product Difference Between Two Pairs
int maxProductDifference(vector<int>& nums);
// 1921. Eliminate Maximum Number of Monsters
int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize);
// 1930. Unique Length - 3 Palindromic Subsequences
int countPalindromicSubsequence(char* s);
// 1980. Find Unique Binary String
char* findDifferentBinaryString(char** nums, int numsSize);
// 2001. Number of Pairs of Interchangeable Rectangles
long long interchangeableRectangles(vector<vector<int>>& rectangles);
// 2009. Minimum Number of Operations to Make Array Continuous
int minOperations(int* nums, int numsSize);
int minOperations(std::vector<int>& nums);
// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
bool winnerOfGame(char* colors);
// 2095. Delete the Middle Node of a Linked List
struct ListNode* deleteMiddle(struct ListNode* head);
// 2130. Maximum Twin Sum of a Linked List
int pairSum(struct ListNode* head);
int pairSum2(ListNode* head);
// 2131. Longest Palindrome by Concatenating Two Letter Words
int longestPalindrome(char** words, int wordsSize);
// 2147. Number of Ways to Divide a Long Corridor
int numberOfWays(char* corridor);
// 2215. Find the Difference of Two Arrays
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes);
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
// 2251. Number of Flowers in Full Bloom
int* fullBloomFlowers(int** flowers, int flowersSize, int* flowersColSize, int* people, int peopleSize, int* returnSize);
// 2264. Largest 3-Same-Digit Number in String
char* largestGoodInteger(char* num);
// 2265. Count Nodes Equal to Average of Subtree
int averageOfSubtree(struct TreeNode* root);
// 2352. Equal Row and Column Pairs
int equalPairs(int** grid, int gridSize, int* gridColSize);
// 2390. Removing Stars From a String
char* removeStars(char* s);
// 2391. Minimum Amount of Time to Collect Garbage
int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize);
// 2433. Find The Original Array of Prefix Xor
int* findArray(int* pref, int prefSize, int* returnSize);
// 2466. Count Ways To Build Good Strings
int countGoodStrings(int low, int high, int zero, int one);
// 2482. Difference Between Ones and Zeros in Row and Column
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid);
// 2483. Minimum Penalty for a Shop
int bestClosingTime(string customers);
// 2542. Maximum Subsequence Score
long long maxScore(int* nums1, int nums1Size, int* nums2, int nums2Size, int k);
// 2742. Painting the Walls
int paintWalls(int* cost, int costSize, int* time, int timeSize);
// 2785. Sort Vowels in a String
string sortVowels(string s);
// 2849. Determine if a Cell Is Reachable at a Given Time
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t);
// 剑指 Offer 05. 替换空格
char* replacespace(char* s);
// 剑指 Offer 58 - II.左旋转字符串
string reverseLeftWords(string s, int n);
char* reverseLeftWords(char* s, int n);
// 9998 转换12进制，10(X),11(Y) 107 = 8Y
char* TranserHexAdecimal(int n);
// 9999 字符串长度 3 < n < 10000000 寻找的单词长度为3
int FindSubFrequence(char* src, char* dest);
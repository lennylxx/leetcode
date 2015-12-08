Pure C solution for LeetCode
============================

This project aims at solving [LeetCode algorithm problems] with pure C Language 
using as little library functions as I can, which means except memory management
functions and few string functions I will implement everything I need such
as trees, stacks, queues and hash tables.

Parts of the problems don't provide C interface for solution, so I accomplished
them with C++ Language.

Compile **C** files using command:

    gcc -std=c99 -Wall src/foo.c -o foo

Compile **C++** files using command:

    g++ -std=c++11 -Wall src/bar.cpp -o bar

**OR**

You can build all the files using `make` (Use MinGW GCC and GNU Make on Windows).

The `☢` means that you need to have a LeetCode Premium Subscription.

|     | Problem                                                      | Solution           |
| --- | ------------------------------------------------------------ | ------------------ |
| 315 | [Count of Smaller Numbers After Self]                        |                    |
| 314 | [Binary Tree Vertical Order Traversal] ☢                     |                    |
| 313 | [Super Ugly Number]                                          | [C](src/313.c)     |
| 312 | [Burst Balloons]                                             |                    |
| 311 | [Sparse Matrix Multiplication] ☢                             |                    |
| 310 | [Minimum Height Trees]                                       |                    |
| 309 | [Best Time to Buy and Sell Stock with Cooldown]              |                    |
| 308 | [Range Sum Query 2D - Mutable] ☢                             |                    |
| 307 | [Range Sum Query - Mutable]                                  |                    |
| 306 | [Additive Number]                                            |                    |
| 305 | [Number of Islands II] ☢                                     |                    |
| 304 | [Range Sum Query 2D - Immutable]                             |                    |
| 303 | [Range Sum Query - Immutable]                                |                    |
| 302 | [Smallest Rectangle Enclosing Black Pixels] ☢                |                    |
| 301 | [Remove Invalid Parentheses]                                 |                    |
| 300 | [Longest Increasing Subsequence]                             | [C](src/300.c)     |
| 299 | [Bulls and Cows]                                             | [C](src/299.c)     |
| 298 | [Binary Tree Longest Consecutive Sequence] ☢                 |                    |
| 297 | [Serialize and Deserialize Binary Tree]                      | [C++](src/297.cpp) |
| 296 | [Best Meeting Point] ☢                                       |                    |
| 295 | [Find Median from Data Stream]                               | [C](src/295.c)     |
| 294 | [Flip Game II] ☢                                             |                    |
| 293 | [Flip Game] ☢                                                |                    |
| 292 | [Nim Game]                                                   | [C](src/292.c)     |
| 291 | [Word Pattern II] ☢                                          |                    |
| 290 | [Word Pattern]                                               | [C++](src/290.cpp) |
| 289 | [Game of Life]                                               | [C](src/289.c)     |
| 288 | [Unique Word Abbreviation] ☢                                 |                    |
| 287 | [Find the Duplicate Number]                                  |                    |
| 286 | [Walls and Gates] ☢                                          |                    |
| 285 | [Inorder Successor in BST] ☢                                 |                    |
| 284 | [Peeking Iterator]                                           | [C++](src/284.cpp) |
| 283 | [Move Zeroes]                                                | [C](src/283.c)     |
| 282 | [Expression Add Operators]                                   |                    |
| 281 | [Zigzag Iterator] ☢                                          |                    |
| 280 | [Wiggle Sort] ☢                                              |                    |
| 279 | [Perfect Squares]                                            | [C](src/279.c)     |
| 278 | [First Bad Version]                                          | [C](src/278.c)     |
| 277 | [Find the Celebrity] ☢                                       |                    |
| 276 | [Paint Fence] ☢                                              |                    |
| 275 | [H-Index II]                                                 | [C](src/275.c)     |
| 274 | [H-Index]                                                    | [C](src/274.c)     |
| 273 | [Integer to English Words]                                   |                    |
| 272 | [Closest Binary Search Tree Value II] ☢                      |                    |
| 271 | [Encode and Decode Strings] ☢                                |                    |
| 270 | [Closest Binary Search Tree Value] ☢                         |                    |
| 269 | [Alien Dictionary] ☢                                         |                    |
| 268 | [Missing Number]                                             | [C](src/268.c)     |
| 267 | [Palindrome Permutation II] ☢                                |                    |
| 266 | [Palindrome Permutation] ☢                                   |                    |
| 265 | [Paint House II] ☢                                           |                    |
| 264 | [Ugly Number II]                                             | [C](src/264.c)     |
| 263 | [Ugly Number]                                                | [C](src/263.c)     |
| 261 | [Graph Valid Tree] ☢                                         |                    |
| 260 | [Single Number III]                                          | [C](src/260.c)     |
| 259 | [3Sum Smaller] ☢                                             |                    |
| 258 | [Add Digits]                                                 | [C](src/258.c)     |
| 257 | [Binary Tree Paths]                                          | [C++](src/257.cpp) |
| 256 | [Paint House] ☢                                              |                    |
| 255 | [Verify Preorder Sequence in Binary Search Tree] ☢           |                    |
| 254 | [Factor Combinations] ☢                                      |                    |
| 253 | [Meeting Rooms II] ☢                                         |                    |
| 252 | [Meeting Rooms] ☢                                            |                    |
| 251 | [Flatten 2D Vector] ☢                                        |                    |
| 250 | [Count Univalue Subtrees] ☢                                  |                    |
| 249 | [Group Shifted Strings] ☢                                    |                    |
| 248 | [Strobogrammatic Number III] ☢                               |                    |
| 247 | [Strobogrammatic Number II] ☢                                |                    |
| 246 | [Strobogrammatic Number] ☢                                   |                    |
| 245 | [Shortest Word Distance III] ☢                               |                    |
| 244 | [Shortest Word Distance II] ☢                                |                    |
| 243 | [Shortest Word Distance] ☢                                   |                    |
| 242 | [Valid Anagram]                                              | [C](src/242.c)     |
| 241 | [Different Ways to Add Parentheses]                          | [C++](src/241.cpp) |
| 240 | [Search a 2D Matrix II]                                      | [C](src/240.c)     |
| 239 | [Sliding Window Maximum]                                     |                    |
| 238 | [Product of Array Except Self]                               | [C](src/238.c)     |
| 237 | [Delete Node in a Linked List]                               | [C](src/237.c)     |
| 236 | [Lowest Common Ancestor of a Binary Tree]                    | [C++](src/236.cpp) |
| 235 | [Lowest Common Ancestor of a Binary Search Tree]             | [C](src/235.c)     |
| 234 | [Palindrome Linked List]                                     | [C](src/234.c)     |
| 233 | [Number of Digit One]                                        | [C](src/233.c)     |
| 232 | [Implement Queue using Stacks]                               | [C](src/232.c)     |
| 231 | [Power of Two]                                               | [C](src/231.c)     |
| 230 | [Kth Smallest Element in a BST]                              | [C](src/230.c)     |
| 229 | [Majority Element II]                                        |                    |
| 228 | [Summary Ranges]                                             | [C](src/228.c)     |
| 227 | [Basic Calculator II]                                        |                    |
| 226 | [Invert Binary Tree]                                         | [C](src/226.c)     |
| 225 | [Implement Stack using Queues]                               | [C](src/225.c)     |
| 224 | [Basic Calculator]                                           | [C](src/224.c)     |
| 223 | [Rectangle Area]                                             | [C](src/223.c)     |
| 222 | [Count Complete Tree Nodes]                                  | [C](src/222.c)     |
| 221 | [Maximal Square]                                             | [C++](src/221.cpp) |
| 220 | [Contains Duplicate III]                                     |                    |
| 219 | [Contains Duplicate II]                                      | [C](src/219.c)     |
| 218 | [The Skyline Problem]                                        |                    |
| 217 | [Contains Duplicate]                                         | [C](src/217.c)     |
| 216 | [Combination Sum III]                                        | [C++](src/216.cpp) |
| 215 | [Kth Largest Element in an Array]                            | [C](src/215.c)     |
| 214 | [Shortest Palindrome]                                        |                    |
| 213 | [House Robber II]                                            | [C](src/213.c)     |
| 212 | [Word Search II]                                             | [C](src/212.c)     |
| 211 | [Add and Search Word - Data structure design]                | [C](src/211.c)     |
| 210 | [Course Schedule II]                                         |                    |
| 209 | [Minimum Size Subarray Sum]                                  | [C](src/209.c)     |
| 208 | [Implement Trie (Prefix Tree)]                               | [C](src/208.c)     |
| 207 | [Course Schedule]                                            |                    |
| 206 | [Reverse Linked List]                                        | [C](src/206.c)     |
| 205 | [Isomorphic Strings]                                         | [C](src/205.c)     |
| 204 | [Count Primes]                                               | [C](src/204.c)     |
| 203 | [Remove Linked List Elements]                                | [C](src/203.c)     |
| 202 | [Happy Number]                                               | [C](src/202.c)     |
| 201 | [Bitwise AND of Numbers Range]                               | [C](src/201.c)     |
| 200 | [Number of Islands]                                          | [C](src/200.c)     |
| 199 | [Binary Tree Right Side View]                                | [C](src/199.c)     |
| 198 | [House Robber]                                               | [C](src/198.c)     |
| 191 | [Number of 1 Bits]                                           | [C](src/191.c)     |
| 190 | [Reverse Bits]                                               | [C](src/190.c)     |
| 189 | [Rotate Array]                                               | [C](src/189.c)     |
| 188 | [Best Time to Buy and Sell Stock IV]                         |                    |
| 187 | [Repeated DNA Sequences]                                     |                    |
| 186 | [Reverse Words in a String II] ☢                             |                    |
| 179 | [Largest Number]                                             | [C](src/179.c)     |
| 174 | [Dungeon Game]                                               |                    |
| 173 | [Binary Search Tree Iterator]                                | [C++](src/173.cpp) |
| 172 | [Factorial Trailing Zeroes]                                  | [C](src/172.c)     |
| 171 | [Excel Sheet Column Number]                                  | [C](src/171.c)     |
| 170 | [Two Sum III - Data structure design] ☢                      |                    |
| 169 | [Majority Element]                                           | [C](src/169.c)     |
| 168 | [Excel Sheet Column Title]                                   | [C](src/168.c)     |
| 167 | [Two Sum II - Input array is sorted] ☢                       |                    |
| 166 | [Fraction to Recurring Decimal]                              |                    |
| 165 | [Compare Version Numbers]                                    | [C](src/165.c)     |
| 164 | [Maximum Gap]                                                | [C](src/164.c)     |
| 163 | [Missing Ranges] ☢                                           |                    |
| 162 | [Find Peak Element]                                          | [C](src/162.c)     |
| 161 | [One Edit Distance] ☢                                        |                    |
| 160 | [Intersection of Two Linked Lists]                           | [C](src/160.c)     |
| 159 | [Longest Substring with At Most Two Distinct Characters] ☢   |                    |
| 158 | [Read N Characters Given Read4 II - Call multiple times] ☢   |                    |
| 157 | [Read N Characters Given Read4] ☢                            |                    |
| 156 | [Binary Tree Upside Down] ☢                                  |                    |
| 155 | [Min Stack]                                                  | [C](src/155.c)     |
| 154 | [Find Minimum in Rotated Sorted Array II]                    | [C](src/154.c)     |
| 153 | [Find Minimum in Rotated Sorted Array]                       | [C](src/153.c)     |
| 152 | [Maximum Product Subarray]                                   | [C](src/152.c)     |
| 151 | [Reverse Words in a String]                                  | [C](src/151.c)     |
| 150 | [Evaluate Reverse Polish Notation]                           | [C](src/150.c)     |
| 149 | [Max Points on a Line]                                       |                    |
| 148 | [Sort List]                                                  | [C](src/148.c)     |
| 147 | [Insertion Sort List]                                        | [C](src/147.c)     |
| 146 | [LRU Cache]                                                  | [C](src/146.c)     |
| 145 | [Binary Tree Postorder Traversal]                            | [C](src/145.c)     |
| 144 | [Binary Tree Preorder Traversal]                             | [C++](src/144.cpp) |
| 143 | [Reorder List]                                               | [C](src/143.c)     |
| 142 | [Linked List Cycle II]                                       | [C](src/142.c)     |
| 141 | [Linked List Cycle]                                          | [C](src/141.c)     |
| 140 | [Word Break II]                                              |                    |
| 139 | [Word Break]                                                 | [C++](src/139.cpp) |
| 138 | [Copy List with Random Pointer]                              | [C](src/138.c)     |
| 137 | [Single Number II]                                           |                    |
| 136 | [Single Number]                                              | [C](src/136.c)     |
| 135 | [Candy]                                                      |                    |
| 134 | [Gas Station]                                                | [C](src/134.c)     |
| 133 | [Clone Graph]                                                | [C++](src/133.cpp) |
| 132 | [Palindrome Partitioning II]                                 | [C++](src/132.cpp) |
| 131 | [Palindrome Partitioning]                                    | [C++](src/131.cpp) |
| 130 | [Surrounded Regions]                                         |                    |
| 129 | [Sum Root to Leaf Numbers]                                   | [C](src/129.c)     |
| 128 | [Longest Consecutive Sequence]                               | [C](src/128.c)     |
| 127 | [Word Ladder]                                                | [C++](src/127.cpp) |
| 126 | [Word Ladder II]                                             |                    |
| 125 | [Valid Palindrome]                                           | [C](src/125.c)     |
| 124 | [Binary Tree Maximum Path Sum]                               |                    |
| 123 | [Best Time to Buy and Sell Stock III]                        |                    |
| 122 | [Best Time to Buy and Sell Stock II]                         | [C](src/122.c)     |
| 121 | [Best Time to Buy and Sell Stock]                            | [C](src/121.c)     |
| 120 | [Triangle]                                                   | [C](src/120.c)     |
| 119 | [Pascal's Triangle II]                                       | [C](src/119.c)     |
| 118 | [Pascal's Triangle]                                          | [C](src/118.c)     |
| 117 | [Populating Next Right Pointers in Each Node II]             |                    |
| 116 | [Populating Next Right Pointers in Each Node]                | [C](src/116.c)     |
| 115 | [Distinct Subsequences]                                      | [C](src/115.c)     |
| 114 | [Flatten Binary Tree to Linked List]                         | [C](src/114.c)     |
| 113 | [Path Sum II]                                                | [C++](src/113.cpp) |
| 112 | [Path Sum]                                                   | [C](src/112.c)     |
| 111 | [Minimum Depth of Binary Tree]                               | [C](src/111.c)     |
| 110 | [Balanced Binary Tree]                                       | [C](src/110.c)     |
| 109 | [Convert Sorted List to Binary Search Tree]                  | [C++](src/109.cpp) |
| 108 | [Convert Sorted Array to Binary Search Tree]                 | [C](src/108.c)     |
| 107 | [Binary Tree Level Order Traversal II]                       | [C++](src/107.cpp) |
| 106 | [Construct Binary Tree from Inorder and Postorder Traversal] | [C](src/106.c)     |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal]  | [C](src/105.c)     |
| 104 | [Maximum Depth of Binary Tree]                               | [C](src/104.c)     |
| 103 | [Binary Tree Zigzag Level Order Traversal]                   | [C++](src/103.cpp) |
| 102 | [Binary Tree Level Order Traversal]                          | [C](src/102.c)     |
| 101 | [Symmetric Tree]                                             | [C](src/101.c)     |
| 100 | [Same Tree]                                                  | [C](src/100.c)     |
| 99  | [Recover Binary Search Tree]                                 |                    |
| 98  | [Validate Binary Search Tree]                                | [C](src/98.c)      |
| 97  | [Interleaving String]                                        |                    |
| 96  | [Unique Binary Search Trees]                                 | [C](src/96.c)      |
| 95  | [Unique Binary Search Trees II]                              | [C++](src/95.cpp)  |
| 94  | [Binary Tree Inorder Traversal]                              | [C](src/94.c)      |
| 93  | [Restore IP Addresses]                                       | [C++](src/93.cpp)  |
| 92  | [Reverse Linked List II]                                     | [C](src/92.c)      |
| 91  | [Decode Ways]                                                | [C](src/91.c)      |
| 90  | [Subsets II]                                                 | [C++](src/90.cpp)  |
| 89  | [Gray Code]                                                  | [C](src/89.c)      |
| 88  | [Merge Sorted Array]                                         | [C](src/88.c)      |
| 87  | [Scramble String]                                            |                    |
| 86  | [Partition List]                                             | [C](src/86.c)      |
| 85  | [Maximal Rectangle]                                          |                    |
| 84  | [Largest Rectangle in Histogram]                             |                    |
| 83  | [Remove Duplicates from Sorted List]                         | [C](src/83.c)      |
| 82  | [Remove Duplicates from Sorted List II]                      | [C](src/82.c)      |
| 81  | [Search in Rotated Sorted Array II]                          | [C](src/81.c)      |
| 80  | [Remove Duplicates from Sorted Array II]                     | [C](src/80.c)      |
| 79  | [Word Search]                                                | [C](src/79.c)      |
| 78  | [Subsets]                                                    | [C++](src/78.cpp)  |
| 77  | [Combinations]                                               | [C++](src/77.cpp)  |
| 76  | [Minimum Window Substring]                                   |                    |
| 75  | [Sort Colors]                                                | [C](src/75.c)      |
| 74  | [Search a 2D Matrix]                                         | [C](src/74.c)      |
| 73  | [Set Matrix Zeroes]                                          | [C](src/73.c)      |
| 72  | [Edit Distance]                                              | [C](src/72.c)      |
| 71  | [Simplify Path]                                              |                    |
| 70  | [Climbing Stairs]                                            | [C](src/70.c)      |
| 69  | [Sqrt(x)]                                                    | [C](src/69.c)      |
| 68  | [Text Justification]                                         |                    |
| 67  | [Add Binary]                                                 | [C](src/67.c)      |
| 66  | [Plus One]                                                   | [C](src/66.c)      |
| 65  | [Valid Number]                                               | [C](src/65.c)      |
| 64  | [Minimum Path Sum]                                           | [C](src/64.c)      |
| 63  | [Unique Paths II]                                            | [C](src/63.c)      |
| 62  | [Unique Paths]                                               | [C](src/62.c)      |
| 61  | [Rotate List]                                                | [C](src/61.c)      |
| 60  | [Permutation Sequence]                                       | [C++](src/60.cpp)  |
| 59  | [Spiral Matrix II]                                           | [C](src/59.c)      |
| 58  | [Length of Last Word]                                        | [C](src/58.c)      |
| 57  | [Insert Interval]                                            |                    |
| 56  | [Merge Intervals]                                            |                    |
| 55  | [Jump Game]                                                  | [C](src/55.c)      |
| 54  | [Spiral Matrix]                                              | [C](src/54.c)      |
| 53  | [Maximum Subarray]                                           | [C](src/53.c)      |
| 52  | [N-Queens II]                                                | [C](src/52.c)      |
| 51  | [N-Queens]                                                   | [C++](src/51.cpp)  |
| 50  | [Pow(x, n)]                                                  | [C](src/50.c)      |
| 49  | [Anagrams]                                                   | [C++](src/49.cpp)  |
| 48  | [Rotate Image]                                               | [C](src/48.c)      |
| 47  | [Permutations II]                                            |                    |
| 46  | [Permutations]                                               | [C](src/46.c)      |
| 45  | [Jump Game II]                                               |                    |
| 44  | [Wildcard Matching]                                          | [C](src/44.c)      |
| 43  | [Multiply Strings]                                           | [C](src/43.c)      |
| 42  | [Trapping Rain Water]                                        |                    |
| 41  | [First Missing Positive]                                     | [C](src/41.c)      |
| 40  | [Combination Sum II]                                         | [C++](src/40.cpp)  |
| 39  | [Combination Sum]                                            | [C++](src/39.cpp)  |
| 38  | [Count and Say]                                              | [C](src/38.c)      |
| 37  | [Sudoku Solver]                                              | [C++](src/37.cpp)  |
| 36  | [Valid Sudoku]                                               | [C](src/36.c)      |
| 35  | [Search Insert Position]                                     | [C](src/35.c)      |
| 34  | [Search for a Range]                                         | [C++](src/34.cpp)  |
| 33  | [Search in Rotated Sorted Array]                             | [C](src/33.c)      |
| 32  | [Longest Valid Parentheses]                                  |                    |
| 31  | [Next Permutation]                                           | [C](src/31.c)      |
| 30  | [Substring with Concatenation of All Words]                  |                    |
| 29  | [Divide Two Integers]                                        |                    |
| 28  | [Implement strStr()]                                         | [C](src/28.c)      |
| 27  | [Remove Element]                                             | [C](src/27.c)      |
| 26  | [Remove Duplicates from Sorted Array]                        | [C](src/26.c)      |
| 25  | [Reverse Nodes in k-Group]                                   | [C](src/25.c)      |
| 24  | [Swap Nodes in Pairs]                                        | [C](src/24.c)      |
| 23  | [Merge k Sorted Lists]                                       | [C](src/23.c)      |
| 22  | [Generate Parentheses]                                       | [C++](src/22.cpp)  |
| 21  | [Merge Two Sorted Lists]                                     | [C](src/21.c)      |
| 20  | [Valid Parentheses]                                          | [C](src/20.c)      |
| 19  | [Remove Nth Node From End of List]                           | [C](src/19.c)      |
| 18  | [4Sum]                                                       |                    |
| 17  | [Letter Combinations of a Phone Number]                      | [C++](src/17.cpp)  |
| 16  | [3Sum Closest]                                               |                    |
| 15  | [3Sum]                                                       | [C++](src/15.cpp)  |
| 14  | [Longest Common Prefix]                                      | [C](src/14.c)      |
| 13  | [Roman to Integer]                                           | [C](src/13.c)      |
| 12  | [Integer to Roman]                                           | [C](src/12.c)      |
| 11  | [Container With Most Water]                                  |                    |
| 10  | [Regular Expression Matching]                                |                    |
| 9   | [Palindrome Number]                                          | [C](src/9.c)       |
| 8   | [String to Integer (atoi)]                                   | [C](src/8.c)       |
| 7   | [Reverse Integer]                                            | [C](src/7.c)       |
| 6   | [ZigZag Conversion]                                          | [C](src/6.c)       |
| 5   | [Longest Palindromic Substring]                              | [C++](src/5.cpp)   |
| 4   | [Median of Two Sorted Arrays]                                |                    |
| 3   | [Longest Substring Without Repeating Characters]             |                    |
| 2   | [Add Two Numbers]                                            | [C](src/2.c)       |
| 1   | [Two Sum]                                                    | [C](src/1.c)       |


[LeetCode algorithm problems]: https://leetcode.com/problemset/algorithms/


[Count of Smaller Numbers After Self]: https://leetcode.com/problems/count-of-smaller-numbers-after-self/
[Binary Tree Vertical Order Traversal]: https://leetcode.com/problems/binary-tree-vertical-order-traversal/
[Super Ugly Number]: https://leetcode.com/problems/super-ugly-number/
[Burst Balloons]: https://leetcode.com/problems/burst-balloons/
[Sparse Matrix Multiplication]: https://leetcode.com/problems/sparse-matrix-multiplication/
[Minimum Height Trees]: https://leetcode.com/problems/minimum-height-trees/
[Best Time to Buy and Sell Stock with Cooldown]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
[Range Sum Query 2D - Mutable]: https://leetcode.com/problems/range-sum-query-2d-mutable/
[Range Sum Query - Mutable]: https://leetcode.com/problems/range-sum-query-mutable/
[Additive Number]: https://leetcode.com/problems/additive-number/
[Number of Islands II]: https://leetcode.com/problems/number-of-islands-ii/
[Range Sum Query 2D - Immutable]: https://leetcode.com/problems/range-sum-query-2d-immutable/
[Range Sum Query - Immutable]: https://leetcode.com/problems/range-sum-query-immutable/
[Smallest Rectangle Enclosing Black Pixels]: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
[Remove Invalid Parentheses]: https://leetcode.com/problems/remove-invalid-parentheses/
[Longest Increasing Subsequence]: https://leetcode.com/problems/longest-increasing-subsequence/
[Bulls and Cows]: https://leetcode.com/problems/bulls-and-cows/
[Binary Tree Longest Consecutive Sequence]: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
[Serialize and Deserialize Binary Tree]: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
[Best Meeting Point]: https://leetcode.com/problems/best-meeting-point/
[Find Median from Data Stream]: https://leetcode.com/problems/find-median-from-data-stream/
[Flip Game II]: https://leetcode.com/problems/flip-game-ii/
[Flip Game]: https://leetcode.com/problems/flip-game/
[Nim Game]: https://leetcode.com/problems/nim-game/
[Word Pattern II]: https://leetcode.com/problems/word-pattern-ii/
[Word Pattern]: https://leetcode.com/problems/word-pattern/
[Game of Life]: https://leetcode.com/problems/game-of-life/
[Unique Word Abbreviation]: https://leetcode.com/problems/unique-word-abbreviation/
[Find the Duplicate Number]: https://leetcode.com/problems/find-the-duplicate-number/
[Walls and Gates]: https://leetcode.com/problems/walls-and-gates/
[Inorder Successor in BST]: https://leetcode.com/problems/inorder-successor-in-bst/
[Peeking Iterator]: https://leetcode.com/problems/peeking-iterator/
[Move Zeroes]: https://leetcode.com/problems/move-zeroes/
[Expression Add Operators]: https://leetcode.com/problems/expression-add-operators/
[Zigzag Iterator]: https://leetcode.com/problems/zigzag-iterator/
[Wiggle Sort]: https://leetcode.com/problems/wiggle-sort/
[Perfect Squares]: https://leetcode.com/problems/perfect-squares/
[First Bad Version]: https://leetcode.com/problems/first-bad-version/
[Find the Celebrity]: https://leetcode.com/problems/find-the-celebrity/
[Paint Fence]: https://leetcode.com/problems/paint-fence/
[H-Index II]: https://leetcode.com/problems/h-index-ii/
[H-Index]: https://leetcode.com/problems/h-index/
[Integer to English Words]: https://leetcode.com/problems/integer-to-english-words/
[Closest Binary Search Tree Value II]: https://leetcode.com/problems/closest-binary-search-tree-value-ii/
[Encode and Decode Strings]: https://leetcode.com/problems/encode-and-decode-strings/
[Closest Binary Search Tree Value]: https://leetcode.com/problems/closest-binary-search-tree-value/
[Alien Dictionary]: https://leetcode.com/problems/alien-dictionary/
[Missing Number]: https://leetcode.com/problems/missing-number/
[Palindrome Permutation II]:https://leetcode.com/problems/palindrome-permutation-ii/
[Palindrome Permutation]: https://leetcode.com/problems/palindrome-permutation/
[Paint House II]: https://leetcode.com/problems/paint-house-ii/
[Ugly Number II]: https://leetcode.com/problems/ugly-number-ii/
[Ugly Number]: https://leetcode.com/problems/ugly-number/
[Graph Valid Tree]: https://leetcode.com/problems/graph-valid-tree/
[Single Number III]: https://leetcode.com/problems/single-number-iii/
[3Sum Smaller]: https://leetcode.com/problems/3sum-smaller/
[Add Digits]: https://leetcode.com/problems/add-digits/
[Binary Tree Paths]: https://leetcode.com/problems/binary-tree-paths/
[Paint House]: https://leetcode.com/problems/paint-house/
[Verify Preorder Sequence in Binary Search Tree]: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
[Factor Combinations]: https://leetcode.com/problems/factor-combinations/
[Meeting Rooms II]: https://leetcode.com/problems/meeting-rooms-ii/
[Meeting Rooms]: https://leetcode.com/problems/meeting-rooms/
[Flatten 2D Vector]: https://leetcode.com/problems/flatten-2d-vector/
[Count Univalue Subtrees]: https://leetcode.com/problems/count-univalue-subtrees/
[Group Shifted Strings]: https://leetcode.com/problems/group-shifted-strings/
[Strobogrammatic Number III]: https://leetcode.com/problems/strobogrammatic-number-iii/
[Strobogrammatic Number II]: https://leetcode.com/problems/strobogrammatic-number-ii/
[Strobogrammatic Number]: https://leetcode.com/problems/strobogrammatic-number/
[Shortest Word Distance III]: https://leetcode.com/problems/shortest-word-distance-iii/
[Shortest Word Distance II]: https://leetcode.com/problems/shortest-word-distance-ii/
[Shortest Word Distance]: https://leetcode.com/problems/shortest-word-distance/
[Valid Anagram]: https://leetcode.com/problems/valid-anagram/
[Different Ways to Add Parentheses]: https://leetcode.com/problems/different-ways-to-add-parentheses/
[Search a 2D Matrix II]: https://leetcode.com/problems/search-a-2d-matrix-ii/
[Sliding Window Maximum]: https://leetcode.com/problems/sliding-window-maximum/
[Product of Array Except Self]: https://leetcode.com/problems/product-of-array-except-self/
[Delete Node in a Linked List]: https://leetcode.com/problems/delete-node-in-a-linked-list/
[Lowest Common Ancestor of a Binary Tree]: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
[Lowest Common Ancestor of a Binary Search Tree]: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
[Palindrome Linked List]: https://leetcode.com/problems/palindrome-linked-list/
[Number of Digit One]: https://leetcode.com/problems/number-of-digit-one/
[Implement Queue using Stacks]: https://leetcode.com/problems/implement-queue-using-stacks/
[Power of Two]: https://leetcode.com/problems/power-of-two/
[Kth Smallest Element in a BST]: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
[Majority Element II]: https://leetcode.com/problems/majority-element-ii/
[Summary Ranges]: https://leetcode.com/problems/summary-ranges/
[Basic Calculator II]: https://leetcode.com/problems/basic-calculator-ii/
[Invert Binary Tree]: https://leetcode.com/problems/invert-binary-tree/
[Implement Stack using Queues]: https://leetcode.com/problems/implement-stack-using-queues/
[Basic Calculator]: https://leetcode.com/problems/basic-calculator/
[Rectangle Area]: https://leetcode.com/problems/rectangle-area/
[Count Complete Tree Nodes]: https://leetcode.com/problems/count-complete-tree-nodes/
[Maximal Square]: https://leetcode.com/problems/maximal-square/
[Contains Duplicate III]: https://leetcode.com/problems/contains-duplicate-iii/
[Contains Duplicate II]: https://leetcode.com/problems/contains-duplicate-ii/
[The Skyline Problem]: https://leetcode.com/problems/the-skyline-problem/
[Contains Duplicate]: https://leetcode.com/problems/contains-duplicate/
[Combination Sum III]: https://leetcode.com/problems/combination-sum-iii/
[Kth Largest Element in an Array]: https://leetcode.com/problems/kth-largest-element-in-an-array/
[Shortest Palindrome]: https://leetcode.com/problems/shortest-palindrome/
[House Robber II]: https://leetcode.com/problems/house-robber-ii/
[Word Search II]: https://leetcode.com/problems/word-search-ii/
[Add and Search Word - Data structure design]: https://leetcode.com/problems/add-and-search-word-data-structure-design/
[Course Schedule II]: https://leetcode.com/problems/course-schedule-ii/
[Minimum Size Subarray Sum]: https://leetcode.com/problems/minimum-size-subarray-sum/
[Implement Trie (Prefix Tree)]: https://leetcode.com/problems/implement-trie-prefix-tree/
[Course Schedule]: https://leetcode.com/problems/course-schedule/
[Reverse Linked List]: https://leetcode.com/problems/reverse-linked-list/
[Isomorphic Strings]: https://leetcode.com/problems/isomorphic-strings/
[Count Primes]: https://leetcode.com/problems/count-primes/
[Remove Linked List Elements]: https://leetcode.com/problems/remove-linked-list-elements/
[Happy Number]: https://leetcode.com/problems/happy-number/
[Bitwise AND of Numbers Range]: https://leetcode.com/problems/bitwise-and-of-numbers-range/
[Number of Islands]: https://leetcode.com/problems/number-of-islands/
[Binary Tree Right Side View]: https://leetcode.com/problems/binary-tree-right-side-view/
[House Robber]: https://leetcode.com/problems/house-robber/
[Number of 1 Bits]: https://leetcode.com/problems/number-of-1-bits/
[Reverse Bits]: https://leetcode.com/problems/reverse-bits/
[Rotate Array]: https://leetcode.com/problems/rotate-array/
[Best Time to Buy and Sell Stock IV]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
[Repeated DNA Sequences]: https://leetcode.com/problems/repeated-dna-sequences/
[Reverse Words in a String II]: https://leetcode.com/problems/reverse-words-in-a-string-ii/
[Largest Number]: https://leetcode.com/problems/largest-number/
[Dungeon Game]: https://leetcode.com/problems/dungeon-game/
[Binary Search Tree Iterator]: https://leetcode.com/problems/binary-search-tree-iterator/
[Factorial Trailing Zeroes]: https://leetcode.com/problems/factorial-trailing-zeroes/
[Excel Sheet Column Number]: https://leetcode.com/problems/excel-sheet-column-number/
[Two Sum III - Data structure design]: https://leetcode.com/problems/two-sum-iii-data-structure-design/
[Majority Element]: https://leetcode.com/problems/majority-element/
[Excel Sheet Column Title]: https://leetcode.com/problems/excel-sheet-column-title/
[Two Sum II - Input array is sorted]: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
[Fraction to Recurring Decimal]: https://leetcode.com/problems/fraction-to-recurring-decimal/
[Compare Version Numbers]: https://leetcode.com/problems/compare-version-numbers/
[Maximum Gap]: https://leetcode.com/problems/maximum-gap/
[Missing Ranges]: https://leetcode.com/problems/missing-ranges/
[Find Peak Element]: https://leetcode.com/problems/find-peak-element/
[One Edit Distance]: https://leetcode.com/problems/one-edit-distance/
[Intersection of Two Linked Lists]: https://leetcode.com/problems/intersection-of-two-linked-lists/
[Longest Substring with At Most Two Distinct Characters]: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
[Read N Characters Given Read4 II - Call multiple times]: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/
[Read N Characters Given Read4]: https://leetcode.com/problems/read-n-characters-given-read4/
[Binary Tree Upside Down]: https://leetcode.com/problems/binary-tree-upside-down/
[Min Stack]: https://leetcode.com/problems/min-stack/
[Find Minimum in Rotated Sorted Array II]: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
[Find Minimum in Rotated Sorted Array]: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
[Maximum Product Subarray]: https://leetcode.com/problems/maximum-product-subarray/
[Reverse Words in a String]: https://leetcode.com/problems/reverse-words-in-a-string/
[Evaluate Reverse Polish Notation]: https://leetcode.com/problems/evaluate-reverse-polish-notation/
[Max Points on a Line]: https://leetcode.com/problems/max-points-on-a-line/
[Sort List]: https://leetcode.com/problems/sort-list/
[Insertion Sort List]: https://leetcode.com/problems/insertion-sort-list/
[LRU Cache]: https://leetcode.com/problems/lru-cache/
[Binary Tree Postorder Traversal]: https://leetcode.com/problems/binary-tree-postorder-traversal/
[Binary Tree Preorder Traversal]: https://leetcode.com/problems/binary-tree-preorder-traversal/
[Reorder List]: https://leetcode.com/problems/reorder-list/
[Linked List Cycle II]: https://leetcode.com/problems/linked-list-cycle-ii/
[Linked List Cycle]: https://leetcode.com/problems/linked-list-cycle/
[Word Break II]: https://leetcode.com/problems/word-break-ii/
[Word Break]: https://leetcode.com/problems/word-break/
[Copy List with Random Pointer]: https://leetcode.com/problems/copy-list-with-random-pointer/
[Single Number II]: https://leetcode.com/problems/single-number-ii/
[Single Number]: https://leetcode.com/problems/single-number/
[Candy]: https://leetcode.com/problems/candy/
[Gas Station]: https://leetcode.com/problems/gas-station/
[Clone Graph]: https://leetcode.com/problems/clone-graph/
[Palindrome Partitioning II]: https://leetcode.com/problems/palindrome-partitioning-ii/
[Palindrome Partitioning]: https://leetcode.com/problems/palindrome-partitioning/
[Surrounded Regions]: https://leetcode.com/problems/surrounded-regions/
[Sum Root to Leaf Numbers]: https://leetcode.com/problems/sum-root-to-leaf-numbers/
[Longest Consecutive Sequence]: https://leetcode.com/problems/longest-consecutive-sequence/
[Word Ladder]: https://leetcode.com/problems/word-ladder/
[Word Ladder II]: https://leetcode.com/problems/word-ladder-ii/
[Valid Palindrome]: https://leetcode.com/problems/valid-palindrome/
[Binary Tree Maximum Path Sum]: https://leetcode.com/problems/binary-tree-maximum-path-sum/
[Best Time to Buy and Sell Stock III]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
[Best Time to Buy and Sell Stock II]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
[Best Time to Buy and Sell Stock]: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
[Triangle]: https://leetcode.com/problems/triangle/
[Pascal's Triangle II]: https://leetcode.com/problems/pascals-triangle-ii/
[Pascal's Triangle]: https://leetcode.com/problems/pascals-triangle/
[Populating Next Right Pointers in Each Node II]: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
[Populating Next Right Pointers in Each Node]: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
[Distinct Subsequences]: https://leetcode.com/problems/distinct-subsequences/
[Flatten Binary Tree to Linked List]: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
[Path Sum II]: https://leetcode.com/problems/path-sum-ii/
[Path Sum]: https://leetcode.com/problems/path-sum/
[Minimum Depth of Binary Tree]: https://leetcode.com/problems/minimum-depth-of-binary-tree/
[Balanced Binary Tree]: https://leetcode.com/problems/balanced-binary-tree/
[Convert Sorted List to Binary Search Tree]: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
[Convert Sorted Array to Binary Search Tree]: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
[Binary Tree Level Order Traversal II]: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
[Construct Binary Tree from Inorder and Postorder Traversal]: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
[Construct Binary Tree from Preorder and Inorder Traversal]: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
[Maximum Depth of Binary Tree]: https://leetcode.com/problems/maximum-depth-of-binary-tree/
[Binary Tree Zigzag Level Order Traversal]: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
[Binary Tree Level Order Traversal]: https://leetcode.com/problems/binary-tree-level-order-traversal/
[Symmetric Tree]: https://leetcode.com/problems/symmetric-tree/
[Same Tree]: https://leetcode.com/problems/same-tree/
[Recover Binary Search Tree]: https://leetcode.com/problems/recover-binary-search-tree/
[Validate Binary Search Tree]: https://leetcode.com/problems/validate-binary-search-tree/
[Interleaving String]: https://leetcode.com/problems/interleaving-string/
[Unique Binary Search Trees]: https://leetcode.com/problems/unique-binary-search-trees/
[Unique Binary Search Trees II]: https://leetcode.com/problems/unique-binary-search-trees-ii/
[Binary Tree Inorder Traversal]: https://leetcode.com/problems/binary-tree-inorder-traversal/
[Restore IP Addresses]: https://leetcode.com/problems/restore-ip-addresses/
[Reverse Linked List II]: https://leetcode.com/problems/restore-ip-addresses/
[Decode Ways]: https://leetcode.com/problems/decode-ways/
[Subsets II]: https://leetcode.com/problems/subsets-ii/
[Gray Code]: https://leetcode.com/problems/gray-code/
[Merge Sorted Array]: https://leetcode.com/problems/merge-sorted-array/
[Scramble String]: https://leetcode.com/problems/scramble-string/
[Partition List]: https://leetcode.com/problems/partition-list/
[Maximal Rectangle]: https://leetcode.com/problems/maximal-rectangle/
[Largest Rectangle in Histogram]: https://leetcode.com/problems/maximal-rectangle/
[Remove Duplicates from Sorted List]: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
[Remove Duplicates from Sorted List II]: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
[Search in Rotated Sorted Array II]: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
[Remove Duplicates from Sorted Array II]: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
[Word Search]: https://leetcode.com/problems/word-search/
[Subsets]: https://leetcode.com/problems/subsets/
[Combinations]: https://leetcode.com/problems/combinations/
[Minimum Window Substring]: https://leetcode.com/problems/minimum-window-substring/
[Sort Colors]: https://leetcode.com/problems/sort-colors/
[Search a 2D Matrix]: https://leetcode.com/problems/search-a-2d-matrix/
[Set Matrix Zeroes]: https://leetcode.com/problems/set-matrix-zeroes/
[Edit Distance]: https://leetcode.com/problems/edit-distance/
[Simplify Path]: https://leetcode.com/problems/simplify-path/
[Climbing Stairs]: https://leetcode.com/problems/climbing-stairs/
[Sqrt(x)]: https://leetcode.com/problems/sqrtx/
[Text Justification]: https://leetcode.com/problems/text-justification/
[Add Binary]: https://leetcode.com/problems/add-binary/
[Plus One]: https://leetcode.com/problems/plus-one/
[Valid Number]: https://leetcode.com/problems/valid-number/
[Minimum Path Sum]: https://leetcode.com/problems/minimum-path-sum/
[Unique Paths II]: https://leetcode.com/problems/unique-paths-ii/
[Unique Paths]: https://leetcode.com/problems/unique-paths/
[Rotate List]: https://leetcode.com/problems/rotate-list/
[Permutation Sequence]: https://leetcode.com/problems/permutation-sequence/
[Spiral Matrix II]: https://leetcode.com/problems/spiral-matrix-ii/
[Length of Last Word]: https://leetcode.com/problems/length-of-last-word/
[Insert Interval]: https://leetcode.com/problems/insert-interval/
[Merge Intervals]: https://leetcode.com/problems/merge-intervals/
[Jump Game]: https://leetcode.com/problems/jump-game/
[Spiral Matrix]: https://leetcode.com/problems/spiral-matrix/
[Maximum Subarray]: https://leetcode.com/problems/maximum-subarray/
[N-Queens II]: https://leetcode.com/problems/n-queens-ii/
[N-Queens]: https://leetcode.com/problems/n-queens/
[Pow(x, n)]: https://leetcode.com/problems/powx-n/
[Anagrams]: https://leetcode.com/problems/anagrams/
[Rotate Image]: https://leetcode.com/problems/rotate-image/
[Permutations II]: https://leetcode.com/problems/permutations-ii/
[Permutations]: https://leetcode.com/problems/permutations/
[Jump Game II]: https://leetcode.com/problems/jump-game-ii/
[Wildcard Matching]: https://leetcode.com/problems/wildcard-matching/
[Multiply Strings]: https://leetcode.com/problems/multiply-strings/
[Trapping Rain Water]: https://leetcode.com/problems/trapping-rain-water/
[First Missing Positive]: https://leetcode.com/problems/first-missing-positive/
[Combination Sum II]: https://leetcode.com/problems/combination-sum-ii/
[Combination Sum]: https://leetcode.com/problems/combination-sum/
[Count and Say]: https://leetcode.com/problems/count-and-say/
[Sudoku Solver]: https://leetcode.com/problems/sudoku-solver/
[Valid Sudoku]: https://leetcode.com/problems/valid-sudoku/
[Search Insert Position]: https://leetcode.com/problems/search-insert-position/
[Search for a Range]: https://leetcode.com/problems/search-for-a-range/
[Search in Rotated Sorted Array]: https://leetcode.com/problems/search-in-rotated-sorted-array/
[Longest Valid Parentheses]: https://leetcode.com/problems/longest-valid-parentheses/
[Next Permutation]: https://leetcode.com/problems/next-permutation/
[Substring with Concatenation of All Words]: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
[Divide Two Integers]: https://leetcode.com/problems/divide-two-integers/
[Implement strStr()]: https://leetcode.com/problems/implement-strstr/
[Remove Element]: https://leetcode.com/problems/remove-element/
[Remove Duplicates from Sorted Array]: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
[Reverse Nodes in k-Group]: https://leetcode.com/problems/reverse-nodes-in-k-group/
[Swap Nodes in Pairs]: https://leetcode.com/problems/swap-nodes-in-pairs/
[Merge k Sorted Lists]: https://leetcode.com/problems/merge-k-sorted-lists/
[Generate Parentheses]: https://leetcode.com/problems/generate-parentheses/
[Merge Two Sorted Lists]: https://leetcode.com/problems/merge-two-sorted-lists/
[Valid Parentheses]: https://leetcode.com/problems/valid-parentheses/
[Remove Nth Node From End of List]: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
[4Sum]: https://leetcode.com/problems/4sum/
[Letter Combinations of a Phone Number]: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
[3Sum Closest]: https://leetcode.com/problems/3sum-closest/
[3Sum]: https://leetcode.com/problems/3sum/
[Longest Common Prefix]: https://leetcode.com/problems/longest-common-prefix/
[Roman to Integer]: https://leetcode.com/problems/roman-to-integer/
[Integer to Roman]: https://leetcode.com/problems/integer-to-roman/
[Container With Most Water]: https://leetcode.com/problems/container-with-most-water/
[Regular Expression Matching]: https://leetcode.com/problems/regular-expression-matching/
[Palindrome Number]: https://leetcode.com/problems/palindrome-number/
[String to Integer (atoi)]: https://leetcode.com/problems/string-to-integer-atoi/
[Reverse Integer]: https://leetcode.com/problems/reverse-integer/
[ZigZag Conversion]: https://leetcode.com/problems/zigzag-conversion/
[Longest Palindromic Substring]: https://leetcode.com/problems/longest-palindromic-substring/
[Median of Two Sorted Arrays]: https://leetcode.com/problems/median-of-two-sorted-arrays/
[Longest Substring Without Repeating Characters]: https://leetcode.com/problems/longest-substring-without-repeating-characters/
[Add Two Numbers]: https://leetcode.com/problems/add-two-numbers/
[Two Sum]: https://leetcode.com/problems/two-sum/

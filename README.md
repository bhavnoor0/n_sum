## n_sum
This project implements a generalised n-sum algorithm, extending problems like LeetCode's [TwoSum](https://leetcode.com/problems/two-sum/description/), [3Sum](https://leetcode.com/problems/3sum/description/) and [4Sum](https://leetcode.com/problems/4sum/description/) to arbitrary n.

The solution was first written up in python and it was assumed that rewriting the algorithm in C++ would make it faster. This was then naively attempted which resulted in the naive C++ solution which turned out to be much slower than expected (worse than python!). The naive solution copied the exact logic of the python algorithm resulting in the creation of vectors at each recursive layer. This was then optimised through the use of a single in place vector which is pulled and pushed to from each recursive layer, thus improving the performance of the algorithm by orders of magnitude.

The following test was run as a bench mark:  
```
n = 7
target = 0
nums = -30 -29 -28 -27 -26 -25 -24 -23 -22 -21 -20 -19 -18 -17 -16 -15 -14 -13 -12 -11 -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
``` 

Python algorithm:  
<img width="690" height="484" alt="Screenshot From 2026-08-16 20-12-02" src="https://github.com/user-attachments/assets/1c236b0f-8b72-4460-9bd8-9a6c3d5f0465" />  

Naive C++ solution:  
<img width="690" height="484" alt="Screenshot From 2026-08-16 20-11-50" src="https://github.com/user-attachments/assets/075319ee-ec70-4f82-8420-a4f12144443b" />  

C++ solution:  
<img width="690" height="484" alt="Screenshot From 2026-09-02 08-27-56" src="https://github.com/user-attachments/assets/5ed41857-4759-41ff-8162-775f32da9f9f" />

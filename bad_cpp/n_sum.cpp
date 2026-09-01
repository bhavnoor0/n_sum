#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> n_sum(int n, std::vector<int> &nums, int target,
                                    int left = 0, int right = -1) {
  if (right == -1) {
    right = nums.size() - 1;
  }
  std::vector<std::vector<int>> res;

  // Base case
  if (n == 2) {
    while (left < right) {
      int sum = nums[left] + nums[right];
      if (sum > target) {
        right -= 1;
      } else if (sum < target) {
        left += 1;
      } else {
        res.push_back(std::vector<int>{nums[left], nums[right]});
        left += 1;
        right -= 1;
        while (left < right and nums[left] == nums[left - 1]) {
          left += 1;
        }
        while (left < right and nums[right] == nums[right + 1]) {
          right -= 1;
        }
      }
    }
    return res;
  } else {
    // Recursive case
    for (int i = left; i <= right; i++) {
      if (i > left and nums[i] == nums[i - 1]) {
        continue;
      }
      std::vector<std::vector<int>> sub_results =
          n_sum(n - 1, nums, target - nums[i], i + 1, right);

      for (auto num : sub_results) {
        std::vector<int> temp = {nums[i]};
        temp.insert(temp.end(), num.begin(), num.end());
        res.push_back(temp);
      }
    }
    return res;
  }
}

int main() {
  int n, target;
  std::cout << "Enter n: ";
  std::cin >> n;

  std::cout << "Enter target: ";
  std::cin >> target;

  std::cout << "Enter numbers (seperated by spaces) end input with any letter:\n";
  std::vector<int> nums;
  int num;

  while (std::cin >> num) {
    nums.push_back(num);
  }

  // Start the timer
  auto start = std::chrono::high_resolution_clock::now();

  // Run the algo
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> result = n_sum(n, nums, target);

  // Stop the timer
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration = end - start;

  std::cout << "The " << result.size() << " unique combinations are:\n";
  for (const auto &combo : result) {
    std::cout << "> ";
    for (int num : combo) {
      std::cout << num << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\n Time taken: " << duration.count() << " seconds\n";

  return 0;
}

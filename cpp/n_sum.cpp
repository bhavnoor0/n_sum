#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

void n_sum(int n, std::vector<int> &nums, int target,
           std::vector<std::vector<int>> &res, std::vector<int> &current_path,
           int left = 0, int right = -1) {
  if (right == -1) {
    right = nums.size() - 1;
  }

  // Base case
  if (n == 2) {
    while (left < right) {
      long long sum = (long long)nums[left] + nums[right];
      if (sum > target) {
        right -= 1;
      } else if (sum < target) {
        left += 1;
      } else {

        // Match found
        current_path.push_back(nums[left]);
        current_path.push_back(nums[right]);

        res.push_back(current_path);

        current_path.pop_back();
        current_path.pop_back();

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
  } else {
    // Recursive case
    for (int i = left; i <= right; i++) {
      if (i > left and nums[i] == nums[i - 1]) {
        continue;
      }

      // Pruning
      if (right - i + 1 < n)
        break;
      long long min_sum = 0, max_sum = 0;
      for (int k = 0; k < n; ++k) {
        min_sum += nums[i + k];
        max_sum += nums[right - k];
      }
      if (target < min_sum)
        break;
      if (target > max_sum)
        continue;

      current_path.push_back(nums[i]);

      n_sum(n - 1, nums, target - nums[i], res, current_path, i + 1, right);

      current_path.pop_back();
    }
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

  std::vector<std::vector<int>> result;
  std::vector<int> current_path;

  n_sum(n, nums, target, result, current_path);

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

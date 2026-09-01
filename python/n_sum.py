import argparse
import time

def n_sum(n: int, nums: list[int], target: int, left=0, right = None):
    if right is None:
        right = len(nums) - 1
    res = []

    # Base case
    if n == 2:
        while left < right:
            sum = nums[left] + nums[right]
            if sum > target:
                right -= 1
            elif sum < target:
                left += 1
            else:
                res.append([nums[left], nums[right]])
                left += 1
                right -= 1
                # skip duplicate answers
                while left < right and nums[left] == nums[left -1]:
                    left += 1
                while left < right and nums[right] == nums[right + 1]:
                    right -= 1
        return res
    # Recursive case
    else:
        for i in range(left, right + 1):
            if i > left and nums[i] == nums[i - 1]:
                continue
            sub_results = n_sum(n-1, nums, target - nums[i], i + 1, right)
            for num in sub_results:
                res.append([nums[i]] + num)
        return res

if __name__ == "__main__":
    # Parse args
    parser = argparse.ArgumentParser(description="Find all unique nSum combinations.")
    parser.add_argument("-n", "--n", type=int, required=True, help="How many numbers to sum (e.g., 4)")
    parser.add_argument("-t", "--target", type=int, required=True, help="The target sum")
    parser.add_argument("--nums", type=int, nargs="+", required=True, help="The list of numbers separated by spaces")
    args = parser.parse_args()

    # Start timer
    start_time = time.perf_counter()

    # Run the algo
    args.nums.sort()
    result = n_sum(args.n, args.nums, args.target)

    # Stop the stopwatch
    end_time = time.perf_counter()

    # Print the results
    print(f"The {len(result)} unique combinations of {args.n} numbers that add to {args.target} are:")
    for res in result:
        print(f"> {res}")

    print(f"\n Time taken: {end_time - start_time:.4f} seconds")

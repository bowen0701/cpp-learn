#include <iostream>
#include <vector>
#include "util.h"

// Quick sort algorithm by recursion with new vectors.
// Procedure:
// - Pick a pivot which ideally is a median pf the list.
// - Arrange half elements which are smaller than pivot to left,
//   and the other half ones that are bigger than pivot to right.
// - Then to each half, recursively apply quicksort.
// Time complexity: O(n*logn).
// Space complexity: O(n).
std::vector<int> quickSortByNewVector(std::vector<int>& nums) {
  auto n = nums.size();

  // Base case.
  if (n <= 1) return nums;

  // Use middle num as pivot to collect small, middle & large numbers.
  auto pivot = nums[n / 2];
  std::vector<int> smalls;
  std::vector<int> middles;
  std::vector<int> larges;
  for (auto x : nums) {
    if (x < pivot) {
      smalls.push_back(x);
    } else if (x == pivot) {
      middles.push_back(x);
    } else {
      larges.push_back(x);
    }
  }

  // Concate small, middle & large numbers.
  std::vector<int> sorted_smalls = quickSortByNewVector(smalls);
  std::vector<int> sorted_larges = quickSortByNewVector(larges);
  sorted_smalls.insert(
    sorted_smalls.end(), middles.begin(), middles.end());
  sorted_smalls.insert(
    sorted_smalls.end(), sorted_larges.begin(), sorted_larges.end());
  return sorted_smalls;
}

// Util function for quickSortInPlace() to rearrange nums in place.
int partition(std::vector<int>& nums, int left, int right) {
  // Use right number as pivot.
  auto right_num = nums[right];

  // Rearrange numbers w.r.t. pivot: 
  // - For left <= k <= i: nums[k] <= pivot,
  // - For i+1 <= k <= j-1: nums[k] > pivot,
  // - For k = right: nums[k] = pivot.
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (nums[j] <= right_num) {
      i++;

      // Swap nums[i] and nums[j].
      auto temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
  }

  // Swap nums[i+1] and right number.
  auto temp = nums[i + 1];
  nums[i + 1] = nums[right];
  nums[right] = temp;

  // Return parition position.
  return i + 1;
}

// Util function for QuickSortInPlace() by recursion.
void quickSortRecur(std::vector<int>& nums, int left, int right) {
  if (left < right) {
    auto mid = partition(nums, left, right);
    quickSortRecur(nums, left, mid - 1);
    quickSortRecur(nums, mid + 1, right);    
  }
}

// Quick sort algorithm by recursion in place.
// Time complexity: O(n*logn).
// Space complexity: O(1).
void quickSortInPlace(std::vector<int>& nums) {
  auto n = nums.size();

  // Base case.
  if (n <= 1) return;

  int left = 0;
  int right = n - 1;
  quickSortRecur(nums, left, right);
}

int main() {
  std::vector<int> nums = {5, 2, 3, 1, 4};
  std::vector<int> result = quickSortByNewVector(nums);
  std::cout << "By QuickSortByNewVector:" << std::endl;
  printVector(result);

  nums = {5, 2, 3, 1, 4};
  quickSortInPlace(nums);
  std::cout << "By QuickSortInPlace:" << std::endl;
  printVector(nums);

  return 0;
}

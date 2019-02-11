#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(const vector<int>& nums, int& L, int& R) {
	int size = nums.size(), tmpL, tmpSum = 0, maxSum = 0, allNegative = 1, zeroIndex = -1;

	for (int i = 0; i < size; ++i) {
		if (0 <= nums[i]) {
			allNegative = 0;
			if (nums[i] == 0 && zeroIndex == -1) {
				zeroIndex = i;
			}
		}

		if (tmpSum == 0) {
			tmpL = i;
		}
		tmpSum += nums[i];
		if (maxSum < tmpSum) {
			maxSum = tmpSum;
			L = tmpL;
			R = i;
		}
		else if (tmpSum < 0) {
			tmpSum = 0;
		}
	}

	if (allNegative == 1) {
		maxSum = 0; 
		L = 0; R = size - 1;
	}
	else if (maxSum == 0 && zeroIndex != -1) {
		L = R = zeroIndex;
	}
	
	return maxSum;
}

int main() {
	int K;
	cin >> K;
	vector<int> nums(K);
	for (int i = 0; i < K; ++i) {
		cin >> nums[i];
	}

	int maxSum, L, R;
	maxSum = findMaxSum(nums, L, R);
	printf("%d %d %d\n", maxSum, nums[L], nums[R]);

	return 0;
}
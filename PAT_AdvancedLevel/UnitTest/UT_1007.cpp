#include "stdafx.h"
#include "CppUnitTest.h"
#include "../1007 Maximum Subsequence Sum/Solution.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UT_1007)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			vector<int> nums{ -10, 1, 2, 3, 4, -5, -23, 3, 7, -21 };

			int L, R;
			int maxSum = findMaxSum(nums, L, R);
			Assert::IsTrue(maxSum == 10);
			Assert::IsTrue(nums[L] == 1);
			Assert::IsTrue(nums[R] == 4);
		}

		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			vector<int> nums{ -1,-2,-3,-4,-5 };

			int L, R;
			int maxSum = findMaxSum(nums, L, R);
			Assert::IsTrue(maxSum == 0);
			Assert::IsTrue(nums[L] == -1);
			Assert::IsTrue(nums[R] == -5);
		}

		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			vector<int> nums{ -1,-2,0,-3,-4,-5 };

			int L, R;
			int maxSum = findMaxSum(nums, L, R);
			Assert::IsTrue(maxSum == 0);
			Assert::IsTrue(nums[L] == 0);
			Assert::IsTrue(nums[R] == 0);
		}

		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			vector<int> nums{ 1,2,3,-10,3,2,1 };

			int L, R;
			int maxSum = findMaxSum(nums, L, R);
			Assert::IsTrue(maxSum == 6);
			Assert::IsTrue(nums[L] == 1);
			Assert::IsTrue(nums[R] == 3);
		}

		TEST_METHOD(TestMethod5)
		{
			// TODO: 在此输入测试代码
			vector<int> nums{ -1,-2,-3,1,0,2,0,3,0,-2,4,0,-3,-4,-5 };

			int L, R;
			int maxSum = findMaxSum(nums, L, R);
			Assert::IsTrue(maxSum == 8);
			Assert::IsTrue(nums[L] == 1);
			Assert::IsTrue(nums[R] == 4);
		}
	};
}
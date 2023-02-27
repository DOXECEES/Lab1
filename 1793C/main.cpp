#include <iostream>
#include <algorithm>

bool Tests()
{
	int arr1[3] = { 1,2,3 };
	int arr2[4] = { 2,1,4,3 };
	int arr3[7] = { 1, 3, 2, 4, 6, 5, 7 };
	int arr4[6] = { 2, 3, 6, 5, 4, 1 };

	if (!(Solve(arr1, 3).first == -1 && Solve(arr1, 3).second == -1))
	{
		return false;
	}
	if (!(Solve(arr2, 4).first == 1 && Solve(arr2, 4).second == 4))
	{
		return false;
	}
	if (!(Solve(arr3, 7).first == 2 && Solve(arr3, 7).second == 6))
	{
		return false;
	}
	if (!(Solve(arr4, 6).first == -1 && Solve(arr4, 6).second == -1))
	{
		return false;
	}

	return true;

}


std::pair<int,int> Solve(int arr[], int size)
{
	int beginIndex = 0;
	int endIndex = size - 1;
	int minValue = 1;
	int maxValue = size;

	while (beginIndex <= endIndex) 
	{
		if (arr[beginIndex] == minValue) 
		{
			++beginIndex;
			++minValue;
		}
		else if (arr[beginIndex] == maxValue) 
		{
			++beginIndex;
			--maxValue;
		}
		else if (arr[endIndex] == minValue) 
		{
			--endIndex;
			++minValue;
		}
		else if (arr[endIndex] == maxValue) 
		{
			--endIndex;
			--maxValue;
		}
		else 
		{
			return std::make_pair<beginIndex + 1, endIndex + 1>;
		}
	}

	return std::make_pair(-1,-1);
	
}



int main()
{

	if (Tests())
	{
		std::cout << "Tests passed" << std::endl;
	}
	else
	{
		std::cout << "Tests failed" << std::endl;
		return -1;
	}

	int t;
	std::cin >> t;
	int n;	

	while (t--)
	{
		bool smtPrint = false;
		std::cin >> n;
		
		int* ptr = new int[n];

		for (int i = 0; i < n; ++i)
		{
			std::cin >> ptr[i];
		}

		auto solution = Solve(ptr, n);

		if (solution.first == -1 && solution.second == -1)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			std::cout << solution.first << ' ' << solution.second << std::endl;
		}


		delete[] ptr;
	}

}
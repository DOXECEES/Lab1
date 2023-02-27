#include <iostream>

bool Solve(int arr[], int size)
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
			std::cout << beginIndex + 1 << ' ' << endIndex + 1 << std::endl;
			return true;
		}
	}

	return false;
	
}



int main()
{
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

		if (!Solve(ptr, n))
		{
			std::cout << -1 << std::endl;
		}


		delete[] ptr;
	}

}
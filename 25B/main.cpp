#include <iostream>
#include <string>

int main()
{
	int n;

	std::cin >> n;
	int symbolsPaste = 0;
	bool isEven;
	char *c = new char[n];
	
	for (int i = 0; i < n; ++i)
	{
		std::cin >> c[i];
	}
	
	if (n % 2 == 0)
		isEven = true;
	else
		isEven = false;



	std::cout << c[0];

	if (isEven == true)
	{
		for (int i = 1; i < n; ++i)
		{
			if (i % 2 == 0 && i < n - 1)
			{
				std::cout << "-";
			}
			std::cout << c[i];
		}
	}
	else
	{
		for (int i = 1; i < n; ++i)
		{
			if (i % 2 == 0 && i < n - 2)
			{
				std::cout << "-";
			}
			std::cout << c[i];
		}
	}



};
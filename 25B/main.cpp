#include <iostream>
#include <string>

std::string Solve(const std::string c, int n);


bool Tests()
{


	if (strcmp(Solve("12913", 6).c_str(), "12-91-3"))
		return false;
	if (strcmp(Solve("7821910321", 11).c_str(), "78-21-91-03-21"))
		return false;
	if (strcmp(Solve("93", 3).c_str(), "93"))
		return false;

	return true;
}

std::string Solve(const std::string c, const int n)
{
	bool isEven;
	std::string str;

	if (n % 2 == 0)
		isEven = true;
	else
		isEven = false;


	str += c[0];

	if (isEven == true)
	{
		for (int i = 1; i < n; ++i)
		{
			if (i % 2 == 0 && i < n - 1)
			{
				str += "-";
			}
			str += c[i];
		}
	}
	else
	{
		for (int i = 1; i < n; ++i)
		{
			if (i % 2 == 0 && i < n - 2)
			{
				str += "-";
			}
			str += c[i];
		}
	}


	return str;
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





	int n;

	std::cin >> n;
	char* c = new char[n];

	for (int i = 0; i < n; ++i)
	{
		std::cin >> c[i];
	}

	std::cout << Solve(c, n) << std::endl;

	delete[] c;
};
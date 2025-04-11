#include <iostream>
#include <vector>

std::vector<std::vector<int>> RES;
void subsetSum(std::vector<int> C, int i, int target, std::vector<int> sc)
{
	if (i < 0)
	{
		if (target == 0)
		{
			RES.push_back(sc);
		}
		return;
	}
	

	sc.push_back(C[i]);
	subsetSum(C, i - 1, target - C[i], sc);
	sc.pop_back();
	subsetSum(C, i - 1, target, sc);
}

bool haySolucion(std::vector<int> C, int i, int target)
{
	if (target < 0)
	{
		return false;
	}
	if (i == 0)
	{
		return target == 0;
	}
	else
	{
		return haySolucion(C, i - 1, target) || haySolucion(C, i - 1, target - C[i]);
	}
}

int main() {
	std::vector<int> conjunto = { 6,12,6 };
	int suma = 12;
	std::vector<int> sc;

	bool isSolvable = haySolucion(conjunto, conjunto.size() - 1, suma);

	std::cout << "Hay solucion? " << isSolvable << std::endl;

	subsetSum (conjunto, conjunto.size() - 1, suma, sc);

	std::cout << "{ ";
	for (std::vector<int> elem : RES)
	{
		std::cout << "{ ";
		for (int e : elem)
		{
			std::cout << e << " ";
		}
		std::cout << "} ";
	}
	std::cout << "}";
	
	return 0;
}
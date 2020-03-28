#include <iostream>
#include <vector>
#include "Tetro.h"

void print(std::vector<std::vector<int>> v)
{
	for (int r = 0; r < v.size(); r++)
	{
		for (int c = 0; c < v[0].size(); c++)
		{
			std::cout << v[r][c];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	Tetro t;
	std::vector<std::vector<int>> v = t.getShape();
	print(v);
	t.changeShape();
	std::vector<std::vector<int>> v2 = t.getShape();
	print(v2);
}
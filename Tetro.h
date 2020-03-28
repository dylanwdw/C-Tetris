#pragma once
#include <vector>

class Tetro
{
	public:

		Tetro();
		bool changeShape();
		std::vector<std::vector<int>> getShape();
		bool rotate();
		bool moveLeft();
		bool moveRight();
		bool moveDown();

	private:

		void buildShape(int randKey);
		std::vector<std::vector<int>> shape;

		struct position
		{
			int x;
			int y;
		} pos;
};



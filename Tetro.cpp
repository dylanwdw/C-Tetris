#include "Tetro.h"
#include "Game.h"
#include <cstdlib>
#include <time.h>

Tetro::Tetro()
{
	srand(time(0));
	buildShape((rand()%7)+1);

	pos.x = BOARD_WIDTH / shape.size();
	pos.y = 0;

}

void Tetro::buildShape(int key)
{
	switch(key)
	{
		case 1:
		{
			this->shape =
			{
				{0, 0, 0, 0},
				{0, 0, 0, 0},
				{1, 1, 1, 1},
				{0, 0, 0, 0}
			};
			break;
		}
		case 2:
		{
			this->shape =
			{
				{2, 2},
				{2, 2}
			};
			break;
		}
		case 3:
		{
			this->shape =
			{
				{0, 3, 3},
				{3, 3, 0},
				{0, 0, 0}
			};
			break;
		}
		case 4:
		{
			this->shape =
			{
				{4, 4, 0},
				{0, 4, 4},
				{0, 0, 0}
			};
			break;
		}
		case 5:
		{
			this->shape =
			{
				{5, 0, 0},
				{5, 5, 5},
				{0, 0, 0}
			};
			break;
		}
		case 6:
		{
			this->shape =
			{
				{0, 0, 6},
				{6, 6, 6},
				{0, 0, 0}
			};
		}
		case 7:
		{
			this->shape =
			{
				{0, 7, 0},
				{7, 7, 7},
				{0, 0, 0}
			};
		}
	}
}

bool Tetro::changeShape()
{
	buildShape((rand() % 7) + 1);
	return true;
}

bool Tetro::rotate()
{
	int N = shape.size();
	for (int i = 0; i < N / 2; i++) 
	{
		for (int j = i; j < N - i - 1; j++) 
		{
			int temp = shape[i][j];
			shape[i][j] = shape[N - 1 - j][i];
			shape[N - 1 - j][i] = shape[N - 1 - i][N - 1 - j];
			shape[N - 1 - i][N - 1 - j] = shape[j][N - 1 - i];
			shape[j][N - 1 - i] = temp;
		}
	}

	return true;
}

bool Tetro::moveLeft()
{
	pos.x--;
	return true;
}

bool Tetro::moveRight()
{
	pos.x++;
	return true;
}

bool Tetro::moveDown()
{
	pos.y--;
	return true;
}

std::vector<std::vector<int>> Tetro::getShape()
{
	return shape;
}


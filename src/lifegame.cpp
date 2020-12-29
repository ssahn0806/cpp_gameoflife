#include "lifegame.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// 멤버 함수 정의
LifeGame::LifeGame()
{
	width = 0;
	height = 0;
	current_cells = NULL;
	next_cells = NULL;
}
LifeGame::~LifeGame()
{
	delete[] current_cells;
	current_cells = NULL;
	delete[] next_cells;
	next_cells = NULL;
}
void LifeGame::initialize(int w, int h)
{
	width = w;
	height = h;
	int size = width * height;
	if (current_cells != NULL || next_cells !=NULL)
	{
		delete[] current_cells;
		delete[] next_cells;
		current_cells = NULL;
		next_cells = NULL;
	}
	current_cells = new bool[width*height];
	next_cells = new bool[width * height];

	for (int i = 0; i < size; i++)
	{
		*(current_cells + i) = false;
		*(next_cells + i) = false;
	}
}
int LifeGame::getWidth() const
{
	return width;
}
int LifeGame::getHeight() const
{
	return height;
}
void LifeGame::setState(int i, int j, bool s)
{
	*(current_cells + j * width + i) = s;
}
bool LifeGame::getState(int i, int j) const
{
	return *(current_cells + j * width + i);
}
void LifeGame::setNState(int i, int j, bool s)
{
	*(next_cells + j * width + i) = s;
}
bool LifeGame::getNState(int i, int j) const
{
	return *(next_cells + j * width + i);
}
void LifeGame::clear()
{
	int w = width;
	int h = height;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			setState(i, j, false);
			setNState(i, j, false);
		}
	}
}
void LifeGame::update()
{
	int w = width;
	int h = height;


	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			setNState(i, j, getState(i, j));
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			int count = 0;
			bool check[8] = { false };

			
			if (i == 0) // 첫번째 줄
			{
				if (j == 0) // 첫번째 칸
				{
					check[0] = getState(w - 1, h - 1);
					check[1] = getState(w - 1, j);
					check[2] = getState(w - 1, j + 1);
					check[3] = getState(i, h - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(i + 1, h - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, j + 1);
				}
				else if (j == h - 1) // 끝 칸
				{
					check[0] = getState(w - 1, j - 1);
					check[1] = getState(w - 1, j);
					check[2] = getState(w - 1, i);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, i);
					check[5] = getState(i + 1, j - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, i);
				}
				else //가운데
				{
					check[0] = getState(w - 1, j - 1);
					check[1] = getState(w - 1, j);
					check[2] = getState(w - 1, j + 1);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(i + 1, j - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, j + 1);
				}
			}
			else if (i > 0 && i < w - 1) // 중간
			{
				if (j == 0) // 첫번째 칸
				{
					check[0] = getState(i - 1, h - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j + 1);
					check[3] = getState(i, h - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(i + 1, h - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, j + 1);
				}
				else if (j == h - 1) // 끝칸
				{
					check[0] = getState(i - 1, j - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j - j);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, j - j);
					check[5] = getState(i + 1, j - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, j - j);
				}
				else // 일반적인 케이스
				{
					check[0] = getState(i - 1, j - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j + 1);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(i + 1, j - 1);
					check[6] = getState(i + 1, j);
					check[7] = getState(i + 1, j + 1);
				}
			}
			else // 마지막 줄
			{
				if (j == 0) // 첫번째 칸
				{
					check[0] = getState(i - 1, h - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j + 1);
					check[3] = getState(i, h - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(j, h - 1);
					check[6] = getState(j, j);
					check[7] = getState(j, j + 1);
				}
				else if (j == h - 1) // 끝칸
				{
					check[0] = getState(i - 1, j - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j-j);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, j-j);
					check[5] = getState(j-j, j - 1);
					check[6] = getState(j-j, j);
					check[7] = getState(j - j, j - j);
				}
				else 
				{
					check[0] = getState(i - 1, j - 1);
					check[1] = getState(i - 1, j);
					check[2] = getState(i - 1, j + 1);
					check[3] = getState(i, j - 1);
					check[4] = getState(i, j + 1);
					check[5] = getState(j - j, j - 1);
					check[6] = getState(j - j, j);
					check[7] = getState(j - j, j + 1);
				}
			}

			for (int k = 0; k < 8; k++)
			{
				if (check[k] == true)
					count++;
			}

			if (getState(i, j) == true)
			{
				if (count == 2 || count == 3)
				{
					setNState(i, j, true);
				}
				else
				{
					setNState(i, j, false);
				}

			}
			else
			{
				if (count == 3)
				{
					setNState(i, j, true);
				}
				else
				{
					setNState(i, j, false);
				}
			}		
		}
		
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			setState(i, j, getNState(i, j));
		}
	}
}

// friend 함수 정의
 ostream& operator <<(ostream& os, const LifeGame& game)
{
	 int w = game.width;
	 int h = game.height;
	 for (int i = 0; i < w * h; i++)
	 {
		 if (i > 0 && i % h == 0)
		 {
			 os << endl;
		 }
		 switch (*(game.current_cells + i))
		 {
		 case true:
			 os << "O ";
			 break;
		 case false:
			 os << ". ";
			 break;

		}

	 }

	 return os;
}
#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class LifeGame
{
public:
	LifeGame();
	~LifeGame();
	void initialize(int w, int h);
	int getWidth() const;
	int getHeight() const;
	void setState(int i, int j, bool s);
	bool getState(int i, int j) const;
	void setNState(int i, int j, bool s);
	bool getNState(int i, int j) const;
	void clear();
	void update();
	friend ostream& operator <<(ostream& os, const LifeGame& game);

private:
	int width;
	int height;
	bool* current_cells;
	bool* next_cells;
};

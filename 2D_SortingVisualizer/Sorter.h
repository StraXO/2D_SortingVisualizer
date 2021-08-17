#pragma once

class Sorter
{
public:
	void update();
	void createObjects();
	bool isComplete();
private:
	void drawObjects();
	void sort();
	void checkIfComplete();
};
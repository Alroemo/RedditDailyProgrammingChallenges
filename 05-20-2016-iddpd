/*
r/dailyprogrammer
2016-05-20
Challenge #267[hard]: IDDQD
------------------------------------------------------------------------------
Description:
You are trapped in a room full of evil zombies. Some people might resign themselves to their doom in this situation, but not you. You're a badass space marine! No, not the kind with big armor; the kind with a BFG-9000!
Unfortunately though, this Big F'in Gun only has one shot remaining, so you have to make it count. The BFG will blow away anything it hits, of course, but it will also destroy anything it grazes. The zombies in the room are slow, so you have ample time to position yourself for the perfect shot. How many zombies can you take out at once?
For the sake of simplicity, the room is represented by a flat 2D grid. The BFG can be fired from any empty spot in any direction along a row, column, or diagonal of the grid. Any zombie that it meets in its path gets destroyed, and stops the BFG beam. Additionally, any zombie that is adjacent (horizontally, vertically or diagonally) to the beam is also destroyed.
------------------------------------------------------------------------------
Formal Input:
The first line of input will be two numbers denoting the size (height, width) of the two-dimensional room. The remaining lines will contain the coordinates at which there is a zombie. These coordinates are zero-indexed.
Sample input:
6 10
2 4
4 6
5 5
0 0
0 6
This corresponds to the following map:
X.....X...
..........
....X.....
..........
......X...
.....X....
------------------------------------------------------------------------------
Formal output:
The output is a single number: the maximum number of zombies you can blast with one single shot of the BFG.
Sample output:
4
Because there are many possible ways to achieve the maximum, an actual output of what the shot is is not necessary. You might want to do it for debug purposes, but in big rooms it is fairly meaningless.
Sample explanation: One way to achieve the 4-zombie blast is:
X....#X...
.....#....
....X#....
.....#....
.....#X...
.....X....
Another one is:
X#....X...
..#.......
...#X.....
....#.....
.....#X...
.....X#...
As might be evident, "your" position doesn't matter. All that matters is the line that the BFG beam draws, and the things adjacent to it.
------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void createGrid(int [][2] grid);
int findHighestRowLength(int [][2]grid);
int findHighestColLength(int [][2]grid);
void createAreaGrid(char [][30]areaGrid, int [][2]grid, int height, int width);
int findMostDamage(char[][30]areaGrid, int height, int width);
int horizontalDamage(char[][30]areaGrid, int height, int width);
int VerticalDamage(char[][30]areaGrid, int height, int width);
int diagonalDamage(char[][30]areaGrid, int height, int width);

int main()
{
	int [][2]inputGrid;
	this.createGrid(inputGrid);
	int areaHeight = this.findHighestRowLength(inputGrid);
	int areaWidth = this.findHighestColLength(inputGrid);
	char [areaHeight][areaWidth]areaGrid;
	this.createAreaGrid(areaGrid, inputGrid, areaHeight, areaWidth);
	int mostDamage = findMostDamage(areaGrid, areaHeight, areaWidth);

	cout << mostDamage<<endl;

	return 0;
}

void createGrid(int [][2] grid)
{
	fstream filein;
	filein.open("file.dat");
	
	if(!filein.fail())
	{
		int row = 0;
		while(!fin.eof())
		{
			filein>>grid[row][0];
			filein>>grid[row][1];
			row++;
		}
	}
	
}

int findHighestRowLength(int [][2]grid)
{
	int currentHighest = 0;
	for(int i = 0; i < grid.size(); i++)
	{
		if(grid[i][0] > currentHighest)
			currentHighest = grid[i][0];	
	}
	return currentHighest;
}

int findHighestColLength(int [][2]grid)
{
	int currentHighest = 0;
	for(int i = 0; i < grid.size(); i++)
	{
		if(grid[i][1] > currentHighest)
			currentHighest = grid[i][1];	
	}
	return currentHighest;
}

void createAreaGrid(char [][30]areaGrid, int [][2]grid, int height, int width)
{
	for(int i=0; i < height; i++)
	{
		for(int j=0; j<width;j++)
		{
			if(grid[i][0] == i && grid[i][1] == j)
				areaGrid[i][j] = 'X';
			else
				areaGrid[i][j] = '.';
		}
	}
}

int findMostDamage(char[][30]areaGrid, int height, int width)
{

	int mostHorizDamage = horizontalDamage(char[][]areaGrid, int height, int width);
	int mostVerDamage = verticalDamage(char[][]areaGrid, int height, int width);
	int mostDiagDamage = diagonalDamage(char[][]areaGrid, int height, int width);
	
	if(mostHorizDamage > mostVerDamage && mostHorizDamage > mostDiagDamage)
		return mostHorizDamage;
	else if(mostVerDamage > mostHorizDamage && mostVerDamage > mostDiagDamage)
		return mostVerDamage;
	else if(mostDiagDamage > mostHorizDamage && mostDiagDamage > mostVerDamage)
		return mostDiagDamage;
	else
		return 0;
	
}

int horizontalDamage(char[][30]areaGrid, int height, int width)
{
	int mostDamage = 0;
	for(int attempts=0; attempts < height; attempts++)
	{
		int damage = 0;
		for(int i = 0; i < width;i++)
		{
			if(areaGrid[attempts][i]!='x')
			{
				areaGrid[attempts][i] = '#';
				if(areaGrid[attempts][i-1] == 'x' && attempts!= 0)
					damage++;
				if(areaGrid[attempts][i+1] == 'x' && attempts!= width)
					damage++;
			}		
		}
		if(damage > mostDamage)
			mostDamage = damage;
	}
	return mostDamage;
}

int VerticalDamage(char[][30]areaGrid, int height, int width)
{
	int mostDamage = 0;
	for(int attempts=0; attempts < width;attempts++)
	{
		int damage = 0;
		for(int i = 0; i < height;i++)
		{
			if(areaGrid[i][attempts]!='x')
			{
				areaGrid[attempts][i] = '#';
				if(areaGrid[attempts][i-1] == 'x' && attempts!= 0)
					damage++;
				if(areaGrid[attempts][i+1] == 'x' && attempts!= width)
					damage++;
			}	
		}
		if(damage > mostDamage)
			mostDamage = damage;
	}
	return mostDamage;
}

int diagonalDamage(char[][30]areaGrid, int height, int width)
{
	int mostDamage = 0;
	for(int i=0; i < height;i++)
	{
		int damage = 0;
		for(int j = 0; j < width;j++)
		{
			if(j < width/2)
			{
				if(areaGrid[i][j+j] !='x')
				{
					areaGrid[i][j+j] = '#';
					if(areaGrid[i][j-1] == 'x' && attempts!= 0)
						damage++;
					if(areaGrid[i][j+1] == 'x' && attempts!= width)
						damage++;
				}
			}
			else
			{
				if(areaGrid[i][j + (width - j)] !='x')
				{
					areaGrid[i][j + (width - j)] = '#';
					if(areaGrid[i][(j + (width - j))-1] == 'x' && attempts!= 0)
						damage++;
					if(areaGrid[i][(j + (width - j))+1]  == 'x' && attempts!= width)
						damage++;
				}
			}
		}
	}
	return mostDamage;
}

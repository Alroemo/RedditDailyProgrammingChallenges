/*
r/dailyprogrammer
2016-05-09
Challenge #266 [Easy]: Basic Graph Statistics: Node Degrees
------------------------------------------------------------------------------------------------------------------------------------------------------------
Description:
In graph theory, the degree of a node is the number of edges coming into it or going out of it - how connected it is. For this challenge you'll be calculating the degree of every node. 
------------------------------------------------------------------------------------------------------------------------------------------------------------
Input:
First you'll be given an integer, N, on one line showing you how many nodes to account for. Next you'll be given an undirected graph as a series of number pairs, a and b, showing that those two nodes are connected - an edge. Example:

3 
1 2
1 3
------------------------------------------------------------------------------------------------------------------------------------------------------------
Your program should emit the degree for each node. Example:

Node 1 has a degree of 2
Node 2 has a degree of 1
Node 3 has a degree of 1
------------------------------------------------------------------------------------------------------------------------------------------------------------
 Programmed in C++
*/

#include <iostream>
using namespace std;
void readArray(int totalCount, int [][2]inputArray, int entityCount);
void printNodes(int totalCount, int [][2]inputArray, int entityCount);

int main()
{
  int totalCount;
  int entityCount;
  int [][2]inputArray;
  readArray(totalCount, inputArray, entityCount);
  printNodes(totalCount, inputArray, entityCount);
}

void readArray(int totalCount, int [][2]inputArray, int entityCount)
{
  fstream filein;
	filein.open("file.dat");
	
	if (!filein.fail())
	{
	  entityCount = 0;
	  filein>>totalCount;
	  while(!filein.eof())
	  {
	    filein>>inputArray[entityCount][0];
	    filein>>inputArray[entityCount][1];
	    entityCount++;
	  }
  }
}

void printNodes(int totalCount, int [][2]inputArray, int entityCount)
{
  int degree;
  for(int i = 1; i <= totalCount; i++)
  {
    degree = 0;
    for(int j = 0; j < entityCount; j++)
    {
      if(i == inputArray[j][0])
        degree = inputArray[j][1];
      else if(i == inputArray[j][1])
        degree = inputArray[j][0];  
    }
    cout<< "Node "<< i <<" has a degree of "<<degree<<endl;
  }
}


}

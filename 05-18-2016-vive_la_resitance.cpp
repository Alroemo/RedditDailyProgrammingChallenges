/*
r/dailyprogrammer challenge #267
05-18-2016 
Intermediate
Vive La Resistance!
------------------------------------------------------------------------------------------------------------------
It's midnight. You're tired after a night of partying (or gaming, or whatever else you like to do when procrastinating), and are about ready to go to sleep when you remember: you have a whole load of homework for your Electronics 101 course. The topic is resistance, and calculating the total resistance of various circuits.

Someone who is not you might do something sensible, like sighing and getting the work done, or even going to sleep and letting it go. But you are a programmer! Obviously, the only thing to do here is to write a program to do your homework for you!

Today's challenge is to write a program that calculates the resistance between two points in a circuit. For the necessary background maths, check the bottom of the problem.
------------------------------------------------------------------------------------------------------------------
The input consists of two parts. First, a line that lists a series of IDs for circuit "nodes". These are strings of uppercase characters. The first and last node are to be the start and end point of the circuit.

Next, there will be some number of lines that identify two nodes and specify the resistance between them (in Ohms, for simplicity). This will be a positive number.

Sample input:

A B C
A B 10
A B 30
B C 50

The above input can be interpreted as the circuit:

     +--(10)--+
     |        |
[A]--+        +--[B]--(50)--[C]
     |        |
     +--(30)--+

The output consists of a single number: the resistance between the first and last node, in Ohms. Round to the 3rd decimal place, if necessary.
------------------------------------------------------------------------------------------------------------------
Sample output:

57.5
Explanation: The theory is explained in the last section of this problem, but the calculation to achieve 57.5 is:

1 / (1/10 + 1/30) + 50 = 57.5
------------------------------------------------------------------------------------------------------------------
Planned Procedure:
1.)Read the first dat line to get the number of restistors and their letters.
2.)read the dat file and make two different arrays; one char 2d array with the resistor connectors lines and reorder any out of order (DA turns to AD), and one int array with the resistance levels
3.)Find possible series by matching each line with the end piece and begining piece. If they do not match, make another. Return as the single line (ex. AC - CE - EF = ACEF) and find the resistance of that series
4.)Find possible parallels in curcuit. Find matching begining and end to each. (ACE and ADE have E at the end and are parallel) Find the resistance of that parallel
5.) Add both series and parallel and return value
------------------------------------------------------------------------------------------------------------------
challenge input:
A B C D E F
A C 5
A B 10
D A 5
D E 10
C E 10
E F 15
B F 20

output: 12.857
math behind:
+---10---b---20---f---+
|                     15
a---5---c----10---e---+
|                 |
+---5---d---10----+

Series found: ACE, ABF, ADE, CEF, linked by EF, ACE matching end e limited due to ADE making ACE and ADE parallel
ACE = 15, ADE = 15
A-E = 1/(1/15 + 1/15) = 7.5
A-f = 7.5 + 15 = 22.5
ABF = 30
Total = 1/(1/30 + 1/22.5) = 12.57

------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


void createArray(char [] resistors, int count, char [][2] connectedResistors, double [] levels);
void findSeries(Series [100] series, int seriesCount, char [][2]resistors, double [] levels);
void fixErrorSeries(Series [100] series, int seriesCount, char [][2]resistors, double [] levels);
void identifyParallel(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount);
void calculateLinkedResistance(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount);
double calculateTotalResistance(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount);

class Series
{
public:
	char [] link;
	double level;
	string type;
	Series linked;
	bool done;
}

class Parallel
{
public:
	Series [] link;
	double level;
}

int main()
{	
	double totalResistance;
	char [] resistors;
	int resistorCount;
	char [][2]connectedResistors;
	int [] levels;
	Series [100] series;
	int seriesCount;
	Parallel [100] parallels;
	int parallelCount;
	createArray(resistors, resistorCount, connectedResistors, levels);
	findSeries(series, seriesCount, resistors, levels);
	identifyParallel(series, seriesCount, parallels, parallelCount);
	totalResistance = calculateTotalResistance(series, seriesCount, parallels, parallelCount);
	
	cout<< "Total Resistance: ", totalResitance<<endl; 
	
}

void createArray(char [] resistors, int count, char [][2] connectedResistors, double [] levels)
{
	fstream filein;
	filein.open("file.dat");
	
	if(!filein.fail())
	{	
		while(getline(filein, str))
		{
			int count = 0;
			resistors[count];
			count++;
		}
		}
		int row = 0;
		while(!fin.eof())
		{
			filein>>connectedResistors[row][0];
			filein>>connectedResistors[row][1];
			filein>>levels[row];
			row++;
		}
	}
}

void findSeries(Series [100] series, int seriesCount, char [][2]resistors, double [] levels)
{
	seriesCount = 0;
	for(int i = 0; i < resistors.size(); i++)
	{
		char currentEnd = resistors[i][1];
		for(int j = 0; j < resistor.size(); j++)
		{
			char currentBeginning = resistors[j][0];
		
			if(currentEnd == currentBeginning && linkCount == 1)
			{
				series[seriesCount].link[0] = resistors[i][0];
				series[seriesCount].link[1] = resistors[i][1];
				series[seriesCount].link[2] = resistors[j][1];
				
				series[seriesCount].level += (levels[i] + levels[j]);
				series[seriesCount].type = "series";
				series[seriesCount].linked = NULL;
				series[seriesCount].done = false;
				seriesCount++;
				
			}	
		}
	}
	fixErrorSeries(series, seriesCount, resistors, levels);
}

//looks for possible series where the series is directly connected to another series and removes that part
void fixErrorSeries(Series [100] series, int seriesCount, char [][2]resistors, double [] levels)
{
	for (int i = 0; i < seriesCount; i++)
	{
		Series currentSeriesCheck = series[i];
		for(int j = 0; j < seriesCount; j++)
		
		{	
			if(currentSeriesCheck.link[0] == series[j].link[1] && currentSeriesCheck.link[1] == series[j].link[2])
			{
				series[i].linked = series[j];
				for(int k = 0; k < resistors.size(); k++)
				{
					if(currentSeriesCheck.link[0] == resistors[k][0] && currentSeriesCheck.link[1] == resistors[k][1])
					{
						series[i].level -= levels[k];
					}
				}
			}
		}
	}
}
void identifyParallel(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount)
{
	parallelCount = 0;
	for (int i = 0; i < seriesCount; i++)
	{
		Series currentSeries = series[i];
		//checks to see if the curcuit was already declared a parallel and breaks if so
		if(currentSeries.type == "parallel")
			break;
		else
		{
			for(int j = 0; j < seriesCount; j++)
			{	
				//breaks if checking the same series
				if(currentSeries.link[0] == series[j].link[0] && currentSeries.link[1] == series[j].link[1] && currentSeries.link[2] == series[j].link[2])
					break;
				else
				{
					if(currentSeries.link[0]== series[j].link[0] && currentSeries.link[2]== series[j].link[2])
					{
						series[i].type = "parallel";
						series[j].type = "parallel"
						parallels[parallelCount].link[0] = series[i].link;
						parallels[parallelCount].link[1] = series[j].link;
						parallels[parallelCount].level = 1/((1/series[i].level)+(1/series[j].level));
						parallelCount++;
					}
				}
			}
		}
	}
}

void calculateLinkedResistance(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount)
{
	for(int i = 0; i < seriesCount; i++)
	{
		if(series[i].linked != NULL)
		{
			for(int j = 0; j < parallelCount; j++)
			{
				if(series[i].linked == parallels[j].link[0] || series[i].linked == parallels[j].link[1])
				{
					parallels[j].level += series[i].level;
					series[i].done = true;
				}
			}
		}
	}
}

double calculateTotalResistance(Series [100] series, int seriesCount, Parallel [100]parallels, int parallelCount)
{
	calculateLinkedResistance(series, seriesCount, parallels, parallelCount);
	double totalResistance = 0;
	double subResistance = 0;
	double [] levels;

	for(int i = 0; i < seriesCount; i++)
	{
		if(series[i].done == false)
			levels[i] = series[i].level;
	}
	for(int j = 0; j < parallelCount; j++)
	{
		levels[seriesCount + j] = parallels[j];	
	}
	
	for(int count = 0; count < (seriesCount+parallelCount); count++)
	{
		totalResistance += 1/levels[count];
	}
	
	totalResistance = 1/totalResistance;
	
	return totalResistance;

}


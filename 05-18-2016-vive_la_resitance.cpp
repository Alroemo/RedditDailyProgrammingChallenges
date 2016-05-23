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

Series found: ACE and ABF, linked by EF, ACE matching end e limited due to ADE making ACE and ADE parallel
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


int main()
{	
	char [] resistors;
	int resistorCount;
	char [][2]connectedResistors;
	int [] levels;
	createArray(resistors, resistorCount, connectedResistors, levels);
}
double createArray(char [] resistors, int count, char [][2] connectedResistors, int [] levels)
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

void fixArray(char [][2]connectedResistors, char []resistors)
{
	for(int i = 0; i < connectedResistors.size(); i++)
	{
		for(in)
	}
}
}

double calculate(char[][]array)
{
	double resistanceLevel = 0;
	//get first row to see the number of resistors in the curcuit
	int curcuitCount;
	
	curcuitCount = array[0].size();	
	int numberInParallel[curcuitCount];
	int totalResist[curcuitCount];
		
	//starts on the second row since the first does not have the resistance levels
	for(int row = 1; row < array.size(); row++)
	{
		for(int i = 0; col < curcuitCount;i++)
		{
			if(array[row][0]==array[0][i])
			{
				numberInParallel[i]++;
				totalResist[i]+= array[row][2];
			}
			if(array[row][1]==array[0][i])
			{
				
			}			
		}
		
	}	
	
	return resistanceLevel;;
}

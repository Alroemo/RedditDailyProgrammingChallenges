/*
r/dailyprogrammer challenge #267
05-18-2016 
Intermediate
Vive La Resistance!
---------------------------------------------------------
It's midnight. You're tired after a night of partying (or gaming, or whatever else you like to do when procrastinating), and are about ready to go to sleep when you remember: you have a whole load of homework for your Electronics 101 course. The topic is resistance, and calculating the total resistance of various circuits.

Someone who is not you might do something sensible, like sighing and getting the work done, or even going to sleep and letting it go. But you are a programmer! Obviously, the only thing to do here is to write a program to do your homework for you!

Today's challenge is to write a program that calculates the resistance between two points in a circuit. For the necessary background maths, check the bottom of the problem.
---------------------------------------------------------
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

Sample output:

57.5
Explanation: The theory is explained in the last section of this problem, but the calculation to achieve 57.5 is:

1 / (1/10 + 1/30) + 50 = 57.5


*/

double createArray()
{
	filestream streamreader;
	streamreader.read();
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

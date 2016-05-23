/*
r/dailyprogrammer
05-16-2016
#267 Easy
All The places your dog didn't win
-----------------------------------------------------------------------
Your job is to create a program that lists all places within the range of 0-100 in spoken English, excluding the placing (X) of your winning pup. 
Input is the integer placement of your dog (X) within the range 0-100.
A reader should see a neatly formatted list of placements from 0-100 in spoken English, excluding your dog's placement.

Here's an example in the case of a 1st place finish; 
*/
0th, 2nd, 3rd, 4th, 5th, 6th, 7th, 8th, 9th, 10th, 11st, 12nd, 13rd, 14th, 15th, 16th, 17th, 18th, 19th, 20th, 21st, 22nd, 23rd, 24th, 25th, 26th, 27th, 28th, 29th, 30th, 31st, 32nd, 33rd, 34th, 35th, 36th, 37th, 38th, 39th, 40th, 41st, 42nd, 43rd, 44th, 45th, 46th, 47th, 48th, 49th, 50th, 51st, 52nd, 53rd, 54th, 55th, 56th, 57th, 58th, 59th, 60th, 61st, 62nd, 63rd, 64th, 65th, 66th, 67th, 68th, 69th, 70th, 71st, 72nd, 73rd, 74th, 75th, 76th, 77th, 78th, 79th, 80th, 81st, 82nd, 83rd, 84th, 85th, 86th, 87th, 88th, 89th, 90th, 91st, 92nd, 93rd, 94th, 95th, 96th, 97th, 98th, 99th, 100th, 101st
-----------------------------------------------------------------------
*/

int main(int [] place)
{
	string tense[] = {"st", "nd", "rd"};
	
	for (int i = 0; i < place.size();i++)
	{
		try{cout<<place[i],(tense[(i%10)-1];}	
		Catch (ArrayOutofBound) {cout<<place[i]<<"th";}
	}
	
	return 0;
}

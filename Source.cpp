#include <iostream>
#include <unordered_map>

//Day 15 Part 1
//Given a set of numbers, we will use them to play a game with the following rules, each turn a number is read from the list, once all numbers are read the next number is
//determined by the previous number, if this is the first time the previous number has been read the next number is 0, else if it is not the first time it has been read
//then the next number read is the number of turns apart since the last time it was read.
//Example the given numbers are: 0, 3, 6. The turns will go as follows, 1:0, 2:3, 3:6, 4:0, 5:3, 6:3, 7:1, 8:0, 9:4, 10:0
//To explain, turn 1 we read our first number 0, then turn 2 we read our next number 3, turn 3 we read the next number 6, now that we have read all our numbers in the 
//list we must consider the previous turn's number to get the next one, because this is the first time 6 has appeared we read 0 as the number for turn 4, for turn 5 the
//previous number 0 has appeared before on turn 1 so the previous turn number 4 minus the last turn number it appeared which was 1 which gives 3, the number 3 appeared on
//turn 2 so 5 minus 2 is 3 for turn 6, two 3's in a row, 6 minus 5 makes turn 7's number 1, this is the first time 1 has appeared so turn 8 is 0, 0 last appeared on turn
//4 so 8 minus 4 so turn 9 is 4, this is the first time 4 has appeared so turn 10 is 0.
//The pattern will continue from there.

//So for this we need to keep track of two things, what the number is and the previous place it was spoken and the current, we can store these in a map, where the key is 
//the number and the value is the turn or in this case index, we can initialize the map with the numbers from the list and start on the final number. So to start we have 
//the current turn, and the previous number, we search for the previous number, if it is not found the current turn's number is 0 we then need to set the current
//position to the current turn and the previous position to the stored current position, if it is found we need to subtract the number's current position from its
//previous position and then either insert a new pair or set the current position and previous position of a current number.
//Numbers: 15,12,0,14,3,1 

int findAnswerPart1(std::unordered_map<int, std::pair<int, int>>& input)
{
	int currentTurn = 7;
	int previousNumber = 1;
	int answer = 0;
	

	while (currentTurn <= 2020)
	{
		if (input.find(previousNumber) == input.end())
		{
			if (input.find(0) != input.end())
			{
				input.at(0).second = input.at(0).first;
				input.at(0).first = currentTurn;
				if (currentTurn == 2020)
				{
					answer = 0;
				}
			}
			else
			{
				input.insert(std::make_pair(0, std::make_pair(currentTurn, currentTurn)));
				if (currentTurn == 2020)
				{
					answer = 0;
				}

			}
			previousNumber = 0;
		}
		else
		{
			int newNum = input.at(previousNumber).first - input.at(previousNumber).second;
			if (input.find(newNum) != input.end())
			{
				input.at(newNum).second = input.at(newNum).first;
				input.at(newNum).first = currentTurn;
				if (currentTurn == 2020)
				{
					answer = newNum;
				}
			}
			else
			{
				input.insert(std::make_pair(newNum, std::make_pair(currentTurn, currentTurn)));
				if (currentTurn == 2020)
				{
					answer = newNum;
				}
			}
			previousNumber = newNum;
		}
		currentTurn++;
	}
	return answer;
}

uint64_t findAnswerPart2(std::unordered_map<uint64_t, std::pair<uint64_t, uint64_t>>& input)
{
	uint64_t currentTurn = 7;
	uint64_t previousNumber = 1;
	uint16_t answer = 0;


	while (currentTurn <= 30000000)
	{
		if (input.find(previousNumber) == input.end())
		{
			if (input.find(0) != input.end())
			{
				input.at(0).second = input.at(0).first;
				input.at(0).first = currentTurn;
				if (currentTurn == 30000000)
				{
					answer = 0;
				}
			}
			else
			{
				input.insert(std::make_pair(0, std::make_pair(currentTurn, currentTurn)));
				if (currentTurn == 30000000)
				{
					answer = 0;
				}

			}
			previousNumber = 0;
		}
		else
		{
			uint64_t newNum = input.at(previousNumber).first - input.at(previousNumber).second;
			if (input.find(newNum) != input.end())
			{
				input.at(newNum).second = input.at(newNum).first;
				input.at(newNum).first = currentTurn;
				if (currentTurn == 30000000)
				{
					answer = newNum;
				}
			}
			else
			{
				input.insert(std::make_pair(newNum, std::make_pair(currentTurn, currentTurn)));
				if (currentTurn == 30000000)
				{
					answer = newNum;
				}
			}
			previousNumber = newNum;
		}
		//std::cout << currentTurn << " : " << previousNumber << '\n';
		currentTurn++;
	}
	return answer;
}

int main()
{
	//map key number, current position and previous position
	std::unordered_map<int, std::pair<int, int>> input =
	{
		{15, std::make_pair(1, 1)},
		{12, std::make_pair(2, 2)},
		{0, std::make_pair(3, 3)},
		{14, std::make_pair(4, 4)},
		{3, std::make_pair(5, 5)},
		{1, std::make_pair(6, 6)}
	};

	std::unordered_map<uint64_t, std::pair<uint64_t, uint64_t>> input2 =
	{
		{15, std::make_pair(1, 1)},
		{12, std::make_pair(2, 2)},
		{0, std::make_pair(3, 3)},
		{14, std::make_pair(4, 4)},
		{3, std::make_pair(5, 5)},
		{1, std::make_pair(6, 6)}
	};

	std::cout << findAnswerPart1(input) << '\n';

	std::cout << findAnswerPart2(input2) << '\n';
	return 0;
}
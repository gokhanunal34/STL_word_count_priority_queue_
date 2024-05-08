#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include "pqueue.h"
#include <unordered_map>
#include <cctype>
#include <ctime>
#include<time.h>


using namespace std;

// *********************************************************************************
// * Author: Gokhan Unal                                                           *
// * Function name:  main                                                          *
// * Date: 4/15/2024 - 4/16/2024 - 4/17/2024                                       *
// * Author: Gokhan Unal                                                           *
// * Description: main routine that inherits pqueue.h                              *
// * Reference: 100% from Dr. Gaitros' 4/15/2024 class. He asked us to add our own *
// * flavor to it and I tried as much as I can to show my style in this code       *
// * Notes: Style change update - I enabled intelliCode in Visual Studio 2022 and  *
// * changed some text editing settings to follow certain conventions, that is why *
// * I am using more snake case or avoiding endl whenever it tells me to avoid it  *
// * and use "\n" instead, and style changes in this nature.                       *
// * Lasly, my pqueue.h is Dr. Gaitros' file that he shared on canvas. I made      *
// * trivial changes to it to make sure my output is the way I want it to be.      *
// *********************************************************************************
int main()
{
	clock_t t;
	//create the appropriate maps
	unordered_map<string, int>word_list;
	unordered_map<string, int>number_list;

	char input_char;
	string word;
	string number;

	PQueue<string> word_queue;
	PQueue<string> number_queue;
	PQueue<char> char_queue;
	
	//priority_queue<pair<int, string>>word_queue;
	//priority_queue<pair<int, string>>number_queue;
	//priority_queue<pair<int, char>>char_queue;

	vector<string> word_vector;
	vector<string> number_vector;
	map<char, int> char_map;
	t = clock();
	word.clear();
	number.clear();
	cin.get(input_char);

	while(!cin.eof())
	{
		//check if alphabetic
		if (isalpha(input_char))
		{
			if (!number.empty())
			{
				//if number is found in the list, then push it to both number_vector and number_list
				//and clear the number after the operation
				if (number_list.find(number) == number_list.end()) { number_vector.push_back(number); }
				++number_list[number];
				number.clear();
			}
			//just push the char back in upper case to the word
			word.push_back(toupper(input_char));

			//if it is not found make the value zero for the char key
			if (char_map.find(input_char) == char_map.end())
			{
				char_map[input_char] = 0;
			}
			//if found, increase the key's count, which is second in the pair
			else { char_map.find(input_char)->second++; }

		}//is_alpha check end bracket
		//check if digit
		else if (isdigit(input_char))
		{
			if (!word.empty())
			{
				if (word_list.find(word) == word_list.end()) { word_vector.push_back(word); }
				++word_list[word];
				word.clear();
			}
			number.push_back(input_char);
			if (char_map.find(input_char) == char_map.end())
			{
				char_map[input_char] = 0;
			}
			else { char_map.find(input_char)->second++; }
		}
		else if (!isdigit(input_char) && !isalpha(input_char))
		{
			if (!word.empty())
			{
				if (word_list.find(word) == word_list.end()) { word_vector.push_back(word); }
				++word_list[word];
				word.clear();
			}
			if (!number.empty())
			{
				bool all_bits = true;
				for (char c : number)
				{
					if (!std::isdigit(static_cast<unsigned char>(input_char)))
					{
						all_bits = false;
						break;
					}
				}
				if (all_bits)
				{
					if (number_list.find(number) == number_list.end()) { number_vector.push_back(number); }
					++number_list[number];
					number.clear();
				}
			}
			if (char_map.find(input_char) == char_map.end()) { char_map[input_char] = 0; }
			else { char_map.find(input_char)->second++; }
		}
		cin.get(input_char);
	}
	// ************** Some utilities, tests and precautious operations *************************
	// * Author: Gokhan Unal, no reference, 100% my work except the fact that I am running     *
	// * Dr. Gaitros' pqueue.h and I am using almost all its functions.                        *
	// * Date: 4/15/2024 - 4/16/2024 - 4/17/2024
	// *****************************************************************************************
	//this is a precaution in case there's still something left in number
	//same protocol used above 
	if (!number.empty())
	{
		bool all_bits = true;
		for (char c : number)
		{
			if(!std::isdigit(static_cast<unsigned char>(input_char)))
			{
				all_bits = false;
				break;
			}
		}
		if (all_bits)
		{
			if (number_list.find(number) == number_list.end()) { number_vector.push_back(number); }
			++number_list[number];
			number.clear();
		}
	}

	/*
	//char_map is ordered alphabetically by its key, the second value
	//is int which shows how many times it is encountered. This will have
	//to swap and be sorted since we want the most used of everything
	cout << "**** char_map test ****" << "\n";
	for(auto first = char_map.begin(); first != char_map.end(); ++first)
	{
		auto key = first->first;
		auto val = first->second;
		cout << "Character: " << key << ", Frequency: " << val << "\n";
	}

	cout << "**** word_list test ****" << "\n";
	for (auto first = word_list.begin(); first != word_list.end(); ++first)
	{
		auto key = first->first;
		auto val = first->second;
		cout << "Word: " << key << ", Frequency: " << val << "\n";
	}

	cout << "**** number_list test ****" << "\n";
	for (auto first = number_list.begin(); first != number_list.end(); ++first)
	{
		auto key = first->first;
		auto val = first->second;
		cout << "Number: " << key << ", Frequency: " << val << "\n";
	}
	*/

	//Dr. Gaitros' pqueue implementation takes care
	//of the sorting with the comparator "struct compare".
	//otherwise, I would have had to write a compare struct on
	//my own.
	//dump the word list into word priority queue
	for (const auto& pair : word_list)
	{
		word_queue.AddItem(pair.first, pair.second);
	}

	//dump the number_list into number_queue
	for (const auto& pair : number_list)
	{
		number_queue.AddItem(pair.first, pair.second);
		//if the size is greater than 10, pop from the list
	}

	//dump the char_map into char_queue. 
	for (const auto& pair : char_map)
	{
		char_queue.AddItem(pair.first, pair.second);
	}

	//test printing
	//destructive
	cout << "\n";
	cout << "There are " << word_vector.size() << " unique words." << "\n";
	cout << "TOP 10 MOST USED WORDS: " << "\n";
	//C++ 11 lets double condition
	if(!word_queue.IsEmpty());
	{
		word_queue.Print();
	}

	cout << "\n";
	cout << "There are " << char_map.size() << " unique characters." << "\n";
	cout << "TOP 10 MOST USED CHARACTERS: " << "\n";
	if(!char_queue.IsEmpty())
	{
		char_queue.Print();
	}


	cout << "\n";
	cout << "There are " << number_vector.size() << " unique numbers." << "\n";
	cout << "TOP 10 MOST USED NUMBERS: "<< "\n";
	if (!number_queue.IsEmpty())
	{
		number_queue.Print();
	}

	t = clock()-t;
	float seconds = static_cast<float>(t)/ CLOCKS_PER_SEC;
	cout << "The time it took to perform all the tasks is: " 
	<< seconds << " seconds." << "\n";

	return 0;
}//main end

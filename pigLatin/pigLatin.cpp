/**
* Gabriel H
* pigLatin.cpp
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
* stringToVector converts all the words in one line and puts them 
* into a vector.
* @param userString users the users string of words and returns them into vector
**/
vector<string> stringToVector(string userString);

/**
* display prints each vector of strings 
* @param stringToVector uses all vectors (words/strings)
**/
void display(vector<string> stringToVector);

/**
* firstVowel gets the first vowel of each word and returns its index
* @param vowel finds the first vowel from the users string.
**/
int firstVowel(string vowel);

/**
* firstY gets the first 'y' from each word if any, and returns its index.
* @param pFirstY finds the position of 'y' from the users string.
**/
int firstY(string pFirstY);

/**
* toPigLatin converts all words into pig latin using functions
* firstVowel and firstY.
* @param pConvert is a vector of strings, also pass by reference.
**/
void toPigLatin(vector<string>& pConvert);

/**
* hasVowel will be true if the string contains a vowel.
* @param line grabs a word and looks if it has a vowel, if so it becomes true.
**/
bool hasVowel(string line);


int main()
{
	/**
	* A vector called strVect is created which will
	* get the users input(stored into string usersString).
	* strVect will be assigned to stringToVector when it is called.
	**/
	vector<string> strVect;
	string usersString;
	getline(cin, usersString);
	strVect = stringToVector(usersString);

	/**
	* the remaining of these are function calls,
	* display prints the result.
	* firstVowel looks for the first vowel's index for each word.
	* firstY looks for the firstY of each word.
	* toPigLatin changes the vectors words from English to Pig Latin.
	* display is used again to show the result of Pig Latin.
	**/
	display(strVect);
	firstVowel(usersString);
	firstY(usersString);
	toPigLatin(strVect);
	display(strVect);
	
}


/**
* stringToVector breaks the sentence into words with each word stored
* as a string element in a vector.
* returns strVect
**/
vector<string> stringToVector(string userString)
{
	string temp = "";
	vector<string> strVect;
	unsigned int i;
	for (i = 0; i < userString.size(); i++)
	{
		if (userString[i] == ' ') 
		{
			strVect.push_back(temp); 
			temp = "";
		}
		else
		{
			temp.push_back(userString[i]);
		}

	}
	strVect.push_back(temp); // another push_back used to get the last word.
	return strVect;
}


/**
* display will display the sentence back onto the screen
**/
void display(vector<string> stringToVector)
{
	for (unsigned i = 0; i < stringToVector.size(); i++)
	{
		if (i == 0)
		{
			cout << stringToVector[i];
		}
		else
		{
			cout << ' ' << stringToVector[i];
		}
	}
	cout << endl;
}

/**
* firstVowel finds the first vowel of each word.
* returns found (first vowel in the word).
**/
int firstVowel(string vowel)
{
	int found = vowel.find_first_of("aeiou");
	
	return found;
}

/**
* firstY finds the first letter Y in each word.
* returns found (index of where the first letter Y was found
**/
int firstY(string pFirstY)
{
	int found = pFirstY.find_first_of("y");
	
	return found;
}


// toPigLatin will convert each word in the vector to pig latin.
void toPigLatin(vector<string>& pConvert)
{
	string temp = "";
		for (unsigned int i = 0; i < pConvert.size(); i++)
		{
			temp = pConvert[i];
			int intFirstVowel = firstVowel(pConvert[i]);
			int intFirstY = firstY(pConvert[i]);
			
			if ((intFirstVowel != 0) && hasVowel(temp)) // if the vowel isnt 0 and vowel is present in word, do:
			{
				string temp2 = "";
				string strConsonants = "";
				for (int j = 0; j < intFirstVowel; j++) // loop and stop right before reaching the vowel.
				{
					strConsonants += temp[j]; // add the consonants together
				}
				for (int j = intFirstVowel; j < temp.length(); j++) // loop in temp string from first vowel
				{
					temp2 += temp[j]; //sets temp2 = the temp string starting with first vowel
				}
				temp = temp2; // now temp starts with the first encountered vowel
				pConvert[i] = temp + "-" + strConsonants + "ay"; 
			}
			else if (intFirstVowel == 0) //if word starts with vowel, do:
			{
				pConvert[i] = temp + "-" + "yay"; // adds -yay to end of word
			}
			else if (temp[0] == 'y') // if word starts with 'y', do:
			{
				temp.erase(temp.begin()); //erases the first word
				temp += "-yay"; // adds "-yay" to end of word in temp
				pConvert[i] = temp; // the word now becomes temp
			}
			else if (intFirstY > 0) // if word doesn't start with 'y' but has a y, do:
			{
				string firstPart = "";
				string cons = "";
				for (int j = 0; j < intFirstY; j++)
				{
					cons.push_back(temp[j]);
				}
				for (int j = intFirstY; j < temp.length(); j++)
				{
					firstPart.push_back(temp[j]);
				}
				temp = firstPart;
				pConvert[i] = temp + "-" + cons + "ay";
			}
		}
	cout << endl;
}


// hasVowel will check if the wordh as a vowel in it, if so it will become true.
// returns found
bool hasVowel(string line)
{
	bool found = false;
	for (int i = 0; i < line.length(); i++)
	{
		if ((line[i] == 'a') || (line[i] == 'e') || (line[i] == 'i') || (line[i] == 'o') || (line[i] == 'u'))
			found = true;
	}
	return found;
}

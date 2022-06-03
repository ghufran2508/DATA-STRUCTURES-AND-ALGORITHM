#include<iostream>
#include"stack.h"
#include<string>

using namespace std;

int main()
{
	string sentence;
	stack<string> reverse_stack;
	string reverse = "";

	cout << "Enter the sentence: ";
	getline(cin, sentence);

	string word = "";

	//run through each letter in the sentence..
	for (int i = 0; i < sentence.size(); i++)
	{	
		//if it finds a space in the sentnce, then it would be called as 1 word.
		//and then that word would be pushed in the stack.
		if (sentence[i] == ' ')
		{
			reverse_stack.push(word);
			word = "";
		}
		else
			word += sentence[i];	//if it does not find a space, word length increase.
	}
	//push the last word in the stack.
	reverse_stack.push(word);

	//poping out and storing the sentence in the string.
	while (!reverse_stack.isEmpty())
	{
		reverse += reverse_stack.pop();
		reverse += ' ';
	}
	//displaying the reverse string on the console.
	cout << reverse << endl;

	return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string x;
	vector <string> code;
	string project;
	vector <string> word;
	ifstream inFile;

	inFile.open("test.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}

	// taking the whole code as input from user 
	while (getline (inFile,x)) {
		code.push_back(x);
	}
	
	for (int i = 0; i < code.size(); i++)
	{
		code[i].insert(code[i].begin(), ' ');
		code[i].insert(code[i].end(), ' ');
	}
	
	
	for (int i = 1; i < code.size(); i++)
	{
		code[0] = code[0] + code[i];
	}

	inFile.close();
	project = code[0];
	cout << project;

	// in this part we will exclude all comments and see weither there is a syntax error or not
	
	for (int i = 0 ; i < project.length() ; i++)
	{
		if (project[i] == '{')
		{
			int found = project.find('}', i);
			if (found == -1)
			{
				cout << "syntax error in comment";
				exit(1);
			}
			else
			{
				project.erase(i, found-i+1);
				//i = found;
			}
		}
		else
			continue;
	}
	
	// now we need to handle all spaces between the string elements
	for (int i = 0; i < project.length(); i++)
	{
		switch (project[i])
		{
		    case '+':
			case '-':
			case '*':
			case '/':
			case '=':
			case '<':
			case '(':
			case ')':
			case ';':
			case '\t':
				project.insert(i, " ");
				project.insert(i+2, " ");
				i = i + 2;
				break;
			case ':':
				if (project[i + 1] == '=')
				{
					project.insert(i, " ");
					project.insert(i + 3, " ");
					i = i + 3;
					break;
				}
				break;

		}
	}
	for (int i = 0; i < project.length(); i++)
	{
		if (project[i] == ' ')
		{
			if (project[i + 1] == ' ')
			{
				continue;
			}
			else
			{
				int found_space = project.find(' ',i+1);
				string cut = project.substr(i + 1, found_space - i - 1);
				if (cut == "\t")
				{
					i = found_space - 1;
				}
				else
				{
					word.push_back(cut);
					i = found_space - 1;
				}
				

			}
		}
	}


	cout << "\n" << "\n";
	cout << project;
	cout << "\n" << "\n";
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i];
		cout << "\n";
	}
	cout << "\n" << "\n";
	return 0;
}

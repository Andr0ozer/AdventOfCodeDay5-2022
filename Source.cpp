#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	map<int, vector<char>> stack;
	vector<char> tempmove;
	string currentline;
	bool paststa = false, partII = false;
	int colnum, move, from, to;
	char current;
	ifstream infile;
	infile.open("input.txt");
	while (!infile.eof())
	{
		getline(infile, currentline);
		if (currentline.empty())
		{
			paststa = true;
		}
		if (!paststa)
		{
			colnum = 1;
			for (int i = 1; i <= 33; i = i + 4)
			{
				if (currentline[i] != ' ') {
					stack[colnum].push_back(currentline[i]);
				}
				colnum++;
			}
		}
		else if (!currentline.empty())
		{
			currentline = currentline.substr(5, currentline.size()-1);
			move = stoi(currentline.substr(0, 2));
			currentline = currentline.substr(2, currentline.size() - 1);
			if (currentline[0] == ' ')
			{
				currentline = currentline.substr(1, currentline.size() - 1);
			}
			currentline = currentline.substr(5, currentline.size() - 1);
			from = stoi(currentline.substr(0, 1));
			currentline = currentline.substr(5, currentline.size() - 1);;
			to = stoi(currentline);	
			if (partII)
			{
				for (int j = 0; j < move; j++)
				{
					tempmove.push_back(stack[from].at(0));
					stack[from].erase(stack[from].begin());
				}
				for (int k = tempmove.size() - 1; k >= 0; k--)
				{
					stack[to].insert(stack[to].begin(), tempmove[k]);
					tempmove.pop_back();
				}
			}
			else
			{
				for (int j = 0; j < move; j++)
				{
					stack[to].insert(stack[to].begin(), stack[from].at(0));
					stack[from].erase(stack[from].begin());
				}
			}
		}
	}
	infile.close();
	for (int i = 1; i <= 9; i++)
	{
		cout << stack[i].at(0);
	}
}
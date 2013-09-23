// TCTemplate.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SquareCipher {
public:
	vector<string> squareCipher(string inp) 
	{
		for(int a = 0; a < inp.length(); a++)
		{
			if(inp[a] == ' ')
			{
				inp.erase(a,1);
				a--;
			}
		}
        int columns = 2;
        int rows = 1;
        while (columns * rows < inp.length())
        {
            columns++;
            rows++;
        }
		int spacesToAdd = (columns * rows) - inp.length();
        for (int i = 0; i < spacesToAdd; i++)
            inp += " ";
		int x = 0;
        vector<string> input (rows, "");
        for (int i = 0; i < rows; i++)
        {
            input[i] = inp.substr(x, columns);
            x += columns;
        }
		vector<string> res (input[0].length(), "");
        for (int i = 0; i < input[0].length(); i++)
        {
            for (int a = 0; a < input.size(); a++)
            {
				stringstream ss;
				string temp;
				ss << input[a][i];
				ss >> temp;
                if (temp != " ")
                    res[i] += ss.str();
            }
        }
		return res;
	}
};



int main()
{
	SquareCipher s;
    cout << "Give me a sentence to encode:" << endl;
    string inp;
	getline(cin, inp);
    vector<string> res = s.squareCipher(inp);
    cout << endl;
    cout << "The sentence: " << "-- " << inp << " -- " << endl;
    cout << "Has become: " << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}


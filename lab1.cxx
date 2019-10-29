/*
 * 1lab.cxx
 * 
 * Copyright 2019 Yarek <Yarek@DESKTOP-9V1V25M>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;

const double PI = 4.*atan(1.);

void Calc(string *str, stack <double> *steck)
{
	if (*str=="x") {steck->push(PI);}
	else if (*str=="+") 
		{
			double temp1, temp2, summ;
			temp1 = steck->top();
			steck->pop();
			temp2 = steck->top();
			steck->pop();
			summ = temp1 + temp2;
			steck->push(summ);
		}
	else if (*str=="-") 
		{
			double temp1, temp2, diff;
			temp1 = steck->top();
			steck->pop();
			temp2 = steck->top();
			steck->pop();
			diff = temp2 - temp1;
			steck->push(diff);
		}
	else if (*str=="*") 
		{
			double temp1, temp2, multi;
			temp1 = steck->top();
			steck->pop();
			temp2 = steck->top();
			steck->pop();
			multi = temp2 * temp1;
			steck->push(multi);
		}
	else if (*str=="sin") 
		{
			double temp;
			temp = steck->top();
			steck->pop();
			steck->push(sin(temp));
		}
	else if (*str=="cos") 
		{			
			double temp;
			temp = steck->top();
			steck->pop();
			steck->push(cos(temp));
		}
	else if (*str=="tan") 
		{
			double temp;
			temp = steck->top();
			steck->pop();
			steck->push(tan(temp));
		}
}

void Debug(string *str, stack <double> *steck)
{
	cout << "STECK: " << steck->top() << endl;
	cout << "WORD: " << str[0] << endl;
}

int main(int argc, char **argv)
{
	int N=0;
	string fStr;
	if(cin.peek() == '\n'){cout<< "Stream empty!" <<endl; return 0;}
	//freopen("IN.txt", "r", stdin); //good work on Windows :c
	ofstream OUT("OUT.txt");
	while (getline(cin, fStr))
	{
		stack <double> *steck;	
		steck = new stack<double>();
		string str[256];
		
		stringstream *ss;
	    ss = new stringstream();
	    
		*ss << fStr;
		*ss >> N;
		if (N==0) {cout << "\nAll examples have been successfully solved!\n" 
			"The answers were duplicated in the <<OUT>> in this directory." << endl; fclose(stdin); OUT.close(); return 0; }
		//cout << fStr << endl; uncomment for see example from stdin
		//cout << "N = " << N << endl; uncomment for debugging!
		for(int i=0; i<N; i++)
		{					
			*ss >> *str;
			Calc(str, steck);
			//Debug(str, steck); uncomment for debugging!
		}
		if (!steck->top())
		{
			OUT  <<"Identity\n"; 
			cout << "Identity" << endl;
		}
		else 
		{
			OUT  <<"Non an identity\n"; 
			cout << "Non an identity" << endl;
		}
		//cout << "------------------" << endl;
		ss->clear();		
	}
	OUT.close();
	fclose(stdin);
	return 0;
}

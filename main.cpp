/**
Belle Erhardt
April 2021

Purpose:
This program reads data from a file into a graph structure, 
using a graph algorithum return the cheapest flight for 
destination requested by user.

Goal:
Return Aqurate feedback: failed to aquire
keep this program running at O(nLog(n)):failed to aquire
*/

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <utility>
#include "Graph.hpp"
#include "Flight.hpp"
using namespace std;
int main(int argc, char *arv[])
		{
		Graph graph;
		string filename;
		string depart;
		string arrive;
		string number;
		cout <<"Enter your file: ";
		cin>> filename;
		graph.setAirports(filename);
		cout << "Enter departing airport: ";
		cin >> depart;
		cout << "Enter arriving airport: ";
		cin >> arrive;
		graph.planTrip(depart, arrive);
		graph.printData();
		return 0;
		}		

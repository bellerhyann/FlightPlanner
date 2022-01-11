/*
Belle Erhardt 
May 2021
 * 
 */
 #include "Flight.hpp"
#include "Graph.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

void
Graph::setAirports(string fName)
	{
	string temp;
	int n, m;
	int a,b;
	//n: How many Nodes in file
	ifstream file(fName.c_str());
	file >> n;
	_nodes = n;
	//program uses their index to find data later
	for (int l = 0; l < n; l++)
		{
	 	file >> temp;
		airports.push_back(temp);
		}
	connections.resize(n);
	Flight flight;
	//m: How many Edges in file
	file >> m;
	_medges = m;
	while(file)
		{ 
		a= 0;
		b = 0;
		flight.read(file);
		//grab indexes
	while(airports[a] != flight.a1())
		{
		a++;
		}
	while (airports[b] != flight.a2())
		{
		b++;
		}
	flight.index(a, b);	
	//append to connections
	connections[flight.lowerIndex()].push_back(flight);
  	}
  	}
  
void
Graph::planTrip(string start, string end)
	{
	//iterator finds node
	int a=0;
	int b=0;
	infin = numeric_limits <int>::infinity(); 
	Flight myTrip(start, end, a, b, infin);
	while(airports[a] != myTrip.a1())
		{
		a++;
		}
	while (airports[b] != myTrip.a2())
		{
		b++;
		}
		myTrip.index(a,b);
		//itinerary.push_back(myTrip);
		vector<Flight>::iterator firstColumn;
		firstColumn = connections[myTrip.lowerIndex()].begin();
		grandTotal = connectionCheck(firstColumn, infin, myTrip.lowerIndex(), myTrip.higherIndex());	
	}
int potentialCost =0;
int flightPrice;
int debug= 0;
//this version of my connection check at least compiles and has my attempt at recursion 
int
Graph::connectionCheck(vector<Flight>::iterator check, int RT, int i1, int i2)
	{
	if(check != connections[itinerary.begin()->lowerIndex()].end())//long as we are not of the end of first column
		{
		if(check == connections[i1].end())
			{
			//remove the one that didn't have a connection
			itinerary.pop_back();
			int lastVal = itinerary.end()->higherIndex();
			int lastInd = itinerary.end()->lowerIndex();
			check = connections[lastInd].begin();
			while(check->higherIndex() != lastVal)
				{check++;}
			check++;
			connectionCheck(check, RT, i1, check->higherIndex());
			}	
					
		flightPrice = check->price();
		potentialCost += flightPrice;
		while(potentialCost<RT)
			{
			RT=potentialCost;
			//append to itinerary
			testItinerary.push_back(*check);
			//add to list of flight options?
			
			//if reached destination set check to end of that column
			if(check->higherIndex()== itinerary.end()->higherIndex())
				{
				itinerary = testItinerary;
				check = itinerary.begin();
				testItinerary.clear();
				//adding one will check the paths below
				check++;
				check= connections[i1].end();
				connectionCheck(check, RT, i1, check->higherIndex());
				}
			}
		if(potentialCost>RT)
			{
			potentialCost-=flightPrice;
			check++;
			connectionCheck(check, RT, i1, check->higherIndex());
			}
		}
		return RT;
	}
/*
int potentialCost =0;
int
Graph::connectionCheck(vector<Flight>::iterator check, int RT, int i1, int i2)
	{
	int cheapestEdge=infin;
	Flight cheapestConnection;
	int connection;
	int counter =0;
	vector<Flight> bestTrip;
	//if the iterator "check"  is not = the end of the starting index
	for(counter<_nodes)
		{
		while(check != connections[i1].end())//long as we are not of the end of first column
			{
				if(check->higherIndex()==i2)
					{
					RT=potentialCost;
					itinerary.push_back(*check);
					}
				if(check->price() < cheapestEdge)
					{
					testItinerary.push_back(*check);
					cheapestConnection= *check;
					connection = check->higherIndex();
					}
					testItinerary.empty();
					check++;
				}
				//Checks Next area
				check = connections[connection].begin();
				potentialCost+= cheapestEdge;
				//connectionCheck(check, RT, i1, check->higherIndex());
		}
	return RT;
	}*/

void
Graph::printData()
{
string flights;
string start;
vector<Flight>::iterator x;
/*if(x->first != sFi)
{
reverse(itinerary.begin(), itinerary.end());
}*/
x= itinerary.begin();
cout << "Cheapest itinerary would be $" << grandTotal << endl;
cout<<x->a1();
for(x; x<itinerary.end(); x++)
{
cout<< "->" << x->a2();
x++;
}
cout<< " " << endl;
}





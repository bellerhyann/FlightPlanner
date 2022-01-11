/*
Belle Erhardt 
May 2021
 * 
 */
 
 #ifndef _GRAPH_HPP_
#define _GRAPH_HPP_
#include "Flight.hpp"
#include <iostream>
#include<fstream>
#include<vector>
#include<string>

class Graph
{
private:
std:: vector <std::string> airports;
std:: vector<std::vector<Flight>> connections;
std:: vector<Flight> itinerary;
std:: vector<Flight> testItinerary;
int infin;
int grandTotal;
int _nodes;
int _medges;
public:
void setAirports(std::string fName);
void planTrip(std::string start, std::string end);
int connectionCheck(std:: vector<Flight>::iterator check, int RT, int i1, int i2);
void printData();
};
#endif


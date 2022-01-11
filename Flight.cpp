/*
Belle Erhardt 
May 2021
 * 
 */
 
#include "Flight.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

void 
Flight::index(int firstLocation,  int secondLocation)
{
	if(firstLocation<secondLocation)
	{
	_firstLocation = firstLocation;
	_secondLocation = secondLocation;
	}
	else if (firstLocation>secondLocation)
	{
	_firstLocation = secondLocation;	
	_secondLocation = firstLocation;
	}
}
istream&
Flight::read (istream &is)
{
  //getline(is, _airport1);
  is>>_airport1;
  is >> _airport2;
  is >> _flightPrice;

  string dummy;
  getline(is, dummy);
  
  return is;
}


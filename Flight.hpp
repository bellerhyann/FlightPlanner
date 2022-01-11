/*
 * 
 */
 
/*
Belle Erhardt 
May 2021
 * 
 */
#ifndef _FLIGHT_HPP_
#define _FLIGHT_HPP_
#include <iostream>
#include<fstream>
#include<vector>
#include<string>


class Flight
{
private:
std::string _airport1;
std::string _airport2;
int _firstLocation; //locations are intergers assigned to each name 
int _secondLocation; //the first is the lower of the two values
int _flightPrice;
public:
  // default constructor
Flight() :_airport1(), _airport2(), _firstLocation(0), _secondLocation(0), _flightPrice(0) {}

  // fully qualified constructor
Flight(std::string a1, std::string a2, int fl, int sl, int fp)
 : _airport1(a1), _airport2(a2), _firstLocation(fl), _secondLocation(sl), _flightPrice(fp) {}
 //Methods of Flight Class
void index(int firstLocation,  int secondLocation);
std::istream& read (std::istream &is);   

// accessor and modifiers
const std::string& a1() const {return _airport1;}
std::string& a1() {return _airport1;}

const std::string& a2() const {return _airport2;}
std::string& a2() {return _airport2;}

const int& lowerIndex() const {return _firstLocation;}
int& lowerIndex() {return _firstLocation;}

const int& higherIndex() const {return _secondLocation;}
int& higherIndex() {return _secondLocation;}

const int& price() const {return _flightPrice;}
int& price() {return _flightPrice;}

};
#endif
 

//
//  airline.cpp

#include "airline.h"
Airline::Airline():name("NULL"),flights(),num_flights(0){}
Airline::Airline(string n, vector<Flight> *f, int numf):name(n),flights(f),num_flights(numf){}

string Airline::get_name(){
  return name;
}
vector<Flight>* Airline::get_flights(){
  return flights;
}
int Airline::get_numflights(){
  return num_flights;
}
void Airline::set_name(string n){
  name = n;
}
void Airline::set_flights(vector<Flight>* f){
  flights = f;
  
}
void Airline::set_numflights(int numf){
  num_flights = numf;
}
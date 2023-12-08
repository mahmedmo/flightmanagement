//
//  airline.h
//  ENSF FINAL PROJECT

#include "flight.h"
#include <vector>
#ifndef AIRLINE_H
#define AIRLINE_H
class Airline{
  public:
    Airline();
    Airline(string n, vector<Flight>* f, int numf);
    string get_name();
    vector<Flight>* get_flights();
    int get_numflights();
    void set_name(string n);
    void set_flights(vector<Flight>* f);
    void set_numflights(int numf);
  

  private:
    string name;
    vector<Flight>* flights;
    int num_flights;
};
#endif
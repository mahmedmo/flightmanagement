//
//  main.h
//  ENSF FINAL PROJECT

#include "airline.h"
#ifndef MAIN_H
#define MAIN_H
Flight populate_flight(string path,Airline* a);
void displayHeader();
void displayPassenger(Flight* f);
void PressEnter();
void add_passenger(Flight* f);
void remove_passenger(Flight* f);
void save_data(Flight* f);
void cleanStream();
#endif

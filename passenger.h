//
//  passenger.h
//  ENSF FINAL PROJECT

#include "seat.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
#ifndef PASSENGER_H
#define PASSENGER_H

class Passenger{
    public:
        Passenger();
        Passenger(int i, string f, string l, string p, Seat* s);
        int get_id();
        string get_first_name();
        string get_last_name();
        string get_phone_number();
        Seat* get_seat();
        void set_id(int i);
        void set_first_name(string f);
        void set_last_name(string l);
        void set_phone_number(string p);
        void set_seat(Seat* s);
        void print_info();

    private:
        int id;
        string first_name;
        string last_name;
        string phone_number;
        Seat* assigned_seat;
        
};
#endif

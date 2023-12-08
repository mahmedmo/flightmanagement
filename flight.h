//
//  flight.h
//  ENSF FINAL PROJECT

#include "passengerlist.h"
#ifndef FLIGHT_H
#define FLIGHT_H
class Flight{
    public:
        Flight();
        Flight(string f, PassengerList p,int max_row, int max_col);
        void print_seatmap();
        string get_flight_number();
        PassengerList& get_passenger_list();
        int get_max_row();
        int get_max_col();
        void set_passenger_list(const PassengerList& p);
        void set_flight_number(string fn);
        void set_max_row(int r);
        void set_max_col(int c);
        void save(const string& path);
        bool isRowFree(int r);
        bool isSeatFree(int r, char c);
    private:
        string flight_number;
        PassengerList passenger_list;
        int max_row;
        int max_col;
};
#endif
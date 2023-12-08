//
//  seat.h
//  ENSF FINAL PROJECT

#include <string>
using namespace std;
#ifndef SEAT_H
#define SEAT_H
class Seat{
    public:
        Seat(){row = 0; col = 0;};
        Seat(int r, int c);
        int get_seat_row();
        int get_seat_col();
        string get_seat_letter();
        string get_seat_number();
        void set_seat_row(int r);
        void set_seat_col(int c);
        void set_seat_letter(string l);

    private:
        int row;
        int col;
        string seat_letter;
        string seat_number;

};
#endif

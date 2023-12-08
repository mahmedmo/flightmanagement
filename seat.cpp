//
//  seat.cpp
//  ENSF FINAL PROJECT

#include "seat.h"
Seat::Seat(int r, int c) : row(r), col(c) {

}
//return seat row
int Seat::get_seat_row(){
    return row;
}
//return seat col
int Seat::get_seat_col(){
    return col;
}
//return seat letter
string Seat::get_seat_letter(){
    return seat_letter;
}
//set seat row
void Seat::set_seat_row(int r){
    row = r;
}
//set seat col
void Seat::set_seat_col(int c){
    col = c;
}
//set seat letter
void Seat::set_seat_letter(string l){
    seat_letter = l;
}
/* returns the seat number which is the row number + seat letter.
For example, if a seat was in row 3 and has a seat letter of 'A' then this function returns "3A" */
string Seat::get_seat_number(){
    return (to_string(row) + seat_letter);
}

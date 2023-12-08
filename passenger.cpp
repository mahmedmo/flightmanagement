//
//  passenger.cpp
//  ENSF FINAL PROJECT

#include "passenger.h"
//default constructor
Passenger::Passenger():id(0),first_name(),last_name(),phone_number(),assigned_seat(NULL){};

//initialize passenger
Passenger::Passenger(int i, string f, string l, string p, Seat* s){

}
//return id
int Passenger::get_id(){
    return id;
}
//return f name
string Passenger::get_first_name(){
    return first_name;
}
//return l name
string Passenger::get_last_name(){
    return last_name;
}
//return phone number
string Passenger::get_phone_number(){
    return phone_number;
}
//return a pointer to seat READ ONLY
Seat* Passenger::get_seat(){
    return assigned_seat;
}
//set id of passenger
void Passenger::set_id(int i){
  id = i;
}
//set first name of passenger
void Passenger::set_first_name(string f){
    first_name = f;
}
//set last name of passenger
void  Passenger::set_last_name(string l){
    last_name = l;
}
//set phone number of passenger
void Passenger::set_phone_number(string p){
    phone_number = p;
}
//set seat of passenger
void Passenger::set_seat(Seat* s){
    assigned_seat = s;
}
//prints all members of passenger to the terminal using cout (follow examples on D2L)
void Passenger::print_info(){
    int spacing = 0;
    cout << first_name;
    spacing = 19 - first_name.length();
    while(spacing>0){
        cout << " ";
        spacing--;
    }
    cout << last_name;
    spacing = 21 - last_name.length();
    while(spacing>0){
        cout << " ";
        spacing--;
    }
    cout << phone_number;
    spacing = 17 - phone_number.length();
    while(spacing>0){
        cout << " ";
        spacing--;
    }
    cout << assigned_seat->get_seat_row();
    spacing = 8 - to_string(assigned_seat->get_seat_row()).length();
    while(spacing>0){
        cout << " ";
        spacing--;
    }
    cout << assigned_seat->get_seat_letter();
    spacing = 10 - assigned_seat->get_seat_letter().length();
    while(spacing>0){
        cout << " ";
        spacing--;
    }
    cout << id << endl;
}

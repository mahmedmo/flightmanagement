//
//  passengerlist.h
//  ENSF FINAL PROJECT

#include "passenger.h"
#include <fstream>
#include "assert.h"
#ifndef PASSENGERLIST_H
#define PASSENGERLIST_H

struct Node {
  Passenger p;
  Node* next;
};

class PassengerList{
    public:
        PassengerList(); 
        ~PassengerList();
        void insert(Passenger& itemP);
        void remove(Passenger& itemP);
        PassengerList& operator=(const PassengerList& rhs);
        void copy(const PassengerList& src);
        Node* const get_head()const;
        void set_head(Node* n);
        Passenger*  search(int id);
    private:
        Node* headM;
        void destroy();

};
#endif
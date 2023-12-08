//
//  flight.cpp
//  ENSF FINAL PROJECT

#include "flight.h"
Flight::Flight():flight_number(),max_row(0),max_col(0){};
//constructor for flight. Create flight object with it's member
Flight::Flight(string f, PassengerList pl,int max_row, int max_col){

}
PassengerList& Flight::get_passenger_list(){
  return passenger_list;
}
string Flight::get_flight_number(){
  return flight_number;
}
int Flight::get_max_row(){
  return max_row;
}
int Flight::get_max_col(){
  return max_col;
}
void Flight::set_max_row(int r){
  max_row = r;
}
void Flight::set_max_col(int c){
  max_col = c;
}
void Flight::set_passenger_list(const PassengerList& src){
    passenger_list = src;
}
void Flight::set_flight_number(string fn){
  flight_number = fn;
}
/*
print seatmap of flight to terminal. It's essentially like printing out a matrix. 
loop through the passengerslist and print their respective seat LETTER. 
At the leftmost of each row print the row number and at the top of each column
print the col number. The result will be rows and columns that map out all the seats
by letter, with useful indicators of row and col on the outer left and top sides respectively.
*/
void Flight::print_seatmap() {
    // Assuming the PassengerList class has a method to get the list of passengers.
    //std::vector<Passenger> passengers = passenger_list.get_passenger();
    //we can retrieve the passenger list by referring to the linked list
    //in passengerlist included within the flight class
    
    // Print column headers (seat letters) edit: print letters up to the max col   number
    cout << "    ";
    char seatLetter = 'A';
    for (int j = 0; j < max_col; seatLetter++) {
        cout << " " << seatLetter << " ";
        j++;
    }
    cout << "\n"<<endl;

    // Iterate through rows
    //quick change here instead of getmaxrownumber
    
    for (int row = 1; row <= max_row; row++) {
        
        // Print row number
        if(row>9){
          cout << row << "  ";
        }else{
          cout << row << "   ";
        }
        // Iterate through columns
          for (int col = 0; col < max_col; col++)  {
            // Check if a passenger is assigned to the current seat
            Node* curr_p = passenger_list.get_head();
            bool isOccupied = false;
            while (curr_p!=0) {
                if (col == curr_p->p.get_seat()->get_seat_col() &&
                    curr_p->p.get_seat()->get_seat_row() == row) {
                    isOccupied = true;
                    break;
                }
                curr_p = curr_p->next;
            }
            // Print seat status
            if (isOccupied) {
                cout << " X ";
            } else {
                cout << " _ ";
            }    
        }

        cout << "\n"<<endl;
    }
}
void Flight::save(const string& path){
    ofstream file(path);
    if(file.is_open()){
      Node* curr_p = passenger_list.get_head();
      file<< flight_number<< "   "<<max_row<<"   "<<max_col<< endl;
      while(curr_p!=0){
          int spacing = 0;
          file << curr_p->p.get_first_name();
          spacing = 19 - curr_p->p.get_first_name().length();
          while(spacing>0){
              file << " ";
              spacing--;
          }
          file << curr_p->p.get_last_name();
          spacing = 21 - curr_p->p.get_last_name().length();
          while(spacing>0){
              file << " ";
              spacing--;
          }
          file << curr_p->p.get_phone_number();
          spacing = 17 - curr_p->p.get_phone_number().length();
          while(spacing>0){
              file << " ";
              spacing--;
          }
          file << curr_p->p.get_seat()->get_seat_number();
          spacing = 8 - (curr_p->p.get_seat()->get_seat_number()).length();
          while(spacing>0){
              file << " ";
              spacing--;
          }
          
          file << curr_p->p.get_id() << endl;
          curr_p = curr_p->next;
      }
      file.close();
    }else{
        cout << "Unable to open file: " << path << endl;
    }
}
bool Flight::isRowFree(int r){
        int rowCount = 0;
        // Iterate through columns
          for (int col = 0; col < max_col; col++)  {
            // Check if a passenger is assigned to the current seat
            Node* curr_p = passenger_list.get_head();
            while (curr_p!=0) {
                if (col == curr_p->p.get_seat()->get_seat_col() &&
                    curr_p->p.get_seat()->get_seat_row() == r) {
                    rowCount++;
                    break;
                }
                curr_p = curr_p->next;
            }
            
            
         }
         if(rowCount == r){
          return false;
         }
         return true;

        
}
bool Flight::isSeatFree(int r, char c){
            Node* curr_p = passenger_list.get_head();
            while (curr_p!=0) {
                if (curr_p->p.get_seat()->get_seat_row() == r &&
                    curr_p->p.get_seat()->get_seat_letter()[0] == c) {
                    return false;
                    break;
                }
                curr_p = curr_p->next;
            }
      
            return true;
        
}


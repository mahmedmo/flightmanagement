//
//  main.cpp
//  ENSF FINAL PROJECT

#include "main.h"
#include <limits>
#include <sstream>
#include "assert.h"
#include "stdbool.h"
int menu()
{
    int choice = -1;
    cout<< "Please select one of the following:\n"
        << "1. Display Flight Seat Map \n"
        << "2. Display Passenger Information \n"
        << "3. Add a New Passenger \n"
        << "4. Remove an Existing Passenger \n"
        << "5. Save data \n"
        << "6. Quit \n"
        << endl;

    while (!(cin >> choice) || !(choice >= 1) || !(choice <= 6)) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input. Please make a selection from 1 to 6... \n"
             << "1. Display Flight Seat Map \n"
             << "2. Display Passenger Information \n"
             << "3. Add a New Passenger \n"
             << "4. Remove an Existing Passenger \n"
             << "5. Save Data \n"
             << "6. Quit \n"
             << endl;
    }
    return choice;
    
}
int main(){
    #ifndef PROGRAM_START
    #define PROGRAM_START
      displayHeader();
      Airline a;
      vector<Flight> flight_list;
      Flight f = populate_flight("flight_info.txt", &a);
      flight_list.push_back(f);
      a.set_flights(&flight_list);
      // cout<< "airline check " << a.get_flights()->at(0).get_passenger_list().get_head()->p.get_first_name() << endl;
      // cout<< "airline check name " << a.get_name() << endl;
      // cout<< "airline check num " << a.get_numflights() << endl;
    #endif
    while(true){

      switch(menu()){
        case 1:
          cout<<endl;
          cout << "DISPLAYING SEAT MAP" << endl;
          cout << "- - - - - - - - - - \n" << endl;
          f.print_seatmap();
          PressEnter();
          break;
        case 2: 
          cout<<endl;
          cout << "DISPLAYING PASSENGER INFO" << endl;
          cout << "- - - - - - - - - - - - - \n" << endl;
          displayPassenger(&f);
          PressEnter();
          break;
        case 3:
          cout<<endl;
          cout << "ADDING PASSENGER" << endl;
          cout << "- - - - - - - - -  \n" << endl;
          add_passenger(&f);
          PressEnter();
          break;
        case 4:
          cout<<endl;
          cout << "REMOVING PASSENGER" << endl;
          cout << "- - - - - - - - - - \n" << endl;
          remove_passenger(&f);
          cout << endl;
          PressEnter();
          break;
        case 5:
          cout<<endl;
          cout << "SAVING DATA" << endl;
          cout << "- - - - - - \n" << endl;
          save_data(&f);
          cout << endl;
          PressEnter();
          break;
        case 6:
          cout<<endl;
          cout << "Program Terminating... \nGoodbye! \n";
          exit(1);
      }
    }
}

Flight populate_flight(string path,Airline* a){
  Flight f;
  ifstream file(path);
  if(file.is_open()){
    string line;
    int line_count = 1;
    while (getline(file, line)) {
        istringstream ss(line);
        string word;
        int word_count = 1;
        int words_in_name = 1;
        int spaces_between_words = 0;
        bool is_first = true;
        
        Passenger* p = new Passenger;
        assert(p!=NULL);
        while (ss >> word) {
          if(line_count == 1){
            if(word_count ==  1){
              f.set_flight_number(word);
              //cout << "flight number "<< f.get_flight_number() << endl;
              string airline_name = string(1,word[0])+string(1,word[1]);
              a->set_name(airline_name);
              a->set_numflights(1);

            }
            if(word_count ==  2){
              f.set_max_row(stoi(word));
              //cout << "max rows "<< f.get_max_row() << endl;
              
            }
            if(word_count ==  3){
              f.set_max_col(stoi(word));
              //cout << "max cols "<< f.get_max_col() << "\n"<<endl;
            }
          }else{
            if(word_count == 1){
              p->set_first_name(word);
            }
            if(word_count >=2 && (word[0] > 57 || word[0] < 48)){
              if(spaces_between_words > 1){
                 is_first = false;
              }
              if(is_first){
                p->set_first_name(p->get_first_name()+" "+ word); 
              }else{
                p->set_last_name(p->get_last_name()+" " + word);
              }
              words_in_name++;
            }else{
                if(word_count - words_in_name == 1){
                  p->set_phone_number(word);
                }
                if(word_count - words_in_name == 2){
                  char letter = '\0';
                  string number = "";
                  for(int i = 0; i < word.length(); i++){
                    if(word[i]>57 || word[i] < 48){
                      letter = word[i];
                      break;
                    }else{
                      number = number + word[i];
                    }
                  }
                  Seat* s = new Seat(stoi(number),letter-'A');
                  assert(s!=NULL);
                  s->set_seat_letter(string(1,letter));
                  p->set_seat(s);
                  
                }
                if(word_count - words_in_name == 3){
                  p->set_id(stoi(word));
                }
            }
            char c='\0';
            while (ss.get(c)) {
                if (c == ' ') {
                    ++spaces_between_words;
                } else {
                    ss.unget(); 
                    break;
                }
            }
          }
          word_count++;
        }
        if(line_count>1){
          f.get_passenger_list().insert(*p);
          // cout << "Passenger no. " << line_count -1 << " first name is: " << p->get_first_name()<< endl;
          // cout << "Passenger no. " << line_count -1 << " last name is: "<< p->get_last_name()<< endl;
          // cout << "Passenger no. " << line_count -1 << " phone number is: " << p->get_phone_number()<< endl;
          // cout << "Passenger no. " << line_count -1 << " assigned seat is: "<< p->get_seat()->get_seat_number()<< endl;
          // cout << "Passenger no. " << line_count -1 << "  seat is letter: "<< p->get_seat()->get_seat_letter()<< endl;
          // cout << "Passenger no. " << line_count -1 << " row seat is: "<< p->get_seat()->get_seat_row()<< endl;
          // cout << "Passenger no. " << line_count -1 << " id is: "<< p->get_id()<<"\n"<< endl;
        }
        delete p;
        line_count++;
        
    }
    file.close();
    Node* curr_p = f.get_passenger_list().get_head();
    // int count = 0;
    // while(curr_p!=0){
    //   cout<< "Passenger no: " << count << " row " << curr_p->p.get_seat()->get_seat_row() << endl;
    //   cout<< "Passenger no: " << count << " col " << curr_p->p.get_seat()->get_seat_col() <<"\n"<< endl;
    //   count++;
    //   curr_p = curr_p -> next;
    // }
    
  }else{
    cout << "File failed to open..."<<endl;
  }
  return f;
}
void displayHeader(){
  cout << "Version 1.0\n"
       << "Term Project - Flight Management Program in C++\n"
       << "Produced By: Muhammad A, Omar A & Jubayer A" 
       << "\n" 
       << endl;
  int count  = 0;
  do{
    cout << "<<<< Press Return to Continue >>>>" << endl;
    if(count>0){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    count++;
  }while (cin.get() != '\n');
}
void displayPassenger(Flight* f){
  int spacing = 0;
  cout << "First Name";
  spacing = 10;
  while(spacing>0){
      cout << " ";
      spacing--;
  }
  cout << "Last Name";
  spacing = 11;
  while(spacing>0){
      cout << " ";
      spacing--;
  }
  cout << "Phone Number";
  spacing = 5;
  while(spacing>0){
      cout << " ";
      spacing--;
  }
  cout << "Row";
  spacing = 5;
  while(spacing>0){
      cout << " ";
      spacing--;
  }
  cout << "Seat";
  spacing = 6;
  while(spacing>0){
      cout << " ";
      spacing--;
  }
  cout << "ID"<<endl;
  
  spacing = 80;
  while(spacing>0){
      cout << "-";
      spacing--;
  }
  cout<<endl;
  Node* curr_p = f->get_passenger_list().get_head();
  while (curr_p != 0 ){
    curr_p->p.print_info();
    spacing = 80;
    while(spacing>0){
        cout << "-";
        spacing--;
    }
    cout<<endl;
    curr_p = curr_p->next;
  }
}
void PressEnter(){
  do{
    cout << "<<<< Press Return to Continue >>>>" << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

  }while (cin.get() != '\n');
}
void add_passenger(Flight* f){
  int in_id = 0;
  string in_fname;
  string in_lname;
  string in_pnum;
  int in_srow = 0;
  string in_sletter;
  Passenger* p = new Passenger;
  int rows_free = f->get_max_row();
  for (int i = 0; i < f->get_max_row(); i++){
    if(!f->isRowFree(i)){
      rows_free--;
    }
  }
  if(rows_free==0){
    cout << "The flight is full. No more passengers can be added. ";
  }
  cleanStream();
  cout << "Please enter the passenger's id: ";
  while (!(cin >> in_id)||f->get_passenger_list().search(in_id)) {
    cleanStream();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInvalid input. Input must be\n-An integer\n-Cannot be the id of an existing passenger \n"
    << endl;
    cout << "Please enter the passenger id: ";
  }
  p->set_id(in_id);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Please enter the passenger's first name: ";
  while (!getline(cin,in_fname) || in_fname.length()>19 || in_fname==" " || in_fname == "") {
    cin.clear();
    cout << "\nInvalid input. Input must be\n-A first name under 20 characters\n"
    << endl;
    cout << "Please enter the passenger's first name: ";
  }
  
  p->set_first_name(in_fname+" ");

  cout << "Please enter the passenger's last name: ";
  while (!getline(cin,in_lname) || in_lname.length()>20 || in_lname==" ") {
    cin.clear();
    cout << "\nInvalid input. Input must be\n-A last name under 20 characters\n"
    << endl;
    cout << "Please enter the passenger's last name: ";
  }
  
  p->set_last_name(" " + in_lname);

  cout << "Please enter the passenger phone number: ";
  while (!getline(cin,in_pnum) || (in_pnum[3]!='-' && !(isspace(in_pnum[3]))&&in_pnum[4]!=')' ) || (in_pnum[7]!='-' && !(isspace(in_pnum[7]))) || in_pnum.length()!=12) {
    cin.clear();
    cout << "\nInvalid input. Input must be\n-A phone number with the format 123-456-7890\n-A phone number with this format works as well 123 456 7890\n-Must be 10 digits\n-No letters\n"
    << endl;
    cout << "Please enter the passenger's phone number: ";
  }
  in_pnum[3]='-';
  in_pnum[7]='-';
  p->set_phone_number(in_pnum);

  cout << "Enter the passenger's desired row: ";
  while (!(cin >> in_srow) || in_srow > f->get_max_row() || !f->isRowFree(in_srow)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInvalid input. Input must be\n-An integer\n-A row in flight's seat map\n-Row must have a free seat\n"
    << endl;
    cout << "Enter the passenger's desired row: ";
  }
  Seat* s = new Seat;
  assert(s!=NULL);
  p->set_seat(s);
  p->get_seat()->set_seat_row(in_srow);

  cout << "Enter the passenger's desired seat: ";
  
  
  while (!(cin >> in_sletter) || in_sletter.length()>1 || in_sletter[0]-'A' > f->get_max_col()-1 || in_sletter[0]<65 || in_sletter[0]>90 ||!f->isSeatFree(p->get_seat()->get_seat_row(),in_sletter[0])){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInvalid input. Input must be \n-Capital letter\n-Cannot be more than one letter\n-The letter must be included within the seatmap in flight's seat map\n-Seat must be free\n"
    << endl;
    cout << "Enter the passenger's desired seat: ";
  }
  p->get_seat()->set_seat_letter(string(1,in_sletter[0]));
  p->get_seat()->set_seat_col(in_sletter[0]-'A');
  f->get_passenger_list().insert(*p);
  delete p;
  cout <<"Passenger added to flight succussfully!\n"<<endl;

}
void remove_passenger(Flight* f){
  int in_int = 0;
  cout << "Please enter the id of the passenger you wish to remove: ";
  while (!(cin >> in_int)|| !f->get_passenger_list().search(in_int)) {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInvalid input. Input must be\n-A valid id of a passenger on flight \n"
    << endl;
    cout << "Please enter the id of the passenger you wish to remove: ";
  }
  f->get_passenger_list().remove(*(f->get_passenger_list().search(in_int)));
  cout <<"Passenger removed from flight succussfully!";
}
void save_data(Flight* f){
  string in_str;
  cout<<"Save file as? ";
  while (!(cin >> in_str) || in_str[in_str.length()-4] != '.'|| in_str[in_str.length()-3] != 't'|| in_str[in_str.length()-2] != 'x'|| in_str[in_str.length()-1] != 't') {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nInvalid input. Input must be\n-A valid file name\n-Must end with '.txt' \n"
    << endl;
    cout<<"Save file as? ";
  }
  cout<<"Saving..."<<endl;
  cout<<"Done! '" << in_str << "' saved successfully." <<endl;
  
  f->save(in_str);
}
void cleanStream(){
  int leftover;
  do{
    leftover = cin.get();

  }while(leftover!='\n'&&leftover!=EOF);
}
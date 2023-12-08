//
//  passengerlist.cpp
//  ENSF FINAL PROJECT

#include "passengerlist.h"
PassengerList::PassengerList():headM(0){}
void  PassengerList::set_head(Node* n){
  headM = n;
}
PassengerList::~PassengerList(){
    destroy();
}
PassengerList& PassengerList::operator=(const PassengerList& rhs){
    if(this!=&rhs){
        destroy();
        copy(rhs);
    }
    return *this;
    

}
//looks for passenger based off id
Passenger* PassengerList::search(int id){
    Node* curr_p = headM;
    while(curr_p!=0){
        if(curr_p->p.get_id() == id){
            return &(curr_p->p);
        }
        curr_p = curr_p->next;
    }
    return 0;
}
//inserts passenger ordered off id 
void PassengerList::insert(Passenger& itemP){
    Node* new_pass = new Node;
    new_pass->p = itemP;
    if (headM == 0 || (itemP.get_id() <= (headM->p).get_id())) {
        new_pass->next = headM;
        headM = new_pass;
    }
    else {
        Node *before = headM;      
        Node *after = headM->next; 
        while(after != 0 && (itemP.get_id() > (after->p).get_id())) {
            before = after;
            after = after->next;
        }
        new_pass->next = after;
        before->next = new_pass;
    }
}
//removes passenger from list
void PassengerList::remove(Passenger& itemP){
    if (headM == 0 || (itemP.get_id() < (headM->p).get_id())){
        return;
    }    
    Node *doomed_node = 0;
    if ((itemP.get_id() == (headM->p).get_id())) {
        doomed_node = headM;
        headM = headM->next;
        delete doomed_node;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && (itemP.get_id() > (maybe_doomed->p).get_id())) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        doomed_node = maybe_doomed;
        before->next = doomed_node->next;
        delete doomed_node;
    }
}
//deallocates passenger
void PassengerList::destroy()
{
    Node* curr = headM;
    Node* before;
    while(curr!=0){
        before = curr;
        delete before;
        curr = curr->next;
    }
    headM = 0;
}
//returns head of list
Node* const PassengerList::get_head()const{
  return headM;
}
//copies passengerlist
void PassengerList::copy(const PassengerList& src){
  if(src.headM==0){
      headM = 0;
      return;
  }
  headM = new Node;
  assert(headM!= NULL);
  Node* src_curr = src.headM;
  Node* new_node = headM;
  while(true){
      new_node->p = src_curr->p;
      if(src_curr->next==0){break;}
      Node* newer_node = new Node;
      new_node->next=newer_node;
      new_node=newer_node;
      src_curr=src_curr->next;
  }
}
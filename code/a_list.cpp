#include"a_list.hpp"

a_list::a_list() : head(NULL), tail(NULL) {}

a_list::a_list(fatality_event fe) : head(new a_list_node(fe)), tail(head) {}

void a_list::new_node(fatality_event fe) {
    
    a_list_node* temp = new a_list_node(fe);

    if(head == NULL) {

        head = temp;
        tail = temp;
        temp = NULL;
    }
    else {

        tail->set_next(temp);
        tail = temp;
    }
    
}

void a_list::insert_node_start(fatality_event fe) {
    a_list_node* temp = new a_list_node(fe);

    temp->set_next(head);
    head = temp;
}

void a_list::insert_node_position(int position, fatality_event fe) {
    a_list_node* pre = new a_list_node(fe);
    a_list_node* cur = new a_list_node(fe);
    a_list_node* temp = new a_list_node(fe);

    cur = head;

    for(int i = 1; i < position; i++) {
      pre = cur;
      cur = cur->get_next();
    }

    pre->set_next(temp);	
    temp->set_next(cur);
}

void a_list::delete_first() {
    a_list_node* temp = new a_list_node();

    temp = head;
    head = head->get_next();
    delete temp;
}

void a_list::delete_last() {
    a_list_node *current=new a_list_node;
    a_list_node *previous=new a_list_node;

    current = head;
    while(current->get_next() != NULL) {
      previous = current;
      current = current->get_next();	
    }

    tail = previous;
    previous->set_next(NULL);
    delete current;
}

void a_list::delete_position(int position) {
    a_list_node *current=new a_list_node;
    a_list_node *previous=new a_list_node;


    current = head;
    for(int i = 1; i < position; i++) {
      previous = current;
      current = current->get_next();
    }

    previous->set_next(current->get_next());
}

void a_list::print() {
    a_list_node *temp = new a_list_node;

    temp = head;
    while(temp != NULL) {
      std::cout << temp->get_fatality_id() << "\t";
      temp = temp->get_next();
    }
} 
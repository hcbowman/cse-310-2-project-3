#ifndef A_LIST_HPP
#define A_LIST_HPP

#include<iostream>
#include"a_list_node.hpp"

class a_list {

    private:

    a_list_node* head;
    a_list_node* tail;

    public:

    a_list();
    a_list(fatality_event fe);

    void new_node(fatality_event fe);
    void insert_node_start(fatality_event fe);
    void insert_node_position(int position, fatality_event fe);
    void delete_first();
    void delete_last();
    void delete_position(int position);
    void print();


};


#endif
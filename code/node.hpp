#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include<string>


class node {
        
    private:

    int vertex;
    node* next;

    public:

    node();
    node(int vertex);
    

    int get_vertex();
    void set_vertex(int vertex);
    node* get_next();
    void set_next(node* next);

};

#endif
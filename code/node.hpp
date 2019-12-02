#ifndef NODE_HPP
#define NODE_HPP

#include<iostream>
#include<string>


class node {
        
    private:

    node* root;

    int vertex;
    std::string color;
    int discovery_time;
    int finish_time;
    node* next;

    public:

    node();
    node(int vertex);
    node(int vertex, node* root);
    
    node* get_root();
    void set_root(node* root);
    int get_vertex();
    void set_vertex(int vertex);
    std::string get_color();
    void set_color(std::string color);
    int get_discovery_time();
    void set_discovery_time(int discovery_time);
    void incr_discovery_time();
    int get_finish_time();
    void set_finish_time(int finish_time);
    node* get_next();
    void set_next(node* next);

};

#endif
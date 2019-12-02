#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include<vector>

#include"node.hpp"

class adjacency_list {

    private:

    int number_of_components;
    int components_list[500];

    public:

    node* the_a_list[3186]; //hash table, array of pointers to struc hach_table_entry

    adjacency_list();

    void add_edge(int vertex1, int vertex2);
    void dfs();
    int dfs_visit(node* u);
    void print_histogram(int size);
    void print_components();

};


#endif
#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP

#include<vector>

#include"node.hpp"

class adjacency_list {

    private:

    public:

    node* the_a_list[3186]; //hash table, array of pointers to struc hach_table_entry

    adjacency_list();

    void add_edge(int vertex1, int vertex2);
    void dfs(int vertex);
    void print_histogram(int size);

};


#endif
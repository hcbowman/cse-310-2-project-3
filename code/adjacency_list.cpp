#include"adjacency_list.hpp"


adjacency_list::adjacency_list() {

    //Initialize the ht with nullptrs
    for (unsigned int i = 0; i < 3186; i++) {
        the_a_list[i] = NULL;
    }
}

void adjacency_list::add_edge(int vertex1, int vertex2) {


    if (the_a_list[vertex1] == NULL) {

        the_a_list[vertex1] = new node(vertex2);

    }
    else {

        node* entry = the_a_list[vertex1];

        if (entry->get_next() != NULL) {
            while (entry->get_next() != NULL) {
                entry = entry->get_next();
            }
            entry->set_next(new node(vertex2));
        } else {

            //entry = entry->get_next();
            entry->set_next(new node(vertex2));
        }

    }

}

void adjacency_list::dfs(int vertex) {


}

void adjacency_list::print_histogram(int size) {

    std::vector<int> edge_count(size);
    for (int i = 0; i < size; i++) {
        edge_count.at(i) = 0;
    }

    //Gets the edge counts
    for (int xx = 0; xx < 3186; xx++) {

        int count = 1;

        if (the_a_list[xx] == NULL) {

            edge_count.at(0)++;

        }
        else {

            node* entry = the_a_list[xx];

            while (entry->get_next() != NULL) {
                entry = entry->get_next();
                count++;
            }

            edge_count.at(count)++;

        }
    }

    //Print the histogram
    for (int i = 0; i < size; i++) {

        int total = edge_count.at(i);

        std::cout << "Degree:" << i << " ";
        
        for (int x = 0; x < (total/10) ; x++) {
            std::cout << "O";
        }
        std::cout << " " << total << "\n";

    }

}
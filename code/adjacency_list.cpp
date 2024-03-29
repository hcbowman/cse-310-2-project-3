#include"adjacency_list.hpp"


adjacency_list::adjacency_list() : number_of_components(0) {

    //Initialize the arrays with nullptrs and 0s
    for (unsigned int i = 0; i < 3186; i++) {
        the_a_list[i] = NULL;
        components_list[i] = 0;
    }

}

void adjacency_list::add_edge(int vertex1, int vertex2) {


    if (the_a_list[vertex1] == NULL) {

        the_a_list[vertex1] = new node(vertex2);
        the_a_list[vertex1]->set_root(the_a_list[vertex1]);

    }
    else {

        node* entry = the_a_list[vertex1];
        node* root = the_a_list[vertex1];

        if (entry->get_next() != NULL) {
            while (entry->get_next() != NULL) {
                entry = entry->get_next();
            }
            entry->set_next(new node(vertex2, root));
        } else {

            //entry = entry->get_next();
            entry->set_next(new node(vertex2, root));
        }

    }

}

void adjacency_list::dfs() {

    for (unsigned int i = 0; i < 3186; i++) {
        if (the_a_list[i]->get_color() == "WHITE") {
            int size = dfs_visit(the_a_list[i]);

            components_list[size]++;
            number_of_components++;
        }
    }

}

int adjacency_list::dfs_visit(node* u) {

    int component_size = 0;

    //time++; // increment time count
    //u->incr_discovery_time(); // set discovery time
    u->set_color("GREY");

    node* temp = u;

    while(temp->get_next() != NULL) {
        temp = temp->get_next();

        if (temp->get_color() == "WHITE") {
            component_size += dfs_visit(temp);
        }

    }

    u->set_color("BLACK");
    component_size++;
    //u.f = time// set finish time

    return component_size;


}

void clustering_coefficient() {


    int actual_edges = 0;
    int total_posibbles_edges = 0;

    int val = (2 *)/()

}

void adjacency_list::print_histogram(int size) {

    std::vector<int> edge_count(500);
    for (int i = 0; i < 500; i++) {
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
    for (int i = 0; i < 500; i++) {

        int total = edge_count.at(i);

        if (edge_count.at(i) != 0) {

        std::cout << "Degree:" << i << " ";
        
        for (int x = 0; x < (total/10) ; x++) {
            std::cout << "O";
        }
        std::cout << " " << total << "\n";

        }
        

    }

}

void adjacency_list::print_components() {

    int index = 1;

    std::cout << "number_of_components=" << number_of_components << "\n";

    for (auto& i : components_list) {

        if (i != 0) {

            std::cout << "component size=" << index << " ";
            std::cout << "number that size=" << i << "\n";
        }

        index++;
    }
}
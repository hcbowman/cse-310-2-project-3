#include"node.hpp"


node::node() : vertex(0), next(NULL) {}

node::node(int vertex) : vertex(vertex), next(NULL) {}

int node::get_vertex() {
    return vertex;
}
void node::set_vertex(int vertex) {
    this->vertex = vertex;
}
node* node::get_next() {
    return next;
}
void node::set_next(node* next) {
    this->next = next;
}
#include"node.hpp"


node::node() : vertex(0), color("WHITE"), discovery_time(0), finish_time(0), next(NULL) {}

node::node(int vertex) : vertex(vertex), color("WHITE"), discovery_time(0), finish_time(0), next(NULL) {}

node::node(int vertex, node* root) : root(root), vertex(vertex), color("WHITE"), discovery_time(0), finish_time(0), next(NULL) {}

node* node::get_root() {
    return root;
}
void node::set_root(node* root) {
    this->root = root;
}
int node::get_vertex() {
    return vertex;
}
void node::set_vertex(int vertex) {
    this->vertex = vertex;
}
std::string node::get_color() {
    return color;
}
void node::set_color(std::string color) {
    this->color = color;
}
int node::get_discovery_time() {
    return discovery_time;
}
void node::set_discovery_time(int discovery_time) {
    this->discovery_time = discovery_time;
}
void node::incr_discovery_time() {
    this->discovery_time++;
}
int node::get_finish_time() {
    return finish_time;
}
void node::set_finish_time(int finish_time) {
    this->finish_time = finish_time;
}
node* node::get_next() {
    return next;
}
void node::set_next(node* next) {
    this->next = next;
}
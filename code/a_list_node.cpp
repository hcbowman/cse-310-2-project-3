#include"a_list_node.hpp"


a_list_node::a_list_node() : fe {} {
    this->next = NULL;
}

a_list_node::a_list_node(fatality_event fe) : fe {} {
    this->next = NULL;
}

a_list_node::a_list_node(int fatality_id,
                int event_id,
                std::string fatality_type,
                std::string fatality_date,
                int fatality_age,
                std::string fatality_sex,
                std::string fatality_location) :
                fe{fatality_id,
                 event_id,
                 fatality_type,
                fatality_date,
                 fatality_age,
                 fatality_sex,
                fatality_location} {
    next = NULL;
}

fatality_event a_list_node::get_fe() {
    return fe;
}
void a_list_node::set_fe(fatality_event fe) {
    this->fe = fe;
}
int a_list_node::get_fatality_id() {
    return fe.fatality_id;
}
void a_list_node::set_fatality_id(int fatality_id) {
    this->fe.fatality_id = fatality_id;
}
int a_list_node::get_event_id() {
    return fe.event_id;
}
void a_list_node::set_event_id(int event_id) {
    this->fe.event_id = event_id;
}
std::string a_list_node::get_fatality_type() {
    return fe.fatality_type;
}
void a_list_node::set_fatality_type(std::string fatality_type) {
    this->fe.fatality_type = fatality_type;
}
std::string a_list_node::get_fatality_date() {
    return fe.fatality_date;
}
void a_list_node::set_fatality_date(std::string fatality_date) {
    this->fe.fatality_date = fatality_date;
}
int a_list_node::get_fatality_age() {
    return fe.fatality_age;
}
void a_list_node::set_fatality_age(int fatality_age) {
    this->fe.fatality_age = fatality_age;
}
std::string a_list_node::get_fatality_sex() {
    return fe.fatality_sex;
}
void a_list_node::set_fatality_sex(std::string fatality_sex) {
    this->fe.fatality_sex = fatality_sex;
}
std::string a_list_node::get_fatality_location() {
    return fe.fatality_location;
}
void a_list_node::set_fatality_location(std::string fatality_location) {
    this->fe.fatality_location = fatality_location;
}
a_list_node* a_list_node::get_next() {
    return next;
}
void a_list_node::set_next(a_list_node* next) {
    this->next = next;
}
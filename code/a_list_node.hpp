#ifndef A_LIST_NODE_HPP
#define A_LIST_NODE_HPP


class a_list_node {
        
    private:

    struct node{
        int value;
        int data;
    };
    a_list_node* next;

    public:

    a_list_node();
    a_list_node(fatality_event fe);
    a_list_node(int fatality_id,
            int event_id,
            std::string fatality_type,
            std::string fatality_date,
            int fatality_age,
            std::string fatality_sex,
            std::string fatality_location
    );
    
    fatality_event get_fe();
    void set_fe(fatality_event fe);
    int get_fatality_id();
    void set_fatality_id(int fatality_id);
    int get_event_id();
    void set_event_id(int event_id);
    std::string get_fatality_type();
    void set_fatality_type(std::string fatality_type);
    std::string get_fatality_date();
    void set_fatality_date(std::string fatality_date);
    int get_fatality_age();
    void set_fatality_age(int fatality_age);
    std::string get_fatality_sex();
    void set_fatality_sex(std::string fatality_sex);
    std::string get_fatality_location();
    void set_fatality_location(std::string fatality_location);
    ll_node* get_next();
    void set_next(ll_node* next);

};

#endif
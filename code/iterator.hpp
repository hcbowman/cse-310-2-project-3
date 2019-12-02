#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include"node.hpp"


// Iterator class can be used to 
// sequentially access nodes of linked list 
class iterator { 

    private:

    //const node* m_pCurrentNode;
    node* m_pCurrentNode;

    public:

    iterator();
    iterator(const node* pNode);

    iterator& operator=(node* pNode);
    iterator& operator++(); // Prefix ++ overload
    iterator operator++(int); // Postfix ++ overload
    bool operator!=(const iterator& iterator);
    int operator*();

};

#endif
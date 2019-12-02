#include"iterator.hpp"

// Iterator class can be used to 
// sequentially access nodes of linked list 

iterator::iterator() noexcept : m_pCurrentNode(m_spRoot) { }

iterator::iterator(const node* pNode) noexcept : m_pCurrentNode (pNode) {}

iterator& iterator::operator=(node* pNode) {
    this->m_pCurrentNode = pNode;
    return *this;
}

// Prefix ++ overload
iterator& iterator::operator++() 
{ 
    if (m_pCurrentNode)
        m_pCurrentNode = m_pCurrentNode->get_next();
    return *this;
}

// Postfix ++ overload
iterator iterator::operator++(int) {
    iterator iterator = *this;
    ++*this; 
    return iterator;
}

bool iterator::operator!=(const iterator& iterator) {
    return m_pCurrentNode != iterator.m_pCurrentNode;
}

int iterator::operator*() {
    return m_pCurrentNode->get_vertex();
}
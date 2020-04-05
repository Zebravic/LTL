#include "slist.h"
#include <iostream>

SList::SList()
{

}

SList::SList(const SList &that)
{
    Node *n = that.root;
    while (n)
    {
        push_back(n->data);
        n = n->next;
    }
}

SList::~SList()
{
    clear();
}

void SList::push_back(int val)
{
    Node *n = back();
    if (!n) root = new Node(val);
    else
    {
        n->next = new Node(val);
    }

    m_size++;
}

void SList::push_front(int val)
{
    Node *n = front();
    if (!n) root = new Node(val);
    else
    {
        n = new Node(val);
        n->next = root;
        root = n;
    }

    m_size++;
}

void SList::insert(SList::Node *node, int val)
{
    Node *n = new Node(val);
    n->next = node->next;
    node->next = n;

    m_size++;
}

void SList::travel() const
{
    Node *n = root;
    while (n)
    {
        std::cout << n->data << std::endl;
        n = n->next;
    }

    std::cout << "size=" << size() << std::endl;
}

void SList::clear()
{
    Node *n = root;

    while (n)
    {
        Node *tmp = n->next;
        delete n;
        n = tmp;
    }

    root = nullptr;
    m_size = 0;
}

void SList::remove(SList::Node *node)
{
    if (root == node)
    {
        root = root->next;
    }
    else
    {
        Node *n = root;
        while (n->next != node)
        {
            n = n->next;
        }
        n->next = n->next->next;
        delete node;
    }

    m_size--;
}

SList::Node *SList::front() const
{
    return root;
}

SList::Node *SList::back() const
{
    if (!root) return nullptr;

    Node *n = root;
    while (n && n->next)
    {
        n = n->next;
    }

    return n;
}

bool SList::empty() const
{
    return 0 == m_size;
}

int SList::size() const
{
    return m_size;
}

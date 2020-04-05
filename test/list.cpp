#include "list.h"

List::List()
{

}

List::~List()
{
    clear();
}

void List::push_back(int val)
{
    Node *n = new Node(val);
    if (!root)
    {
        root = n;
    }
    else
    {
        root->next = n;
        n->prev = root;
    }

    m_size++;
}

void List::push_front(int val)
{
    Node *n = new Node(val);
    if (root)
    {
        n->next = root;
        root->prev = n;
    }

    root = n;
    m_size++;
}

List::Node *List::front() const
{
    return root;
}

List::Node *List::back() const
{
    Node *n = root;
    while (n->next)
    {
        n = n->next;
    }

    return n;
}

void List::remove(List::Node *node)
{
    Node *p = node->prev;
    Node *n = node->next;
    if (p)
    {
        p->next = n;
    }
    else
    {
        root = n;
    }

    if (n)
    {
        n->prev = p;
    }

    delete node;
    m_size--;
}

void List::insert(List::Node *node, int val)
{
    Node *n = new Node(val);
    if (node->next)
    {
        node->next->prev = n;
        n->next = node->next;
    }

    node->next = n;
    n->prev = node;

    m_size++;
}

void List::clear()
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

int List::size() const
{
    return m_size;
}

bool List::empty() const
{
    return 0 == m_size;
}

void List::reverse()
{

}

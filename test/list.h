#ifndef LIST_H
#define LIST_H


class List
{
public:
    struct Node {
        Node() {}
        Node(int val) : data(val) {}

        int     data = 0;
        Node    *next = 0;
        Node    *prev = 0;
    };

    List();
    ~List();

public:
    void push_back(int val);
    void push_front(int val);
    Node *front() const;
    Node *back() const;
    void remove(Node *node);
    void insert(Node *node, int val);
    void clear();
    int size() const;
    bool empty() const;
    void reverse();
    void travel() const;
    void reverse_travel() const;

private:
    Node    *root = 0;
    int     m_size = 0;
};

#endif // LIST_H

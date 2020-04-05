#ifndef SLIST_H
#define SLIST_H


class SList
{
public:
    struct Node {
        Node(int val) : data(val) {}
        Node() {}

        int     data = 0;
        Node    *next = nullptr;
    };

    SList();
    SList(const SList &that);
    ~SList();

public:
    void push_back(int val);
    void push_front(int val);
    void insert(Node *node, int val);
    void travel() const;
    void clear();
    void remove(Node *node);
    Node *front() const;
    Node *back() const;
    bool empty() const;
    int size() const;

private:
    Node    *root = nullptr;
    int      m_size = 0;
};

#endif // SLIST_H

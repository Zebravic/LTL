#include <QCoreApplication>
#include "slist.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SList l;
    l.push_back(2);
    l.push_back(4);
    l.push_back(5);
    l.push_back(1);
    l.travel();

    SList s(l);
    s.travel();

    return a.exec();
}

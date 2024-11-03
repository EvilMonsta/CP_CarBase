#ifndef MARK_H
#define MARK_H
#include<string>

using namespace std;

class Mark {
public:

    int id;

    string name;

    Mark() : id(0), name("def") {}

    Mark(int id, const string& name) : id(id),name(name) {}

    ~Mark() {};

};
#endif // MARK_H

#ifndef MARK_H
#define MARK_H
#include<string>
using namespace std;



class Mark {
private:
    int id;

    string name;

public:
    Mark() : id(0), name("def") {}

    Mark(int id, const string& name) : id(id),name(name) {}

    ~Mark() {};

    int getId() const;

    string getName() const;

};
#endif // MARK_H

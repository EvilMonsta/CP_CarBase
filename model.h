#ifndef MODEL_H
#define MODEL_H
#include<string>

using namespace std;

class Model {
public:

    int id;

    string name;

    Model() : id(0), name("def") {};

    Model(int id, const string& name) : id(id),name(name) {};

    ~Model() {};

};
#endif // MODEL_H

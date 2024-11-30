#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include<file_manager.h>
#include<vector>
#include<model.h>
#include<mark_container_manager.h>
#include "duplicate_model_exception.h"
#include<model_container_manager.h>

class ModelManager: public QObject {
    Q_OBJECT
public:

    explicit ModelManager(QObject *parent = nullptr);

    ~ModelManager() {};

    void saveModel(const Model& model);

    Model loadModel(int id);

    vector<Model> getModels(vector<int> modIds);

    vector<int> readIds();

    string getFolderPath() const;

    Model addModel(const string& newModelName, int markId);

private:
    FileManager fileManager;

    string createFilepath(int id);

    const string folderPath = "C:/course/CourseProject/resources/models";

    MarkContainerManager markContainerManager;

    string createData(const Model& model);

    Model convertData(const string& data);

    bool isModelNameUnique(const string& name, int markId);

};

#endif // MODEL_MANAGER_H


#ifndef MARK_MANAGER_H
#define MARK_MANAGER_H
#include<file_manager.h>
#include<vector>
#include<mark.h>
#include<mark_container_manager.h>
#include "duplicate_mark_exception.h"

class MarkManager : public QObject {

    Q_OBJECT

private:
    FileManager fileManager;

    string createFilepath(int id);

    const string folderPath = "C:/course/CourseProject/resources/marks";

    MarkContainerManager markContainerManager;

    string createData(const Mark& mark);

    Mark convertData(const string& data);

    bool isMarkNameUnique(const string& name);

public:

    explicit MarkManager(QObject *parent = nullptr);

    ~MarkManager() {};

    void saveMark(const Mark& mark);

    Mark loadMark(int id);

    vector<Mark> getMarks();

    vector<int> readIds();

    string getFolderPath() const;

    Mark addMark(const string& newMarkName);
};

#endif // MARK_MANAGER_H

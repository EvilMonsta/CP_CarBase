#ifndef MARK_MANAGER_H
#define MARK_MANAGER_H
#include<file_manager.h>
#include<vector>
#include<mark.h>
#include<mark_container_manager.h>

class MarkManager : public QObject {

    Q_OBJECT

private:
    FileManager fileManager;

    string createFilepath(int id);

    const string folderPath = "C:/course/CourseProject/resources/marks";

    MarkContainerManager markContainerManager;

    string createData(const Mark& mark);

    Mark convertData(const string& data);

    vector<int> extractIds(const string& input);


public:

    explicit MarkManager(QObject *parent = nullptr);

    ~MarkManager() {};

    void saveMark(const Mark& mark);

    Mark loadMark(int id);

    vector<Mark> getMarks();

    vector<int> readIds(const string& folderPath);

    string getFolderPath() const;
};

#endif // MARK_MANAGER_H

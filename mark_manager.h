#ifndef MARK_MANAGER_H
#define MARK_MANAGER_H
#include<file_manager.h>
#include<vector>
#include<mark.h>
class MarkManager : public QObject {

    Q_OBJECT

private:
    FileManager fileManager;

    string createFilepath(int id);

    string folderPath = "C:/course/CourseProject/resources/marks";

    bool markExists(int id) const;

    void saveMarkToFile(Mark mark) const;

public:

    explicit MarkManager(QObject *parent = nullptr);

    ~MarkManager() {};

    Mark loadMarkFromFile(int id);

    vector<Mark> getMarks() const;

};

#endif // MARK_MANAGER_H

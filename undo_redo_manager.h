#ifndef UNDO_REDO_MANAGER_H
#define UNDO_REDO_MANAGER_H

#include <string>
#include <deque>
#include <filesystem>
using namespace std;
class UndoRedoManager {
public:
    UndoRedoManager(const string& resourcesPath, size_t maxSnapshots = 5);
    ~UndoRedoManager();

    void createSnapshot();
    void undo();
    void redo();

    size_t getUndoStackSize() const;
    size_t getRedoStackSize() const;

private:
    string resourcesPath;
    size_t maxSnapshots;
    deque<string> undoStack;
    deque<string> redoStack;

    string generateSnapshotPath() const;
    void clearRedoStack();
    void copyDirectory(const string& source, const string& destination);
    void restoreSnapshot(const string& snapshotPath);
};

#endif // UNDO_REDO_MANAGER_H

#include "undo_redo_manager.h"

#include <iostream>
#include <stdexcept>
#include <ctime>

namespace fs = filesystem;

UndoRedoManager::UndoRedoManager(const string& resourcesPath, size_t maxSnapshots)
    : resourcesPath(resourcesPath), maxSnapshots(maxSnapshots) {
    if (!fs::exists(resourcesPath) || !fs::is_directory(resourcesPath)) {
        throw invalid_argument("Invalid resources path: " + resourcesPath);
    }
    createSnapshot();
}

UndoRedoManager::~UndoRedoManager() {
    try {
        if (fs::exists("C:/course/CourseProject/snapshots")) {
            fs::remove_all("C:/course/CourseProject/snapshots");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error clearing snapshots: " << e.what() << std::endl;
    }
}

void UndoRedoManager::createSnapshot() {
    string snapshotPath = generateSnapshotPath();

    copyDirectory(resourcesPath, snapshotPath);

    undoStack.push_back(snapshotPath);

    clearRedoStack();

    if (undoStack.size() > maxSnapshots) {
        fs::remove_all(undoStack.front());
        undoStack.pop_front();
    }
}

void UndoRedoManager::undo() {
    if (undoStack.size() <= 1) {
        throw runtime_error("No more actions to undo.");
    }

    redoStack.push_back(undoStack.back());
    undoStack.pop_back();

    restoreSnapshot(undoStack.back());
}

void UndoRedoManager::redo() {
    if (redoStack.empty()) {
        throw runtime_error("No more actions to redo.");
    }

    undoStack.push_back(redoStack.back());
    redoStack.pop_back();

    restoreSnapshot(undoStack.back());
}

size_t UndoRedoManager::getUndoStackSize() const {
    return undoStack.size();
}

size_t UndoRedoManager::getRedoStackSize() const {
    return redoStack.size();
}

string UndoRedoManager::generateSnapshotPath() const {
    return "C:/course/CourseProject/snapshots/snapshot_" + to_string(time(nullptr));
}

void UndoRedoManager::clearRedoStack() {
    for (const auto& snapshot : redoStack) {
        fs::remove_all(snapshot);
    }
    redoStack.clear();
}

void UndoRedoManager::copyDirectory(const string& source, const string& destination) {
    fs::path srcPath = fs::u8path(source);
    fs::path destPath = fs::u8path(destination);

    if (!fs::exists(destPath)) {
        fs::create_directories(destPath);
    }

    for (const auto& entry : fs::recursive_directory_iterator(srcPath)) {
        const auto& sourcePath = entry.path();
        auto relativePath = fs::relative(sourcePath, srcPath);
        auto destPathCurrent = destPath / relativePath;

        if (fs::is_directory(sourcePath)) {
            fs::create_directories(destPathCurrent);
        } else if (fs::is_regular_file(sourcePath)) {
            fs::copy_file(sourcePath, destPathCurrent, fs::copy_options::overwrite_existing);
        }
    }
}

void UndoRedoManager::restoreSnapshot(const string& snapshotPath) {
    if (!fs::exists(snapshotPath) || !fs::is_directory(snapshotPath)) {
        throw runtime_error("Snapshot does not exist: " + snapshotPath);
    }

    fs::remove_all(resourcesPath);

    copyDirectory(snapshotPath, resourcesPath);
}

// #include <iostream>
// #include <fstream>
// #include <sstream>
// #include <functional>
// using namespace std;

// template <typename T>
// void FileManager::saveToFile(const T& obj, const string& filepath, function<string(const T&)> createData) {
//     ofstream file(filepath);
//     if (!file.is_open()) {
//         cout << "error" << endl;
//         return;
//     }

//     string data = createData(obj);
//     file << data;
//     file.close();

//     cout << "Successfull wrote to file: " << filepath << endl;
// }


// template <typename T>
// T FileManager::loadFromFile(const string& filepath, function<T(const string&)> convertData) {
//     ifstream file(filepath);
//     if (!file.is_open()) {
//         cout << "Unable to open: " << filepath << endl;
//         return "";
//     }

//     string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
//     file.close();

//     cout << "successful" << endl;
//     return convertData(data);
// }

#pragma once
#include <fstream>
#include <iostream>
#include <string>

class FileManager {
public:
    void save(const std::string& path, const std::string& data);
    std::string load(const std::string& path);
};
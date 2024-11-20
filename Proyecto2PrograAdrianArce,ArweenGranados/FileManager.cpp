#include "FileManager.h"

void FileManager::save(const std::string& path, const std::string& data) {
    try {
        std::ofstream outFile(path);
        if (!outFile.is_open()) {
            throw std::runtime_error("Error: No se pudo abrir el archivo para guardar.");
        }
        outFile << data;
        outFile.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Excepción en save: " << e.what() << '\n';
    }
}

std::string FileManager::load(const std::string& path) {
    std::string data;
    try {
        std::ifstream inFile(path);
        if (!inFile.is_open()) {
            throw std::runtime_error("Error: No se pudo abrir el archivo para cargar.");
        }
        std::string line;
        while (std::getline(inFile, line)) {
            data += line + '\n';
        }
        inFile.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Excepción en load: " << e.what() << '\n';
    }
    return data;
}
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "DoublyLinkedList.h"
#include "Rout.h"

class RouteFileManager {
public:
    static void saveToFile(const DoublyLinkedList<Rout>& routes, const std::string& filePath);
    static void loadFromFile(DoublyLinkedList<Rout>& routes, const std::string& filePath);
};
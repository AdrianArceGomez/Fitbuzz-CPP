#include "RoutFManager.h"

void RouteFileManager::saveToFile(const DoublyLinkedList<Rout>& routes, const std::string& filePath) {
    std::ofstream outFile(filePath);
    if (!outFile) {
        throw std::runtime_error("Error al abrir el archivo para guardar.");
    }

    for (int i = 0; i < routes.getSize(); i++) {
        outFile << routes.at(i)->toCSV();
    }


    outFile.close();
}

void RouteFileManager::loadFromFile(DoublyLinkedList<Rout>& routes, const std::string& filePath) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        return;
    }

    std::string line;
    std::string routeName;
    Rout currentRoute;
    bool inRoute = false;

    while (std::getline(inFile, line)) {
        size_t openBracePos = line.find('{');
        if (openBracePos != std::string::npos) {

            routeName = line.substr(0, openBracePos);
            currentRoute = Rout(routeName);
            inRoute = true;
            continue;
        }

        size_t closeBracePos = line.find('}');
        if (closeBracePos != std::string::npos && inRoute) {
            routes.pushBack(currentRoute);
            inRoute = false;
            continue;
        }

        if (inRoute) {
            std::string pointName = line.substr(0, line.find(","));
            std::string pointDetails = line.substr(line.find(",") + 1);

            TouristPoint point = TouristPoint::stringToTouristPoint(pointName, pointDetails);
            currentRoute.addPoint(point);
        }
    }

    if (inRoute) {
        routes.pushBack(currentRoute);
    }

    inFile.close();
}
#pragma once
#include "DoublyLinkedList.h"
#include "Rout.h"
#include "PointTurist.h"

class RouteManager {
public:
    RouteManager(DoublyLinkedList<Rout>& routes);

    void addPointToRoute(int routeIndex, const TouristPoint& point);

private:
    DoublyLinkedList<Rout>& routes;
};
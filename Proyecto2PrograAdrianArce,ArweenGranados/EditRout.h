#pragma once
#include <iostream>
#include "ButtonStrategy.h"
#include "DoublyLinkedList.h"
#include "PointTurist.h"
#include "Rout.h"
#include "TextInputWindow.h"


class EditRouteStrategy : public ButtonStrategy {
private:
    DoublyLinkedList<Rout>& routes;
    int& routeIndex;

public:
    EditRouteStrategy(DoublyLinkedList<Rout>& routes, int& routeIndex);
    void execute() override;
};
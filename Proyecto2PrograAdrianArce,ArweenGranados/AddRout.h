#pragma once
#include "ButtonStrategy.h"
#include "DoublyLinkedList.h"
#include "PointTurist.h"
#include "Rout.h"
#include <iostream>
#include "TextInputWindow.h"

class AddRouteStrategy : public ButtonStrategy {
private:
    DoublyLinkedList<Rout>& routes;

public:
    AddRouteStrategy(DoublyLinkedList<Rout>& routes);
    void execute() override;
};
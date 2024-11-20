#pragma once
#include "ButtonStrategy.h"
#include "DoublyLinkedList.h"
#include "PointTurist.h"
#include <iostream>
#include "Rout.h"

class DeleteRouteStrategy : public ButtonStrategy {
private:
	DoublyLinkedList<Rout>& routes;
	int& routeIndex;

public:
	DeleteRouteStrategy(DoublyLinkedList<Rout>& routes, int& routeIndex);
	void execute() override;
};
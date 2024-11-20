#pragma once
#include "DoublyLinkedList.h"
#include "RoutManager.h"
#include "Button.h"
#include "Rout.h"
#include <iostream>
#include "TextInputWindow.h"
#include "Colors.h"
#include "MouseP.h"

using namespace std;
using namespace sf;

class DisplayList
{
private:
	Vector2f positionList;
	DoublyLinkedList<Button> buttons;
	DoublyLinkedList<Rout>& routes;

	int currentRout;

	RectangleShape listBox;

public:
	DisplayList(DoublyLinkedList<Rout>& routes, Vector2f positionList, Vector2f size);
	int handleClick(const Vector2i& mousePos, RenderWindow& window);
	void updateButtons();
	void addPointToCurrentRoute(RenderWindow& window, Event& event);
	void deletePointCurrentRoute(RenderWindow& window, Event& event);
	void drawList(RenderWindow& window);
	void drawPoints(RenderWindow& window);
	Vector2f getPosition();
	int& getCurrentRouteIndex();
	DisplayList() = default;
};
#pragma once
#include <SFML/Graphics.hpp>
#include "DoublyLinkedList.h"
#include "Button.h"
#include "Rout.h"
#include "DisplayList.h"

enum class MenuState {
    Hidden,
    MainMenuVisible,
    RouteMenuVisible
};

class SideBarMenu {
private:
    sf::RectangleShape sideBarMenu;
    sf::Clock clock;
    MenuState menuState = MenuState::Hidden;
    float displacementSpeed = 400.0f;

    Button buttonRoutes;
    Button helpButton;
    Button exitButton;
    Button addRouteButton;
    Button editRouteButton;
    Button deleteRouteButton;

    DoublyLinkedList<Rout>& routes;
    DisplayList routeList;

    ButtonStrategy* showRoutesStrategy = nullptr;
    ButtonStrategy* helpStrategy = nullptr;
    ButtonStrategy* exitStrategy = nullptr;

    ButtonStrategy* editRouteStrategy = nullptr;
    ButtonStrategy* addRouteStrategy = nullptr;
    ButtonStrategy* deleteRouteStrategy = nullptr;

    void updateButtonPositions();
    void updateMainMenuButtonPositions(float offsetX);
    void updateRouteMenuButtonPositions(float offsetX);

public:
    SideBarMenu(sf::Vector2f size, sf::Vector2f position, DoublyLinkedList<Rout>& routes);
    void setStrategies(ButtonStrategy* add, ButtonStrategy* edit, ButtonStrategy* del, ButtonStrategy* help, ButtonStrategy* exit, ButtonStrategy* showRoutes);
    void toggleSideBar();
    void toggleRouteMenu();
    void moveSideBarMenu();
    bool isEdgeClicked(const sf::Vector2i& mousePos);
    bool handleButtonClick(const sf::Vector2i& mousePos, sf::RenderWindow& window);
    bool handleRouteMenuClick(const sf::Vector2i& mousePos, sf::RenderWindow& window);
    void updateHover(sf::RenderWindow& window);
    void handleMenuEvents(const sf::Vector2i& mousePos, sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderWindow& window);
    DisplayList& getRouteDisplay();
};
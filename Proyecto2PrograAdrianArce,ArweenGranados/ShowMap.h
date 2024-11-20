#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class MapViewer {
public:
    MapViewer(sf::RenderWindow& window, const std::string& filepath);

    void handleZoomEvent(const sf::Event& event);

    void drawMap();

private:
    sf::RenderWindow& window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::View mapView;
    float zoomLevel;
    const float minZoomLevel;
    const float maxZoomLevel;

    void applyZoom();
};
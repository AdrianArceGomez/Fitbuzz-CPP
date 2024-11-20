#include "ShowMap.h"

MapViewer::MapViewer(sf::RenderWindow& window, const std::string& filepath)
	: window(window), zoomLevel(1.0f), minZoomLevel(0.5f), maxZoomLevel(2.0f)
{
	if (!mapTexture.loadFromFile(filepath)) {
		throw std::runtime_error("Error: No se pudo cargar la textura del mapa.");
	}

	mapSprite.setTexture(mapTexture);

	mapView = window.getDefaultView();
	mapView.setCenter(mapSprite.getGlobalBounds().width / 2, mapSprite.getGlobalBounds().height / 2);
}

void MapViewer::handleZoomEvent(const sf::Event& event) {
	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.delta > 0 && zoomLevel > minZoomLevel) {
			zoomLevel *= 0.9f;
		}
		else if (event.mouseWheelScroll.delta < 0 && zoomLevel < 0.9f) {
			zoomLevel *= 1.1f;
		}
		applyZoom();
	}
}

void MapViewer::drawMap() {

	sf::View originalView = window.getView();

	window.setView(mapView);
	window.draw(mapSprite);

	window.setView(originalView);
}

void MapViewer::applyZoom() {
	mapView.setSize(window.getDefaultView().getSize());
	mapView.zoom(zoomLevel);
}
#include "ShowRous.h"


ShowRoutesStrategy::ShowRoutesStrategy(SideBarMenu& sideBarMenu) : sideBarMenu(sideBarMenu) {}

void ShowRoutesStrategy::execute() {
    sideBarMenu.toggleRouteMenu();
}
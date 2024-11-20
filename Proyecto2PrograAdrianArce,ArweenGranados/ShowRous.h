#pragma once
#include "ButtonStrategy.h"
#include "SideBarr.h"

class ShowRoutesStrategy : public ButtonStrategy {
private:
    SideBarMenu& sideBarMenu;

public:
    ShowRoutesStrategy(SideBarMenu& sideBarMenu);
    void execute() override;
};
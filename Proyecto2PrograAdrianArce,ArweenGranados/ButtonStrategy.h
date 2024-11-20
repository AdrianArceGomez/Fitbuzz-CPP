#pragma once
class ButtonStrategy
{
public:
    virtual void execute() = 0;
    virtual ~ButtonStrategy() = default;
};
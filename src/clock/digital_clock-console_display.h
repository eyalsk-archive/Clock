#pragma once
#include "clock_display.h"
#include "console.h"

class DigitalClockConsoleDisplay final : public ClockDisplay {
public:
    explicit DigitalClockConsoleDisplay(Console&);
    void Draw(Hour, Minute, Second) const override;
private:
    Console& _console;
};

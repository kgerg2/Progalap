#pragma once

class Dispenser {
private:
    int screen;

public:
    Dispenser() : screen(0) {}
    void fill(int liter) { screen += liter; }
    int getScreenContent() { return screen; }
    int setScreenContent(int liters = 0) { screen = liters; }
};
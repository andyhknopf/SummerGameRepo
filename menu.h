#pragma once
#include "raylib.h"

void menuStateInit(void);

void menuStateUpdate(void);

void runMenuState(char mode);

int menuButtonIsClicked(Rectangle button);

// Main Menu buttons
struct Rectangle playButton;


# Snake Game

This is a simple Snake game implemented in C++ using basic data structures and algorithms concepts.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Requirements](#requirements)
- [How to Play](#how-to-play)
- [Controls](#controls)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## Introduction
This project is a classic Snake game where the player controls a snake that moves around the board to eat food (represented by 'X'). As the snake eats food, it grows longer. The game ends if the snake runs into the walls or itself.

## Features
- Simple and intuitive gameplay
- Randomized placement of food after each consumption
- Score tracking

## Requirements
- C++ compiler
- Windows OS (for using `conio.h` and `windows.h` libraries)

## How to Play
1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/snake-game.git
    ```
2. Compile the code:
    ```bash
    g++ snake.cpp -o snake
    ```
3. Run the executable:
    ```bash
    ./snake
    ```
4. Use the arrow keys to control the snake's direction.
5. Eat the food ('X') to score points and grow the snake.
6. Avoid running into the walls or the snake itself.

## Controls
- UP arrow key: Move up
- DOWN arrow key: Move down
- LEFT arrow key: Move left
- RIGHT arrow key: Move right

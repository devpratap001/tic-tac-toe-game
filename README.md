# Tic Tac Toe
A CLI based board game player against computer in two modes(easy, difficult).

## Installation

```bash
git clone git@github.com:devpratap001/tic-tac-toe-game.git
cd tic-tac-toe-game
make all //build project
make clean //delete the build files
```
## Usage

```bash
./build/index
```

## Features

- Normal mode
- Difficult mode

## Documentation

### H2 utils.c

Contains functions to clear stdin buffer and clearing console screen, for better UI.

### H2 gameplay.c

Contains logic for playing game. It takes choices as input and handles all UI and gameplay logic.
<pre><code>``` 
//choices 1. normal mode; 2. hard mode; 3. exit;
```</code></pre>

### H2 game_logic.c

It contains helper functions for smooth gameplay. Handles, winning conditions, print board, modify values, etc.
<pre>``` 
int analyse_borad(void) // check for win, draw or lose
``` </pre>

### H2 computer_logic.c

it handles all the computer logic for normal and hard modes. It takes choices as input and respectively handles the computer logic.

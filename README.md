# so_long

so_long is a 42 project where I created a simple 2D game using the **MiniLibX** library.  
The player navigates a map, collects all items, and reaches the exit to win.  
This project helped me improve my skills in graphics programming, event handling, and implementing game logic in C.

---

## 🛠️ Features

- Simple 2D top-down game  
- Player movement using keyboard input  
- Collectibles and exit logic  
- Map validation (walls, collectibles, player, exit)  
- Game window rendering with **MiniLibX**  

---

## ⚡ Usage

Clone the repository and compile:

```bash
git clone https://github.com/mhmdam14/so_long.git
cd so_long
make
./so_long maps/map.ber

## 🎮 Game Tutorial

Use the keyboard to move the player:

W → Move up

A → Move left

S → Move down

D → Move right

Collect all collectibles (C) on the map.

Once all collectibles are collected, move to the exit (E) to win.

Avoid invalid moves (walls 1) — you cannot pass through them.

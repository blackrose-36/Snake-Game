<h1 align="center">🐍 Console Snake</h1>

<p align="center">
  <b>The classic Snake game, written in pure C — runs right inside your Windows terminal.</b><br>
  No libraries to install. No engine. Just one file, a compiler, and your reflexes.
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/language-C-blue.svg">
  <img alt="Platform" src="https://img.shields.io/badge/platform-Windows-0078D6.svg">
  <img alt="Dependencies" src="https://img.shields.io/badge/dependencies-none-brightgreen.svg">
  <img alt="PRs welcome" src="https://img.shields.io/badge/PRs-welcome-ff69b4.svg">
</p>

<p align="center">
  <!-- Replace with your own screenshot or GIF: -->
  <!-- <img src="assets/demo.gif" width="600" alt="Snake gameplay demo"> -->
</p>

---

## 🎮 What is this?

A small, fast, flicker-free **terminal Snake game** built in C using the Windows Console API.
Eat the food, grow longer, rack up points — but don't bite your own tail!

Perfect if you want to:

- 🕹️ Kill five minutes with a nostalgic classic
- 📚 Learn how a real-time game loop works in C
- 🔧 Fork it and build your own features on top

---

## ✨ Features

| Feature | Details |
|---|---|
| **Smooth rendering** | Moves the cursor to `(0,0)` instead of calling `system("cls")` every frame, so there is no flicker |
| **Hidden cursor** | The blinking console cursor is turned off for a clean look |
| **Wrap-around world** | Leave one edge of the board and come out the opposite side |
| **Smart food spawning** | Food never appears on top of the snake |
| **No instant U-turns** | You can't reverse straight into your own body |
| **Live score** | +10 points for every piece of food |
| **Zero dependencies** | Only the C standard library and `windows.h` |

---

## 🕹️ Controls

| Key | Action |
|:---:|---|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Q` | Quit the game |

Both uppercase and lowercase keys work.

---

## 🚀 Quick Start

### Requirements

- Windows
- A C compiler such as [MinGW-w64 (GCC)](https://www.mingw-w64.org/) or MSVC

### Build and run

**With GCC (MinGW):**

```bash
gcc snake.c -o snake.exe
snake.exe
```

**With MSVC (Developer Command Prompt):**

```bash
cl snake.c
snake.exe
```

> 💡 Tip: run it in **Command Prompt** or **Windows Terminal** for the best experience.

---

## 🧠 How it works

The game runs on a classic loop:

```
draw → read input → move snake → check collision → check food → sleep
```

- **Snake body:** two arrays (`snakeX[]`, `snakeY[]`) store every segment. Each tick, every segment copies the position of the one in front of it, then the head moves.
- **Rendering:** the board is redrawn each frame with `printf`, and `SetConsoleCursorPosition` pulls the cursor back to the top-left so the screen updates in place.
- **Input:** `_kbhit()` checks for a key press without blocking, and `_getch()` reads it, so the game never stops to wait for you.
- **Timing:** `Sleep(120)` sets the speed (about 8 moves per second).

---

## ⚙️ Customize it

Open `snake.c` and tweak the settings at the top:

```c
#define WIDTH 30       // board width
#define HEIGHT 15      // board height
#define MAX_SNAKE 100  // maximum snake length
```

To change the difficulty, edit the delay in `main()`:

```c
Sleep(120);   // lower = faster, higher = slower
```

---

## 🗺️ Roadmap / Ideas

Want to contribute? Here are some fun ideas:

- [ ] High score saved to a file
- [ ] Speed that increases as you score
- [ ] Start menu and difficulty levels
- [ ] Solid walls mode (hit the wall = game over)
- [ ] Colored output using console text attributes
- [ ] Pause key (`P`)
- [ ] Linux / macOS support (using `ncurses`)

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a branch: `git checkout -b feature/cool-feature`
3. Commit your changes: `git commit -m "Add cool feature"`
4. Push: `git push origin feature/cool-feature`
5. Open a Pull Request

---

## 📄 License

Released under the [MIT License](LICENSE). Free to use, modify, and share.

---

<p align="center">
  <b>Enjoyed it? Drop a ⭐ on the repo — it really helps!</b><br>
  Made with ❤️ and C.
</p>

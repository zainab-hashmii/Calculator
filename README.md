# 🧮 Raylib GUI Calculator

A simple and visually appealing calculator built using **C++** and the **Raylib graphics library**. It supports basic arithmetic operations and demonstrates GUI design fundamentals using rectangles, text rendering, and interactive buttons.

---

## 🚀 Features

- Graphical interface using Raylib
- Clickable buttons for digits and operations
- Basic arithmetic: `+`, `-`, `*`, `/`
- Clear (`C`) and Equals (`=`) functionality
- Responsive UI layout with color-coded operators

---

## 🛠 Build & Run Instructions

### ✅ Prerequisites
- A C++ compiler (like `g++`)
- Raylib installed on your system

### 🔧 Compile with g++ (Windows example):
```bash
g++ Calculator/main.cpp -o calculator -IC:/raylib/include -LC:/raylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm

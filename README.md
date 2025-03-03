# **VectorEngine**

_A Modular and Cross-Platform Game Engine in C++_

## **Overview**

VectorEngine is a fully modular, cross-platform game engine built from scratch in C++. Designed for flexibility and efficiency, the engine provides optimized memory management, custom logging, event handling, input mapping, a math library, and an OpenGL-based rendering system.

This project is part of the **ANI-PJ 4098: Génie logiciel et Gameplay** course, where the objective is to develop a complete and structured game engine. The final application will include a **3D racing game prototype** with vehicle controls, shooting mechanics, obstacle management, bonuses, and scoring.

## **Features**

- **Cross-platform architecture** (Windows, Linux, macOS)
- **Custom memory management**
- **Logging system**
- **Window creation and input handling**
- **Math library** (vector operations, transformations, matrices)
- **Rendering system** (OpenGL integration, camera system)
- **Entity Component System (ECS)**
- **Scene management**
- **Physics & Animation systems**
- **Scripting support** (Lua, Python)

## **Project Structure**

```
VectorEngine/
│── External/
│   ├── Bin/ (Premake5)
│   ├── Libs/
│   │   ├── imgui/
│   │   ├── SDL2-2.30.12/
│── Scripts/
│   ├── lua/
│   │   ├── config.lua
│   ├── python/
│       ├── command/
│       │   ├── build.py
│       │   ├── gen.py
│       │   ├── help.py
│       │   ├── run.py
│       ├── ve.py
│── VectorEngine/
│   ├── src/
│   │   ├── VectorEngine/
│   │   ├── VectorEngine.cpp
│   ├── premake5.lua
│── VEditor/
│   ├── resources/
│   ├── src/
│       ├── VEditor/
│       ├── VEditor.cpp
│   ├── premake5.lua
│── .gitignore
│── LICENSE
│── premake5.lua
│── README.md
│── ve.bat
│── ve.sh
```

## **Installation & Setup**

### **1. Clone the Repository**

```sh
git clone https://github.com/jordankamto/VectorEngine.git
cd VectorEngine
```

### **2. Install Dependencies**

Ensure you have the required dependencies:

- **C++17 or later**
- **OpenGL**
- **SDL2**
- **ImGui**
- **Premake5**

### **3. Build the Project**

#### **Windows**

```sh
ve.bat
```

#### **Linux/macOS**

```sh
chmod +x ve.sh
./ve.sh
```

### **4. Run the Engine**

```sh
./VectorEngine
```

## **Development Guidelines**

- **Modularity:** Each module (rendering, ECS, physics) should be loosely coupled and independent.
- **Efficiency:** Optimize memory usage and processing speed.
- **Cross-platform compatibility:** Ensure the codebase works on multiple OS.
- **Scalability:** The engine should be able to handle future extensions and improvements.

## **License**

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## **Contributors**

- **Jordan Kamto** - Lead Developer

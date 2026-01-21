# Kuchiki Engine  
current status: refactoring old code  

## installation
requires OpenGL installed:
```bash
# ubuntu, installing OpenGL driver implementation
sudo apt install libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
```
```bash
git clone https://github.com/Asahina118/Kuchiki-Engine.git
```
```bash
cmake -S . -B out/build -G "Ninja"
cmake --build out/build
```

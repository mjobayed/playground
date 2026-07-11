# Simple window

It just displays a simple window with raylib. It's easier than `SDL`

# Requirements

On fedora run:

```bash
sudo dnf install -y gcc cmake raylib-devel
```

# Build & run

```bash
cmake -S . -B build
cmake --build build
./build/simple_window
```

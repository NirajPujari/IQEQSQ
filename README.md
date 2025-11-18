# 🧠 IQ-EQ-SQ Console Test Suite

A fully modular C-based console application that calculates IQ, EQ, and SQ scores using structured questionnaires and scoring logic. Designed to be portable, safe, and easy to extend, the project uses a clean folder structure and a cross-platform build system.

## ✨Features

- Modular architecture — IQ, EQ, SQ each in separate modules
- Safe input handling — no gets, no unsafe buffers
- Cross-platform screen clear + input utilities
- Clean folder structure with header separation
- Makefile-based build system
- Works on Windows (MSYS2), Linux, macOS
- Readable question banks stored in clean C arrays
- Scores IQ, EQ, SQ independently


## 📁Folder Structure

```
IQEQSQ/
├── Makefile
├── README.md
├── include/
│   ├── iq.h
│   ├── eq.h
│   ├── sq.h
│   └── utils.h
└── src/
    ├── main.c
    ├── iq.c
    ├── eq.c
    ├── sq.c
    └── utils.c
```
## 🛠️Tech Stack
- C (C11)
- GCC / Clang
- Make
- MSYS2 / MinGW-w64 (for Windows builds)
- Standard library only — no external dependencies
## 🚀Run Locally

1. Clone the repository
```bash
git clone https://github.com/NirajPujari/IQEQSQ
cd IQEQSQ
```

2. Install a compiler
- Windows (recommended): MSYS2
    ```bash
    pacman -Syu
    pacman -S --needed base-devel mingw-w64-x86_64-toolchain
    ```
Open MSYS2 MinGW 64-bit shell before building.
- Linux
    ```bash
    sudo apt install build-essential
    ```

- macOs
    ```bash
    xcode-select --install
    ```

3. Build the project
```bash
make
```

4. Run the app
```bash
./IQEQSQ
```

## 📖About the Project / Details

This project transforms traditional IQ, EQ, and SQ questionnaires into a **single interactive console test suite**.

The purpose is:
- To practice modular C programming
- To use safe and portable input/output handling
- To demonstrate project structuring with headers, source files, and Makefiles
- To create a clean, maintainable codebase students can extend (new tests, new scoring models, etc.)

Each module (`iq.c`, `eq.c`, `sq.c`) is fully independent and connected through a minimal `main.c` coordinator.
## License
MIT


## Authors

- [@Niraj Pujari](https://github.com/NirajPujari)


# ATSP Solver - Asymmetric Traveling Salesman Problem

This repository contains a C++ implementation of algorithms designed to study and solve the **Asymmetric Traveling Salesman Problem (ATSP)**. The project was developed with a focus on high-performance computing, clean object-oriented design, and efficient memory management.

## Key Features

* **Algorithmic Research**: Specifically designed for studying various approaches to the ATSP, including Brute Force, random, greedy algorithms.
* **Interactive Console Menu**: Features an intuitive CLI menu for easy navigation between loading data and running algorithms.
* **Dynamic File Loading**: Users can manually input file paths in the console to load specific `.atsp` instances for testing.
* **Comprehensive Test Data**: Includes a wide variety of standard ATSP instances (e.g., `br17`, `ftv47`, `rbg443`) for benchmarking.

## Technical Highlights

This software serves as a demonstration of advanced C++ programming skills, specifically:

* **Object-Oriented Programming (OOP)**: Clear separation of concerns using classes like `MapData`, `BruteForce`, `Menu`.
* **Dynamic Memory Management**: Manual handling of memory allocation for complex data structures to ensure efficiency and prevent leaks.
* **Custom Data Structures**: Definition and implementation of specialized structures optimized for representing asymmetric distance matrices and paths.

## Project Structure

* `src/`: Implementation files (.cpp).
* `include/`: Header files (.h).
* `bin/`: Compiled executable.
* `obj/`: Object files generated during compilation.

## Getting Started

### Prerequisites
* GCC Compiler (g++)
* Make

### Compilation
To build the project, simply run the following command in the root directory:
```bash
make
```bash
make

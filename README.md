# Particle Detector Simulation

This program simulates a particle detector system. It creates a variety of particles, including electrons, muons, taus, and their corresponding antiparticles. These particles are then passed through three types of detectors: a tracker, a calorimeter, and a muon chamber. Each detector checks if it can detect the particle based on its type. After all particles have been processed, the detectors are turned off and a summary of the detected particles is printed.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need a C++ compiler that supports C++17. The code has been tested with GCC 11.

### Compiling

1. Open a terminal in the project directory.
2. Compile the program using the following command:

```bash
g++ -std=c++17 assignment-3.cpp -o assignment-3

```

### Running

After compiling the program, you can run it using the following command:

```bash
./assignment-3
```

## Code Structure

The code consists of two classes, `particle` and `detector`, and a main function that drives the simulation.

### `particle` Class

The `particle` class represents a particle that can be detected by the detectors. It has methods for printing data and flipping to an antiparticle.

### `detector` Class

The `detector` class represents a detector that can detect different types of particles. It has methods for printing its status and detecting a particle.

### Main Function

The main function creates a variety of particles and three types of detectors. It then passes each particle through each detector, prints the status of each detector, and finally prints a summary of the detected particles.

## Built With

* GCC - The GNU Compiler Collection

## Authors

* Vadan Khan - Particle Detector (OOP) - [VadanKhan](https://github.com/VadanKhan)


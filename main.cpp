/**
# Particle Detector Simulation

This program simulates a particle detector system. It creates a variety of particles,
including electrons, muons, taus, and their corresponding antiparticles. These particles
are then passed through three types of detectors: a tracker, a calorimeter, and a muon
chamber. Each detector checks if it can detect the particle based on its type. After all
particles have been processed, the detectors are turned off and a summary of the detected
particles is printed.

## Code Structure

The code consists of two classes, `particle` and `detector`, and a main function that
drives the simulation.

### `particle` Class

The `particle` class represents a particle that can be detected by the detectors. It has
methods for printing data and flipping to an antiparticle.

### `detector` Class

The `detector` class represents a detector that can detect different types of particles.
It has methods for printing its status and detecting a particle.

### Main Function

The main function creates a variety of particles and three types of detectors. It then
passes each particle through each detector, prints the status of each detector, and finally
prints a summary of the detected particles.

## Authors

* 10823198 - Particle Detector (OOP) - [VadanKhan](https://github.com/VadanKhan%29)
*/


#include "detector.h"
#include "particle.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using std::string;

// PARTICLE METHODS
// Implementation of print_data function goes here
void particle::print_data() const
{
  std::cout.precision(3); // 2 significant figures
  std::cout << "Particle: [type,m,c,v,Beta] = [" << type << "," << invariant_mass << "," << charge
            << "," << velocity << "," << beta << "]" << std::endl;
  return;
}

// Implementation of flipping to antiparticle
void particle::charge_conjugate()
{
  charge = -charge;
  type = "anti-" + type;
}

// DETECTOR METHODS
void detector::print_status() const
{
  std::string type_full;
  if (detector_type == "tr")
    type_full = "tracker";
  else if (detector_type == "cr")
    type_full = "calorimeter";
  else if (detector_type == "mc")
    type_full = "muon chamber";

  std::cout << "Detector type: " << type_full << ", status: " << (status ? "On" : "Off")
            << std::endl;
}

int detector::detect_particle(const particle &input_particle)
{
  if (!status)
  {
    return 0;
  }

  std::string type = input_particle.get_type();
  if ((detector_type == "tr" &&
       (type == "e" || type == "anti-e" || type == "mu" || type == "anti-mu")) ||
      (detector_type == "cr" && (type == "e" || type == "anti-e")) ||
      (detector_type == "mc" && (type == "mu" || type == "anti-mu")))
  {
    std::cout << type << " was detected" << std::endl;
    detected_particles++;
    return 1;
  }

  return 0;
}

// Main program
int main()
{
  // Create the following particles:
  // two electrons, four muons, three taus, one antielectron, one antimuon, one antitau
  // Create two electrons and four muons
  std::vector<particle> particles;
  for (int i = 0; i < 2; ++i)
    particles.push_back(particle("e", 100000));
  for (int i = 0; i < 4; ++i)
    particles.push_back(particle("mu", 100000));

  // Create three taus
  for (int i = 0; i < 3; ++i)
    particles.push_back(particle("tau", 100000));

  // Create one antielectron, one antimuon, one antitau
  // Use the charge_conjugate method to make a particle an antiparticle
  particle antielectron("e", 0.5);
  antielectron.charge_conjugate();
  particles.push_back(antielectron);

  particle antimuon("mu", 0.5);
  antimuon.charge_conjugate();
  particles.push_back(antimuon);

  particle antitau("tau", 0.5);
  antitau.charge_conjugate();
  particles.push_back(antitau);

  // Print out the data from all the particles (put them in a vector)
  std::cout << "=================================================" << std::endl;
  std::cout << "Details of particles simulated in each detector: " << std::endl;
  for (const auto &particle : particles)
  {
    particle.print_data();
  }

  // Create the following detectors: a tracker, a calorimeter, a muon chamber
  detector tracker("tr", true);
  detector calorimeter("cr", true);
  detector muon_chamber("mc", true);

  // Pass the list of particles into each detector
  std::cout << "=================================================" << std::endl;
  std::cout << "Pass into Tracker " << std::endl;
  for (const auto &particle : particles)
  {
    tracker.detect_particle(particle);
  };
  std::cout << "=================================================" << std::endl;
  std::cout << "Pass into Calorimeter " << std::endl;
  for (const auto &particle : particles)
  {
    calorimeter.detect_particle(particle);
  };
  std::cout << "=================================================" << std::endl;
  std::cout << "Pass into Muon Chamber " << std::endl;
  for (const auto &particle : particles)
  {
    muon_chamber.detect_particle(particle);
  };

  // turn detectors off
  tracker.set_status(0);
  calorimeter.set_status(0);
  muon_chamber.set_status(0);

  // Print a summary of how many particles were detected
  std::cout << "=================================================" << std::endl;
  std::cout << "Tracker detected " << tracker.get_detected_particles() << " particles" << std::endl;
  std::cout << "Calorimeter detected " << calorimeter.get_detected_particles() << " particles"
            << std::endl;
  std::cout << "Muon Chamber detected " << muon_chamber.get_detected_particles() << " particles"
            << std::endl;
  std::cout << "=================================================" << std::endl;
  return 0;
}

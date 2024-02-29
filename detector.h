#ifndef DETECTOR_H
#define DETECTOR_H

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "particle.h"

// Beginning of detector class
class detector
{
private:
  std::string detector_type; // "tr" for tracker, "cr" for calorimeter, "mc" for muon chamber
  bool status{false};
  int detected_particles{0};

public:
  // Default constructor
  detector() = default;

  // Parameterized constructor
  detector(std::string type, bool detector_status)
  {
    if (type != "tr" && type != "cr" && type != "mc")
    {
      throw std::invalid_argument("Invalid detector type. Must be 'tr', 'cr', or 'mc', which stand for tracker (electrons and muons), calorimeter (electrons) and muon chamber (muons) respectively.");
    }
    detector_type = type;
    status = detector_status;
  }

  // Destructor
  ~detector() {}

  // Getter methods
  std::string get_detector_type() const { return detector_type; }
  bool get_status() const { return status; }
  int get_detected_particles() const { return detected_particles; }

  // Setter methods
  void set_detector_type(const std::string& type)
  {
  if (type != "tr" && type != "cr" && type != "mc")
  {
    throw std::invalid_argument("Invalid detector type. Must be 'tr', 'cr', or 'mc', which stand for tracker (electrons and muons), calorimeter (electrons) and muon chamber (muons) respectively.");
  }
  detector_type = type;
  }
  void set_status(bool s) { status = s; }
  void set_detected_particles(int count) { detected_particles = count; }

  // Method to print the status of the detector
  void print_status() const;

  // Method to detect a particle
  int detect_particle(const particle& p);
};



// Functionalities needed, in addition to constructor/destructor/setters/getters (see slides on BB):
// - write a function that takes a particle
//   and returns a bool and a print-out on whether this type of detector detected the particle
//   depending on the detector/particle combination (see slides on BB)
// - have data members that keep track of how many particles were detected by this particular
// detector,
//   and of which type
// - write a function (accessor) that prints how many particles passed through this detector

// End of detector class

#endif

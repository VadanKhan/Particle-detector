#ifndef PARTICLE_H
#define PARTICLE_H


#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>


// Beginning of particle class
class particle
{
  const double LIGHT_SPEED = 2.99792458e8; // ms^-1
  const double ELECTRON_MASS = 0.51099;      // MeV
  const double MUON_MASS = 105.66;         // MeV
  const double TAU_MASS = 1776.9;         // MeV, there is higher uncertainty as much rarer
  const int LEPTON_CHARGE = -1;            // "e" (elementary charge)

private:
  std::string type{"Ghost"};
  double invariant_mass{0.0}; // in MeV
  int charge{0};              // in "e" (elementary charge)
  double velocity{0.0};       // in ms^-1
  double beta{0.0};           // v/c

public:
  // Default constructor
  particle() = default;

  // Parameterized constructor
  particle(std::string particle_type, double particle_velocity)
      : type{particle_type}, velocity{particle_velocity}
  {
    if (velocity >= LIGHT_SPEED)
    {
      throw std::invalid_argument("Velocity must be less than the speed of light (3E8 ms^-1)");
    }
    beta = velocity / LIGHT_SPEED;

    if (type == "e")
    {
      invariant_mass = ELECTRON_MASS;
      charge = LEPTON_CHARGE;
    }
    else if (type == "mu")
    {
      invariant_mass = MUON_MASS;
      charge = LEPTON_CHARGE;
    }
    else if (type == "tau")
    {
      invariant_mass = TAU_MASS;
      charge = LEPTON_CHARGE;
    }
    else
    {
      throw std::invalid_argument("Invalid particle type. Must be 'e', 'mu', or 'tau'.");
    }
  }

  // Destructor
  ~particle() {}

  // Getter methods
  std::string get_type() const { return type; }
  double get_invariant_mass() const { return invariant_mass; }
  int get_charge() const { return charge; }
  double get_velocity() const { return velocity; }
  double get_beta() const { return beta; }

  // Setter methods
  void set_type(const std::string& t)
  {
    if (t != "e" && t != "mu")
    {
      throw std::invalid_argument("Invalid particle type. Must be 'e' or 'mu'.");
    }
    type = t;
  }
  void set_invariant_mass(double m)
  {
    if (m < 0)
    {
      throw std::invalid_argument("Invariant mass must be non-negative.");
    }
    invariant_mass = m;
  }
  void set_charge(int c)
  {
    charge = c;
  }
  void set_velocity(double v)
  {
    if (v >= LIGHT_SPEED)
    {
      throw std::invalid_argument("Velocity must be less than the speed of light (3E8 ms^-1)");
    }
    velocity = v;
    beta = velocity / LIGHT_SPEED;
  }


  // Function to print info about a particle
  void print_data() const;

  // method to change particle to antiparticle
  void charge_conjugate();

};


#endif
/// \file PhysicsList.hh
/// \brief Sets up Penelope physics list

#ifndef CalibrationPhysicsList_h
#define CalibrationPhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "G4EmPenelopePhysics.hh"

namespace Calibration
{
    class PhysicsList : public G4VModularPhysicsList
    {
        public:
        PhysicsList();
    };
}
#endif

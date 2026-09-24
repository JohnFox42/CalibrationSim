#include "PhysicsList.hh"
#include "G4EmPenelopePhysics.hh"

namespace Calibration
{
    PhysicsList::PhysicsList()
    {
        RegisterPhysics(new G4EmPenelopePhysics());
    }
} 

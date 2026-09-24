/// \file PrimaryGeneratorAction.hh
/// \brief Definition of the Calibration::PrimaryGeneratorAction class

#ifndef CalibrationPrimaryGeneratorAction_h
#define CalibrationPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"

class G4ParticleGun;
class G4Event;

namespace Calibration
{
    class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
    {
        public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction() override;
        void GeneratePrimaries(G4Event*) override;
        const G4ParticleGun* GetParticleGun() const { return fParticleGun; }

        private:
        G4ParticleGun* fParticleGun=nullptr;
    };
}

#endif

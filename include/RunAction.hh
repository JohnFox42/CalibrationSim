/// \file RunAction.hh
/// \brief Definition of BasicDetector::RunAction

#ifndef BasicDetectorRunAction_h
#define BasicDetectorRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"

class G4Run;

extern const G4double DetectorRotation;
const double DetectorRotateHold = static_cast<G4double>(DetectorRotation);
namespace Calibration
{
    class RunAction : public G4UserRunAction
    {
        public:
        RunAction();
        ~RunAction() override = default;

        void BeginOfRunAction(const G4Run*) override;
        void EndOfRunAction(const G4Run*) override;
        void IterateGeHitCount();

        private:
        G4Accumulable<G4int> fGeHitCount = 0;
    };
}

#endif

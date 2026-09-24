/// \file RunAction.hh
/// \brief Definition of BasicDetector::RunAction

#ifndef BasicDetectorRunAction_h
#define BasicDetectorRunAction_h 1

#include "G4UserRunAction.hh"

class G4Run;

namespace Calibration
{
    class RunAction : public G4UserRunAction
    {
        public:
        RunAction();
        ~RunAction() override = default;

        void BeginOfRunAction(const G4Run*) override;
        void EndOfRunAction(const G4Run*) override;
    };
}

#endif

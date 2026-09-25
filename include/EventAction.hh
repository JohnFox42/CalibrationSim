/// \file EventAction.hh
/// \brief 

#ifndef BasicDetectorEventAction_h
#define BasicDetectorEventaction_h 1

#include "G4UserEventAction.hh"
#include "RunAction.hh"

namespace Calibration
{
    class RunAction;

    class EventAction : public G4UserEventAction
    {
        public:
        EventAction(RunAction* runAction);
        ~EventAction() override=default;

        void BeginOfEventAction(const G4Event*) override;
        void EndOfEventAction(const G4Event*) override;
        void UpdateRecorded(const G4bool);
        G4bool ReturnRecorded()const{return Recorded;}
        private:
        RunAction* fRunAction = nullptr;
        G4bool Recorded = false;
    };
}

#endif 

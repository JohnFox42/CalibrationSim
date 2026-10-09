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
        void AddEdep(const G4double);
        void AddSiEdep(const G4double);
        private:
        RunAction* fRunAction = nullptr;
        G4bool Recorded = false;
        G4double GeEdep = 0;
        G4double SiEdep = 0;
    };
}

#endif 

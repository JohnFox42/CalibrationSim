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
        private:
        RunAction* fRunAction = nullptr;
    };
}

#endif 

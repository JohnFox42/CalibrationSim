#include "EventAction.hh"
#include "RunAction.hh"
#include "G4RootAnalysisManager.hh"
#include "G4Event.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4ios.hh"

namespace Calibration
{
    EventAction::EventAction(RunAction* runAction): fRunAction(runAction)
    {
    }

    void EventAction::BeginOfEventAction(const G4Event*)
    {
        Recorded = false;
    }

    void EventAction::UpdateRecorded(const G4bool update)
    {
        Recorded = update;
    }

    void EventAction::EndOfEventAction(const G4Event*)
    {
    }
}

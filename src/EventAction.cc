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
        GeEdep = 0;
    }

    void EventAction::UpdateRecorded(const G4bool update)
    {
        Recorded = update;
    }

    void EventAction::AddEdep(const G4double edep)
    {
        GeEdep += edep;
    }

    void EventAction::EndOfEventAction(const G4Event* event)
    {
        auto AnalysisManager = G4RootAnalysisManager::Instance();
        if (Recorded)
        {
            AnalysisManager->FillH1(0,GeEdep);
        }

        auto eventID = event->GetEventID();
        if (eventID % 100000 == 0)
        {
            G4cout << "Event: " << eventID << G4endl;
        }
    }
}

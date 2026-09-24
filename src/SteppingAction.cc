#include "SteppingAction.hh"
#include "G4ios.hh"
#include "DetectorConstruction.hh"
#include "EventAction.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"
#include "RunAction.hh"
#include "G4RootAnalysisManager.hh"

namespace Calibration
{
    
    SteppingAction::SteppingAction(EventAction* eventAction,RunAction* runAction)
    : fEventAction(eventAction), fRunAction(runAction)
    {
    }

    void SteppingAction::UserSteppingAction(const G4Step* step)
    {

    }
}
    
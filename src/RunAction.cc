#include "G4RootAnalysisManager.hh"
#include "G4Run.hh"
#include "RunAction.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "G4AccumulableManager.hh"

namespace Calibration
{
RunAction::RunAction()
{
    //Register the accumulable managaer and accumulables
    G4AccumulableManager* AccumulableManager = G4AccumulableManager::Instance();
    AccumulableManager->Register(fGeHitCount);
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
    
}

void RunAction::IterateGeHitCount()
{
    ++fGeHitCount;
}

void RunAction::EndOfRunAction(const G4Run* run)
{
    //Merge Accumulables
    G4AccumulableManager* AccumulableManager = G4AccumulableManager::Instance();
    AccumulableManager->Merge();    

    //Parse accumulables
    const G4int TotalGeHitCount = fGeHitCount.GetValue();

    //Output Statistics
    if (IsMaster())
    {
        G4cout << "The total hit count of the Ge detector was: " << TotalGeHitCount << '\n';
        G4double prob = static_cast<G4double>(TotalGeHitCount)/(run->GetNumberOfEvent());
        G4cout << "This is a hit efficiency of: " << prob << '\n';
        G4double stdev = sqrt((prob)*(1-prob)/(run->GetNumberOfEvent()));
        G4cout << "With standard deviation:" << stdev << G4endl;
    }

}
}

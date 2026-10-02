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
    //Creating the analysis manager and registering the root histogram
    auto AnalysisManager = G4RootAnalysisManager::Instance();
    AnalysisManager->SetVerboseLevel(1);
    AnalysisManager->SetDefaultFileType("root");
    AnalysisManager->SetNtupleMerging(true);
    AnalysisManager->CreateH1("GeEdep","Energy Deposited into the Germanium Detector at: "+std::to_string(DetectorRotateHold/deg)+"deg",105,0,420*keV);
}

void RunAction::BeginOfRunAction(const G4Run* run)
{
    auto AnalysisManager = G4RootAnalysisManager::Instance();
    AnalysisManager->OpenFile("CalibrationSpectrum.root");
}

void RunAction::IterateGeHitCount()
{
    ++fGeHitCount;
}

void RunAction::EndOfRunAction(const G4Run* run)
{
    //
    auto AnalysisManager = G4RootAnalysisManager::Instance();
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
    AnalysisManager->Write();
    AnalysisManager->CloseFile();
}
}

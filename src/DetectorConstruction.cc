#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"

namespace Calibration
{
G4VPhysicalVolume* DetectorConstruction::Construct()
{
    ///Defining the world space parameters
    G4double world_hx = 0.5*m;
    G4double world_hy = 0.5*m;
    G4double world_hz = 0.5*m;
    
     //Creating the world space
    G4Box* worldBox = new G4Box("World",world_hx,world_hy,world_hz);
    
    //Creating a vaccum property from NIST
    auto nist = G4NistManager::Instance();
    G4Material* worldMat = nist->FindOrBuildMaterial("G4_Galactic");

    //Creating the world logical volume
    G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox,worldMat,"World");

    //Placing the world volume
    G4VPhysicalVolume* worldPhys = new G4PVPlacement(0,G4ThreeVector(0,0,0),worldLog,"World",nullptr,false,0);

    return worldPhys;
}
}

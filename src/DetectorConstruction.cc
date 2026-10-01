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

    //Defining the silicon detector geometric parameters
    G4double SiInnerRadius = 0.*m;
    G4double SiOuterRadius = 2*cm;
    G4double SiHz = 1.*mm;
    G4double SiStartAngle = 0.*deg;
    G4double SiSpanningAngle = 360.*deg;
    
    //Building the silicon detector
    G4Tubs* SiDetectorTube = new G4Tubs("SiDetector",SiInnerRadius,SiOuterRadius,SiHz,SiStartAngle,SiSpanningAngle);
    
    //Creating Silicon
    G4Material* Si = nist->FindOrBuildMaterial("G4_Si");

    //Creating the logical detector volume and filling with silicon
    G4LogicalVolume* SiDetectorLog = new G4LogicalVolume(SiDetectorTube,Si,"SiDetector");

    //Dimensions for the germanium detector
    G4double GeOuterRadius = 2.*cm;
    G4double GeInnerRadius = 0.*cm; 
    G4double GeHz = 3.5*cm;
    G4double GeStartAngle = 0.*deg;
    G4double GeSpanningAngle = 360.*deg;

    //Building the germanium detector
    G4Tubs* GeDetectorTube = new G4Tubs("GeDetector",GeInnerRadius,GeOuterRadius,GeHz,GeStartAngle,GeSpanningAngle);

    //Creating germanium
    G4Material* Ge = nist->FindOrBuildMaterial("G4_Ge");

    //Creating the logical germanium detector and filling with germanium
    G4LogicalVolume* GeDetectorLog = new G4LogicalVolume(GeDetectorTube,Ge,"GeDetector");

    //Updating the logical pointer
    fGeDetector = GeDetectorLog;

    //Creating the beamline housing
    G4double HouseOuterRadius = 5.11*cm;
    G4double HouseInnerRadius = 5.08*cm;
    G4double HouseHz = 0.1*m;
    G4double HouseStartAngle = 0.*deg;
    G4double HouseSpanningAngle = 360.*deg;

    //Building the beamline housing
    G4Tubs* BeamlineHousing = new G4Tubs("BeamlineHousing",HouseInnerRadius,HouseOuterRadius,HouseHz,HouseStartAngle,HouseSpanningAngle);

    //Creating Aluminum
    G4Material* Al = nist->FindOrBuildMaterial("G4_Al");

    //Creating the logical housing and filling with aluminum
    G4LogicalVolume* BeamlineHousingLog = new G4LogicalVolume(BeamlineHousing,Al,"BeamlineHousing");

    //Creating the housing cap
    G4double HouseCapOuterRadius = 5.11*cm;
    G4double HouseCapInnerRadius = 0.*cm;
    G4double HouseCapHz = 1.5*mm;
    G4double HouseCapStartAngle = 0.*deg;
    G4double HouseCapSpanningAngle = 360.*deg;

    //Building the beamline housing cap
    G4Tubs* BeamlineHousingCap = new G4Tubs("BeamlineHousingCap",HouseCapInnerRadius,HouseCapOuterRadius,HouseCapHz,HouseCapStartAngle,HouseCapSpanningAngle);

    //Creating the logical housing cap and filling with aluminum
    G4LogicalVolume* BeamlineHousingCapLog = new G4LogicalVolume(BeamlineHousingCap,Al,"BeamlineHousingCap");

    //Creating the Ge Housing 
    G4double GeHousingOuterRadius = 2.5*cm;
    G4double GeHousingInnerRadius = 2.2*cm;
    G4double GeHousingHz = 4*cm;
    G4double GeHousingStartAngle = 0*deg;
    G4double GeHousingSpanningAngle = 360*deg;

    //Building the Ge Housing
    G4Tubs* GeHousing = new G4Tubs("GeHousing",GeHousingInnerRadius,GeHousingOuterRadius,GeHousingHz,GeHousingStartAngle,GeHousingSpanningAngle);

    //Creating the logical Ge Housing and filling with aluminum
    G4LogicalVolume* GeHousingLog = new G4LogicalVolume(GeHousing,Al,"GeHousing");

    //Creating the Ge Housing cap
    G4Tubs* GeHousingCap = new G4Tubs("GeHousingCap",0,2.5*cm,1.5*mm,0*deg,360*deg);

    //Creating the logical Ge Housing cap and filling with aluminum
    G4LogicalVolume* GeHousingCapLog = new G4LogicalVolume(GeHousingCap,Al,"GeHousingCap");

    //Placing the world volume
    G4VPhysicalVolume* worldPhys = new G4PVPlacement(0,G4ThreeVector(0,0,0),worldLog,"World",nullptr,false,0);

    //Placing the silicon detector
    G4VPhysicalVolume* SiDetectorPhys = new G4PVPlacement(0,G4ThreeVector(0,0,0),SiDetectorLog,"SiDetector",worldLog,false,0);

    //Placing the germanium detector 
    G4RotationMatrix Rot = G4RotationMatrix();
    Rot.rotateY(30*deg);
    G4VPhysicalVolume* GeDetectorPhys = new G4PVPlacement(G4Transform3D(Rot,G4ThreeVector(9.2975*sin(30*deg)*cm,0,9.2975*cos(30*deg)*cm)),GeDetectorLog,"GeDetector",worldLog,false,0);

    //Placing the Ge housing
    G4VPhysicalVolume* GeHousingPhys = new G4PVPlacement(G4Transform3D(Rot,G4ThreeVector(9.3975*sin(30*deg)*cm,0,9.3975*cos(30*deg)*cm)),GeHousingLog,"GeHousing",worldLog,false,0);
    G4VPhysicalVolume* GeHousingCapPhys = new G4PVPlacement(G4Transform3D(Rot,G4ThreeVector(5.3975*sin(30*deg)*cm,0,5.3975*cos(30*deg)*cm)),GeHousingCapLog,"GeHousingCap",worldLog,false,0); 

    //Placing the beamline housing
    G4VPhysicalVolume* BeamlineHousingPhys = new G4PVPlacement(0,G4ThreeVector(0,0,-8.73*cm),BeamlineHousingLog,"BeamlineHousing",worldLog,false,0);

    //Placing the beamline housing cap
    G4VPhysicalVolume* BeamlineHousingCapPhys = new G4PVPlacement(0,G4ThreeVector(0,0,1.42*cm),BeamlineHousingCapLog,"BeamlineHousingCap",worldLog,false,0);

    return worldPhys;
}
}

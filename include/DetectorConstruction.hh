/// \file DetectorConstruction.hh
/// \brief Definition of Calibration::DetectorConstruction Class
#ifndef CalibrationDetectorConstruction_h
#define CalibrationDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

extern const G4double DetectorRotation;
namespace Calibration
{
class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
    DetectorConstruction()= default;
    ~DetectorConstruction() override = default;

    G4LogicalVolume* GetGeDetector()const {return fGeDetector;}

    G4VPhysicalVolume* Construct() override;

    private:
    G4LogicalVolume* fGeDetector = nullptr;
};
}

#endif

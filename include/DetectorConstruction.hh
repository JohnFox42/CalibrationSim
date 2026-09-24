/// \file DetectorConstruction.hh
/// \brief Definition of Calibration::DetectorConstruction Class
#ifndef CalibrationDetectorConstruction_h
#define CalibrationDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

namespace Calibration
{
class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
    DetectorConstruction()= default;
    ~DetectorConstruction() override = default;

    G4VPhysicalVolume* Construct() override;
};
}

#endif

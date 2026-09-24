/// \file ActionInitialization.hh
/// \brief Definition of Calibration::ActionInitialization()

#ifndef CalibrationActionInitialization_h
#define CalibrationActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

namespace Calibration
{
class ActionInitialization : public G4VUserActionInitialization
{
    public:
    ActionInitialization() = default;
    ~ActionInitialization() override = default;

    void Build() const override;
    void BuildForMaster() const override;
};
}
#endif

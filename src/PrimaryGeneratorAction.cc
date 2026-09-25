#include "PrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "G4UnitsTable.hh"
#include "Randomize.hh"
#include "G4PhysicalConstants.hh"

namespace Calibration
{
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    G4int nofParticles = 1;
    fParticleGun = new G4ParticleGun(nofParticles);

    //yoinking the default particle kinematic
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition* particle = particleTable->FindParticle("gamma");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(400*keV);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0,0,1));
}
PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
    delete fParticleGun;
}
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    //Randomly set the particle position with a 1cm diameter 
    G4double r = rMax*G4UniformRand();
    G4double phi = twopi*G4UniformRand();
    fParticleGun->SetParticlePosition(G4ThreeVector(r*cos(phi),r*sin(phi),-0.4*m));
    fParticleGun->GeneratePrimaryVertex(anEvent);
}
}

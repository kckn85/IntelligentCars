#include "../../IntelligentCars.h"
#include "../../Pawns/Classes/IntCarPawn.h"
#include "../Classes/IntCarController.h"

AIntCarController::AIntCarController()
{
  
}

void AIntCarController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

  MyCar = Cast<AIntCarPawn>(GetControlledPawn());
  if (MyCar != NULL)
  {
    MyCar->MoveForward(1.0f);
  }
}

#pragma once
#include "AIController.h"
#include "../../Pawns/Classes/IntCarPawn.h"
#include "IntCarController.generated.h"

UCLASS(config=game)
class AIntCarController : public AAIController
{
  GENERATED_BODY()

public:
  AIntCarController();

	//~ Begin AActor Interface
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

private:

  AIntCarPawn* MyCar;
};

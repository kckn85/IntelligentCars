#pragma once
#include "GameFramework/WheeledVehicle.h"
#include "IntCarPawn.generated.h"

UCLASS(config=game)
class AIntCarPawn : public AWheeledVehicle
{
  GENERATED_BODY()

    /** Spring arm that will offset the camera */
  UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
  USpringArmComponent* SpringArm;

  /** Camera component that will be our viewpoint */
  UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
  UCameraComponent* Camera;

 public:
  AIntCarPawn();

	// Begin Pawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End Pawn interface

	// Begin Actor interface
	virtual void Tick(float Delta) override;
	virtual void BeginPlay() override;
	// End Actor interface

	/** Handle pressing forwards */
	void MoveForward(float Val);

	/** Handle pressing right */
	void MoveRight(float Val);
	/** Handle handbrake pressed */
	void OnHandbrakePressed();
	/** Handle handbrake released */
	void OnHandbrakeReleased();
	/** Switch between cameras */
	/** Returns SpringArm subobject **/
  
	FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE UCameraComponent* GetCamera() const { return Camera; }
	/** Returns InternalCamera subobject **/
};

#include "../../IntelligentCars.h"
#include "../Classes/IntCarPawn.h"
#include "../Classes/GenCarWheel.h"

AIntCarPawn::AIntCarPawn()
{
  
	// Create a spring arm component for our chase camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 34.0f));
	SpringArm->SetWorldRotation(FRotator(-20.0f, 0.0f, 0.0f));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 125.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->bEnableCameraRotationLag = false;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;

	// Create the chase camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->SetRelativeLocation(FVector(-125.0, 0.0f, 0.0f));
	Camera->SetRelativeRotation(FRotator(10.0f, 0.0f, 0.0f));
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;

	UWheeledVehicleMovementComponent4W* Vehicle4W = CastChecked<UWheeledVehicleMovementComponent4W>(GetVehicleMovement());

	check(Vehicle4W->WheelSetups.Num() == 4);

	// Wheels/Tyres
	// Setup the wheels
	Vehicle4W->WheelSetups[0].WheelClass = UGenCarWheel::StaticClass();
	Vehicle4W->WheelSetups[0].BoneName = FName("PhysWheel_FL");
	Vehicle4W->WheelSetups[0].AdditionalOffset = FVector(0.f, -8.f, 0.f);

	Vehicle4W->WheelSetups[1].WheelClass = UGenCarWheel::StaticClass();
	Vehicle4W->WheelSetups[1].BoneName = FName("PhysWheel_FR");
	Vehicle4W->WheelSetups[1].AdditionalOffset = FVector(0.f, 8.f, 0.f);

	Vehicle4W->WheelSetups[2].WheelClass = UGenCarWheel::StaticClass();
	Vehicle4W->WheelSetups[2].BoneName = FName("PhysWheel_BL");
	Vehicle4W->WheelSetups[2].AdditionalOffset = FVector(0.f, -8.f, 0.f);

	Vehicle4W->WheelSetups[3].WheelClass = UGenCarWheel::StaticClass();
	Vehicle4W->WheelSetups[3].BoneName = FName("PhysWheel_BR");
	Vehicle4W->WheelSetups[3].AdditionalOffset = FVector(0.f, 8.f, 0.f);

}

void AIntCarPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AIntCarPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AIntCarPawn::MoveRight);

	InputComponent->BindAction("Handbrake", IE_Pressed, this, &AIntCarPawn::OnHandbrakePressed);
	InputComponent->BindAction("Handbrake", IE_Released, this, &AIntCarPawn::OnHandbrakeReleased);
}

void AIntCarPawn::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);

}

void AIntCarPawn::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void AIntCarPawn::OnHandbrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void AIntCarPawn::OnHandbrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void AIntCarPawn::Tick(float Delta)
{
	Super::Tick(Delta);
}

void AIntCarPawn::BeginPlay()
{
	Super::BeginPlay();
}

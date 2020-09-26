// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"

// Sets default values
APlayerTank::APlayerTank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// adds static mesh component for material to entity
	body = CreateDefaultSubobject<UStaticMeshComponent>("playertankbody");
	RootComponent = body;

	// adds springarm and camera
	springArm = CreateDefaultSubobject<USpringArmComponent>("playertankspringarm");
	camera = CreateDefaultSubobject<UCameraComponent>("playertankcamera");

	// attaches springarm to body and camera to springarm
	springArm->AttachToComponent(body, FAttachmentTransformRules::KeepWorldTransform);
	camera->AttachToComponent(springArm, FAttachmentTransformRules::KeepWorldTransform);

	// defines starting distance of camera arm
	springArm->TargetArmLength = springArmDistance;
	springArm->SocketOffset = FVector(0.f, 0.f, -45.f);

	MovementComponent = CreateDefaultSubobject<UPlayerTankMovementComponent>("playertankmovementcomponent");
	MovementComponent->UpdatedComponent = RootComponent;

}

// Called when the game starts or when spawned
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// mapping to the input axis (with logging for each)
	PlayerInputComponent->BindAxis("PlayerTankMoveLeftRight", this, &APlayerTank::MoveLeftRight);
	UE_LOG(LogTemp, Log, TEXT("Axis left-right bind function called"));
	PlayerInputComponent->BindAxis("PlayerTankMoveForwardBackward", this, &APlayerTank::MoveForwardBackward);
	UE_LOG(LogTemp, Log, TEXT("Axis forward-backward bind function called"));

}

void APlayerTank::MoveLeftRight(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddInputVector(GetActorRightVector() * (val * MovementScale));
	}

}

void APlayerTank::MoveForwardBackward(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddInputVector(GetActorForwardVector() * (val * MovementScale));
	}

}

UPawnMovementComponent* APlayerTank::GetMovementComponent() const
{
	return MovementComponent;
}

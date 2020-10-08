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


	MovementComponent = CreateDefaultSubobject<UPlayerTankMovementComponent>("playertankmovementcomponent");
	MovementComponent->UpdatedComponent = RootComponent;

	playerStats = CreateDefaultSubobject<UStatsComponent>(TEXT("playerstats"));

}

// Called when the game starts or when spawned
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	// attaches springarm to body and camera to springarm
	springArm->AttachToComponent(body, FAttachmentTransformRules::KeepWorldTransform);
	camera->AttachToComponent(springArm, FAttachmentTransformRules::KeepWorldTransform);

	// defines starting distance of camera arm
	springArm->TargetArmLength = springArmDistance;
	springArm->SocketOffset = FVector(0.f, 0.f, -45.f);



//	global = GetGlobals();
}

// Called every frame
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (TObjectIterator<AGlobals> It; It; ++It)
	{
		if (It->bulletIsSpawnable == 0) {
			this->canFire = 0;
		}
		else {
			this->canFire = 1;
		}
	}
}


// Called to bind functionality to input
void APlayerTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// mapping to the input axis (with logging for each)
//	PlayerInputComponent->BindAxis("PlayerTankMoveLeftRight", this, &APlayerTank::MoveLeftRight);
//	UE_LOG(LogTemp, Log, TEXT("Axis left-right bind function called"));
	PlayerInputComponent->BindAxis("PlayerTankMoveForwardBackward", this, &APlayerTank::MoveForwardBackward);
	UE_LOG(LogTemp, Log, TEXT("Axis forward-backward bind function called"));
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerTank::Fire);
	UE_LOG(LogTemp, Log, TEXT("Fire action bind function called"));

	/* commented as per lower comments - this works very nicely in blueprint but fails in C++ - no rotation commands seem to be accessible in the class heirarchy
	PlayerInputComponent->BindAxis("AimX", this, &APlayerTank::AimX);
	UE_LOG(LogTemp, Log, TEXT("AimX axis bind function called"));
	PlayerInputComponent->BindAxis("AimY", this, &APlayerTank::AimY);
	UE_LOG(LogTemp, Log, TEXT("AimY axis bind function called"));
	*/
}

/* commented after initial tests - perhaps sideways movement can be implemented later after chassis rotation but for now rotation is attached to axis 
void APlayerTank::MoveLeftRight(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddInputVector(GetActorRightVector() * (val * (MovementScale / 2)));
	}

}
*/

void APlayerTank::MoveForwardBackward(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddInputVector(GetActorForwardVector() * (val * MovementScale));
	}

}

void APlayerTank::Fire() {



	// code handled in blueprint event to avoid time sink

}

/* commented out as rotation does no appear to work for pawn class. will try in blueprint to avoid spending more than the 3 hours I have already spent trying to get this to work. (Edit: this works nicely in blueprint... I'm not sure why the class heirarchy had no rotation capabilities.)
void APlayerTank::AimX(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddActorWorldRotation(GetActorRotation() * (val * MovementScale));
	}

}

void APlayerTank::AimY(float val) {

	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent)) {
		MovementComponent->AddInputVector(GetActorRotation() * (val * MovementScale));
	}

}
*/

UPawnMovementComponent* APlayerTank::GetMovementComponent() const
{
	return MovementComponent;
}

/* not being used as objectiterator is now handling it
AGlobals* APlayerTank::GetGlobals() const
{
	if (global) {
		return global;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank.cpp reports globals not initialized"));
	}

	return NULL;

}
*/
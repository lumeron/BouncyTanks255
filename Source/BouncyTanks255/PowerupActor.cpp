// SIT255 Group Project Assignment


#include "PowerupActor.h"

// Sets default values
APowerupActor::APowerupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PowerupMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PowerupMeshComponent"));
	RootComponent = PowerupMeshComponent;

	//RotationComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("PowerupRotationComponent"));
	

}

// Called when the game starts or when spawned
void APowerupActor::BeginPlay()
{
	Super::BeginPlay();

	switch (PowerupType) {
	case 0:
		// 0 is for health powerup
		powerupGeneratedType = "health";
		powerupGeneratedEffect = healEffect;
		break;
/* not yet handled
	case 1:
		// 1 is for shield powerup
		powerupGeneratedType = "shield";
		powerupGeneratedEffect = shieldEffect;
		break;
	case 2:
		// 2 is for damage powerup
		powerupGeneratedType = "damage";
		powerupGeneratedEffect = powerEffect;
		break;
*/
	default:
		// default is a heal powerup
		powerupGeneratedType = "health";
		powerupGeneratedEffect = healEffect;
		break;
	}

	
}

// Called every frame
void APowerupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator RotationSpeed = FRotator(0, 4, 0);
	FQuat QuatRotation = FQuat(RotationSpeed);

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}


// SIT255 Group Project Assignment


#include "EnemyTank.h"

// Sets default values
AEnemyTank::AEnemyTank()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	aiStats = CreateDefaultSubobject<UStatsComponent>(TEXT("aistats"));

}

// Called when the game starts or when spawned
void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyTank::MoveForwardBackward(float val)
{
	return;
}
void AEnemyTank::TurnLeftRight(float val)
{
	return;
}
void AEnemyTank::Fire()
{
	return;
}

AGlobals* AEnemyTank::GetGlobals() const
{
	if (global) {
		return global;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Globals not initialized"));
	}

	return NULL;

}
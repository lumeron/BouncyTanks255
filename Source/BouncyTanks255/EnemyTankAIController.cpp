// SIT255 Group Project Assignment


#include "EnemyTankAIController.h"
AEnemyTankAIController::AEnemyTankAIController() 
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


}

// Called every frame
void AEnemyTankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

//	SetFocus(PlayerPawn);

	MoveToActor(PlayerPawn);
	if (LineOfSightTo(PlayerPawn)) {
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, 100);
	} else {
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}
}



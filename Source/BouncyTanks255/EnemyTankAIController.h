// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "EnemyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCYTANKS255_API AEnemyTankAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyTankAIController();

private:
	APawn* PlayerPawn;

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

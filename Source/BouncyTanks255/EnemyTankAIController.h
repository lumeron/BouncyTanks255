// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Math/RandomStream.h"
#include "StatsComponent.h"
#include "EnemyTank.h"
#include "PowerupActor.h"
#include "BehaviorTree/BlackboardComponent.h"
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
	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehaviorEnemyTank;
//	APawn* PlayerTank;

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Category = "StateHandling", EditAnywhere, BlueprintReadWrite)
		FString controllerState = "default";

	APawn* PlayerTank;
	AEnemyTank* EnemyTank;
};

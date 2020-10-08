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

/* -- DOCO/REFLECTION COMMENT --
 * This class is used to handle and adjust AI behavior, as well as to adjust blackboard/behavior tree states
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

	FVector nearestHeal = FVector(0.f,0.f,0.f);
	bool pendingHeal = true;
	bool *powerupStillAvailable;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// controllerState
	UPROPERTY(Category = "StateHandling", EditAnywhere, BlueprintReadWrite)
		FString controllerState = "default";

	APawn* PlayerTank;
	AEnemyTank* EnemyTank;
};

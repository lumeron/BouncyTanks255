// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PlayerTankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCYTANKS255_API UPlayerTankMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;
};

 // SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "PlayerTankRotationComponent.generated.h"

UCLASS()
class BOUNCYTANKS255_API UPlayerTankRotationComponent : public URotatingMovementComponent
{
	GENERATED_BODY()

public:
	UPlayerTankRotationComponent();
	float pitchVal;
	float yawVal;
	
	/*
	virtual void TickComponent
	(
		float DeltaTime,
		enum ELevelTick TickType,
		FActorComponentTickFunction* ThisTickFunction
	) override;
	*/
};

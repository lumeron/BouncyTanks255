// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsComponent.h"
#include "Globals.h"
#include "EnemyTank.generated.h"

/* -- DOCO/REFLECTION COMMENT --
* This class is used for the AI tank, currently generated to BP_EnemyTankBase
*/

UCLASS()
class BOUNCYTANKS255_API AEnemyTank : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyTank();

private:
	AGlobals* global;

	// stats component to deal with character stats
	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStatsComponent* aiStats;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
//	AGlobals* GetGlobals() const;

	// added current state variable to be passed to AI controller
	UPROPERTY(Category = "StateHandling", EditAnywhere, BlueprintReadWrite)
		FString currentState = "default";

	// added movement speed property
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float MovementScale = 10.f;
	// not actually implemented as movement is now handled in the AI character movement component
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float RotationScale = 0.1f;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// the following three are not used but may be in future
	void MoveForwardBackward(float val);
	void TurnLeftRight(float val);
	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

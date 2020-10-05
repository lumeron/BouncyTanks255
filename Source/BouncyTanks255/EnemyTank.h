// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StatsComponent.h"
#include "Globals.h"
#include "EnemyTank.generated.h"

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
	AGlobals* GetGlobals() const;

	// added dynamic movement speed property
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float MovementScale = 10.f;

	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float RotationScale = 0.1f;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MoveForwardBackward(float val);
	void TurnLeftRight(float val);
	void Fire();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

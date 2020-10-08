// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerTankMovementComponent.h"
#include "StatsComponent.h"
#include "Globals.h"
//#include "PlayerTankRotationComponent.h"
#include "PlayerTank.generated.h"

/* -- DOCO/REFLECTION COMMENT --
 * This class is used for the player's tank, and is implemented for BP_PlayerTank
 */

UCLASS()
class BOUNCYTANKS255_API APlayerTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerTank();

private:
	AGlobals* global;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// overrides springArmDistance default
	float springArmDistance = 250.f;

	//controls player's ability to fire a shot - "globals" singleton keeps a count of current number of player projectiles
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool canFire = 1;

	// variable for base move speed - moved to make it dynamic
	//float MovementScale = 5.f;
	UPlayerTankMovementComponent* MovementComponent;
//	UPlayerTankRotationComponent* RotationComponent;

	FVector2D MovementInput;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

//	AGlobals* GetGlobals() const;

	// lines for the mesh component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* body;
		
	/* 
	* I'm very happy with how this next property worked. Originally I created it in C++ and then it was not working so I reverted to using blueprints - however, after 
	* testing and getting it working in blueprint I re-implemented via C++ using the logic that the blueprints presented
	*/
	// stats component to deal with character stats
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		UStatsComponent* playerStats;

	// lines for the springarm component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* springArm;

	// lines for the camera component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		UCameraComponent* camera;

	// added dynamic movement speed property
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float MovementScale = 10.f;

	// rotation speed
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float RotationScale = 0.1f;

//	void MoveLeftRight(float val);
	void MoveForwardBackward(float val);
	void Fire();

	/* commented due to issues getting rotation to work with pawnmovementcomponent in C++
	void AimX(float val);
	void AimY(float val);
	*/
	virtual UPawnMovementComponent* GetMovementComponent() const override;

};

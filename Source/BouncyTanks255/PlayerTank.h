// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerTankMovementComponent.h"
#include "Globals.h"
//#include "PlayerTankRotationComponent.h"
#include "PlayerTank.generated.h"

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

	AGlobals* GetGlobals() const;

	// lines for the mesh component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* body;

	// lines for the springarm component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* springArm;

	// lines for the camera component
	UPROPERTY(Category = "Components", EditAnywhere, BlueprintReadWrite)
		UCameraComponent* camera;

	// added dynamic movement speed property
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float MovementScale = 10.f;

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

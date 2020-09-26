// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerTankMovementComponent.h"
#include "PlayerTank.generated.h"

UCLASS()
class BOUNCYTANKS255_API APlayerTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// overrides springArmDistance default
	float springArmDistance = 250.f;

	// variable for base move speed - moved to make it dynamic
	//float MovementScale = 5.f;
	UPlayerTankMovementComponent* MovementComponent;

	FVector2D MovementInput;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// lines for the mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* body;

	// lines for the springarm component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* springArm;

	// lines for the camera component
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UCameraComponent* camera;

	// added dynamic movement speed property
	UPROPERTY(Category = "Speed", EditAnywhere, BlueprintReadWrite)
		float MovementScale = 5.f;

	void MoveLeftRight(float val);
	void MoveForwardBackward(float val);

	virtual UPawnMovementComponent* GetMovementComponent() const override;

};

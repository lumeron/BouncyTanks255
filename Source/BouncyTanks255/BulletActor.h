// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Globals.h"
#include "BulletActor.generated.h"

class UProjectileMovementComponent;
UCLASS()
class BOUNCYTANKS255_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

private:
	AGlobals* global;

	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	float currentLifespan;

public:	
	// Called every frame
//	virtual void Tick(float DeltaTime) override;

	virtual void LifeSpanExpired() override;

	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseLifespan = 4.0f;
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseSpeed = 900.0f;
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseDamage = 10.0f;

	AGlobals* GetGlobals() const;
};

// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletActor.generated.h"

UCLASS()
class BOUNCYTANKS255_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(Category = "baselifespan", EditAnywhere, BlueprintReadWrite)
		float baseLifespan = 50.0f;
	UPROPERTY(Category = "basespeed", EditAnywhere, BlueprintReadWrite)
		float baseSpeed = 100.0f;
	UPROPERTY(Category = "basedamage", EditAnywhere, BlueprintReadWrite)
		float baseDamage = 10.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

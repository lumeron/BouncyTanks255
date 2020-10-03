// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Globals.h"
#include "BulletActor.generated.h"

UCLASS()
class BOUNCYTANKS255_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

private:
	AGlobals* global;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(Category = "baselifespan", EditAnywhere, BlueprintReadWrite)
		float baseLifespan = 200.0f;
	UPROPERTY(Category = "basespeed", EditAnywhere, BlueprintReadWrite)
		float baseSpeed = 400.0f;
	UPROPERTY(Category = "basedamage", EditAnywhere, BlueprintReadWrite)
		float baseDamage = 10.0f;

	float currentLifespan;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AGlobals* GetGlobals() const;
};

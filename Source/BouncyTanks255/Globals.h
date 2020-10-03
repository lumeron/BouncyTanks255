// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Globals.generated.h"

UCLASS()
class BOUNCYTANKS255_API AGlobals : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGlobals();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(Category = "GlobalVariable", EditAnywhere, BlueprintReadWrite)
		int timeInSeconds = 0;
	
	UPROPERTY(Category = "BulletSpawnable", EditAnywhere, BlueprintReadWrite)
		bool bulletIsSpawnable;

	int32 bulletCount;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Globals.h"
#include "PowerupActor.generated.h"


UENUM()
namespace EPowerupTypes {
	enum Type {
		IO_HEALTH  UMETA(DisplayName = "Health"),
		IO_SHIELD  UMETA(DisplayName = "Shield"),
		IO_POWER   UMETA(DisplayName = "Damage")
	};
}

UCLASS()
class BOUNCYTANKS255_API APowerupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerupActor();

private:
//	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
//		URotatingMovementComponent* RotationComponent;
	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* PowerupMeshComponent;

	UPROPERTY(Category = "GeneratedPowerupValues", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		FString powerupGeneratedType;
	UPROPERTY(Category = "GeneratedPowerupValues", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float powerupGeneratedEffect;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
		float healEffect = 20.0f;
	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
		float shieldEffect = 40.0f;
	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
		float powerEffect = 10.0f;
	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EPowerupTypes::Type> PowerupType;
	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
		bool powerupAvailable = 0;
	
//	UPROPERTY(Category = "PowerupSettings", EditAnywhere, BlueprintReadWrite)
//		FString baseLifespan = "";

	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

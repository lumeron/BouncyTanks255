// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComponent.generated.h"

/* -- DOCO/REFLECTION COMMENT --
 * This component class is used to handle character (player as well as AI) stats, such as health or shields
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BOUNCYTANKS255_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	/* -- DOCO/REFLECTION COMMENT --
	* Base values are used and edited in editor; current value is initialized later and is referenced if a powerup or bullet affects the owning actor.
	*/
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float baseHealth = 50.0f;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float currentHealth;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float baseShield = 0.0f;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float currentShield;

	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float baseDamage = 0.0f;
	UPROPERTY(Category = "Stats", EditAnywhere, BlueprintReadWrite)
		float currentDamage;
		
};

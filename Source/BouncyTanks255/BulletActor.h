// SIT255 Group Project Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Globals.h"
#include "BulletActor.generated.h"

/* -- DOCO/REFLECTION COMMENT --
* This class is used for the bullet projectile handling, currently generated to BP_Bullet (unused) and BP_Bullet2
*/

class UProjectileMovementComponent;
UCLASS()
class BOUNCYTANKS255_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

private:

	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* ProjectileMeshComponent;

	/* -- DOCO/REFLECTION COMMENT --
	*	DamageType is not used, but I kept it in case of migration to damage type class usage in future
	*/

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
		TSubclassOf<UDamageType> DamageType;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// pointer to globals to reference current bullet count
	AGlobals* globals;

//	float currentLifespan;

public:	
	// Called every frame
//	virtual void Tick(float DeltaTime) override;

	/* -- DOCO/REFLECTION COMMENT --
	* 	Overrides to LifeSpanExpired and Destroyed are to handle the way I implemented the bullet limit. It is not a perfect system, 
	*	and I have already thought of several better ways to handle this, but due to time limitations I have left it in place.
	*/
	virtual void LifeSpanExpired() override;
	virtual void Destroyed() override;

	/* -- DOCO/REFLECTION COMMENT --
	* baseLifespan: used directly to define how many seconds of LifeSpan a bullet has
	* baseSpeed: used to determine bullet speed
	* baseDamage: this is put into currentDamage and then used by classes that are hit by the bullet to determine damage taken
	*/
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseLifespan = 4.0f;
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseSpeed = 1500.0f;
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		float baseDamage = 10.0f;
	UPROPERTY(Category = "Damage", EditAnywhere, BlueprintReadWrite)
		float currentDamage;

	/* -- DOCO/REFLECTION COMMENT --
	* This is a check I added late during implementation to prevent AI bullet count limiting player bullets
	* (ideally this whole system would be replaced so that this is not necessary)
	*/
	UPROPERTY(Category = "BaseValues", EditAnywhere, BlueprintReadWrite)
		bool spawnedByPlayer = false;

//	AGlobals* GetGlobals() const;
};

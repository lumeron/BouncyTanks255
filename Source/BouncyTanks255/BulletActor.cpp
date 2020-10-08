// SIT255 Group Project Assignment


#include "BulletActor.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	/* initialized in header file
	baseLifespan = 50.0f;
	baseSpeed = 100.0f;
	baseDamage = 10.0f;
	*/
//	currentLifespan = baseLifespan;

	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
	RootComponent = ProjectileMeshComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovement->InitialSpeed = baseSpeed;
	ProjectileMovement->MaxSpeed = baseSpeed;
	
	InitialLifeSpan = baseLifespan;
	currentDamage = baseDamage;
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
//	global = GetGlobals();
	
	/* -- DOCO COMMENT --
	* When the bullet comes into play, it checks if it was created by a player and then if it was.
	* I did not use a pointer because the pointer would be used for approximately four seconds, but 
	* in hindsight perhaps I could have passed a pointer from the parent class.
	*/
	if (spawnedByPlayer) {
		for (TObjectIterator<AGlobals> It; It; ++It)
		{
			It->bulletCount++;
		}
	}
}

/* -- DOCO/REFLECTION COMMENT --
* originally I was manually handling lifespan, but then I learned about the actual lifespan variable that uses seconds, so i used that instead (below).
*/
/* tick no longer necessary
// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector MovementThisFrame = this->GetActorForwardVector() * baseSpeed * DeltaTime;
	this->SetActorLocation(this->GetActorLocation() + MovementThisFrame);
	
	if (currentLifespan > 0.0f) {
		currentLifespan -= 1.0f;
	}
	else {
		PrimaryActorTick.bCanEverTick = true;
		for (TObjectIterator<AGlobals> It; It; ++It)
		{
			It->bulletCount--;
		}
		Destroy();
	}

}
	*/

/* -- DOCO/REFLECTION COMMENT --
* It is possible that LifeSpanExpired runs a Destroy of its own, but I just wanted to make sure so I added it manually.
*/
void ABulletActor::LifeSpanExpired()
{
	Destroy();
}

/* -- DOCO/REFLECTION COMMENT --
* Originally I had the following section under Tick (under a lifeSpan manual check), but then I learned about LifeSpanExpired, and then after some testing I realized that
* LifeSpanExpired would not be the only way that bullet gets destroyed, so my global bullet count was blowing out of proportion. Repaired by putting Destroy() in LifeSpanExpired
* as well and then implementing the following Destroyed() override.
*/
void ABulletActor::Destroyed()
{
	if (spawnedByPlayer) {
		for (TObjectIterator<AGlobals> It; It; ++It)
		{
			It->bulletCount--;
		}
	}
}

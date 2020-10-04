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
	currentLifespan = baseLifespan;

	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
	RootComponent = ProjectileMeshComponent;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovement->InitialSpeed = baseSpeed;
	ProjectileMovement->MaxSpeed = baseSpeed;
	
	InitialLifeSpan = baseLifespan;
}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
	
	global = GetGlobals();
	
	for (TObjectIterator<AGlobals> It; It; ++It)
	{
		It->bulletCount++;
	}
}

/* tick no longer necessary
// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector MovementThisFrame = this->GetActorForwardVector() * baseSpeed * DeltaTime;
	this->SetActorLocation(this->GetActorLocation() + MovementThisFrame);
	*/
	/* originally i was manually handling lifespan, but then i learned about the actual lifespan variable that uses seconds, so i used that instead (below).
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

void ABulletActor::LifeSpanExpired()
{
	for (TObjectIterator<AGlobals> It; It; ++It)
	{
		It->bulletCount--;
	}
	Destroy();
}

AGlobals* ABulletActor::GetGlobals() const
{
	if (global) {
		return global;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Globals not initialized"));
	}

	return NULL;

}
// SIT255 Group Project Assignment


#include "Globals.h"

// Sets default values
AGlobals::AGlobals()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGlobals::BeginPlay()
{
	Super::BeginPlay();
	
	if (bulletCount >= 7) {
		bulletCount = 0;
	}
}

// Called every frame
void AGlobals::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bulletCount < 7) {
		if (bulletIsSpawnable == 0) {
			bulletIsSpawnable = 1;
		}
	}
	else {
		bulletIsSpawnable = 0;
	}

	timeInSeconds++;
	// max time for loop is 1500
	if (timeInSeconds > 1500) {
		timeInSeconds = 0;
	}
	if (timeInSeconds < 0) {
		// built-in course-correction for the time component.
		timeInSeconds = 0;
		UE_LOG(LogTemp, Warning, TEXT("timeInSeconds dipped below zero. This is now corrected, but something may need to be resolved."));
	}

}


// SIT255 Group Project Assignment


#include "HealthPoolComponent.h"

/* -- DOCO/REFLECTION COMMENT --
 * This class is not used. I created it and immediately realized I wanted a stat component instead. Have simply not removed yet.
 */

// Sets default values for this component's properties
UHealthPoolComponent::UHealthPoolComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthPoolComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthPoolComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


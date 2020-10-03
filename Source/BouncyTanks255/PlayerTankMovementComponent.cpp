// SIT255 Group Project Assignment


#include "PlayerTankMovementComponent.h"

void UPlayerTankMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
        return;
    }

    FVector MovementThisFrame = ConsumeInputVector() * DeltaTime * 5.f;

    if (!MovementThisFrame.IsNearlyZero()) {
        FHitResult Hit;
        SafeMoveUpdatedComponent(MovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
        
        if (Hit.IsValidBlockingHit())
        {

            SlideAlongSurface(MovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
        }
    }
}
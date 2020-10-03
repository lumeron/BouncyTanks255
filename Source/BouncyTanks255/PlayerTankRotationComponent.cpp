// SIT255 Group Project Assignment


#include "PlayerTankRotationComponent.h"

UPlayerTankRotationComponent::UPlayerTankRotationComponent() {
    pitchVal = 0.f;
    yawVal = 0.f;
}
/*
void UPlayerTankRotationComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!UpdatedComponent || ShouldSkipUpdate(DeltaTime)) {
        return;
    }

    FRotator RotateValues = FRotator(pitchVal, yawVal, 0.f);

    FQuat QuatRotate = FQuat(RotateValues);

    rota

    AddActorLocalRotation(QuatRotate, false, 0, ETeleportType::None);


    if (!RotationThisFrame.IsNearlyZero()) {
        FHitResult Hit;
        SafeMoveUpdatedComponent(RotationThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);
    }
}
*/
// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerAnimInstance.h"


void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaTimeX)
{
    Super::NativeUpdateAnimation(DeltaTimeX);

    FVector rightFoot = GetSkelMeshComponent()->GetBoneLocation(FName("RightFoot"), EBoneSpaces::ComponentSpace);
    FVector leftFoot = GetSkelMeshComponent()->GetBoneLocation(FName("LeftFoot"), EBoneSpaces::ComponentSpace);
    _lastVelocityScale = _velocityScale;
    _velocityScale = FVector(_xVelocity, _yVelocity, _zVelocity).Length() / _maxVelocity;
    _rightLegInFront = rightFoot.Y > leftFoot.Y;

    UE_LOG(LogTemp, Warning, TEXT("VelocityScale: %f") , _velocityScale);
}

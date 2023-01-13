// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputInfo.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/Vector2D.h"
#include "PlayerCharacterMovementComponent.generated.h"


UCLASS()
class MIXAMOARENA_API UPlayerCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:
	UPlayerCharacterMovementComponent();
	UPROPERTY()
	class UPlayerAnimInstance* _anim;

	UPROPERTY()
	class UPlayerCameraComponent* _camera;

	UPROPERTY()
	FAxisInfo _axisInfo;

	const float MAX_ANGLE = 360;
	const float MIN_ANGLE_TO_ROTATE_FIRST = 15;

	UPROPERTY()
	bool _rotationIsSet;

	UPROPERTY()
	FRotator _lastDesireRotation;

	UPROPERTY(EditAnywhere)
	float PlayerRegularMaxSpeed;

	void Move();
	void MoveAnimation();

protected:
	void BeginPlay() override;
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void Configure(UPlayerAnimInstance* anim, UPlayerCameraComponent* camera);
	void AdjustPlayerRotation(float DeltaTime);
	void MoveHorizontal(float input);
	void MoveVertical(float input);
	void Jump();
	bool IsMoving() const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float _rotateAdjustVelocity = 1000;
};

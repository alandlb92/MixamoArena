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
	UPROPERTY()
	class UPlayerAnimInstance* _anim;

	UPROPERTY()
	class UPlayerCameraComponent* _camera;

	UPROPERTY()
	FAxisInfo _axisInfo;


	UPROPERTY()
	bool _rotationIsSet;

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
};

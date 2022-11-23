// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/Vector2D.h"
#include "PlayerCharacterMovementComponent.generated.h"

USTRUCT()
struct MIXAMOARENA_API FInputInfo
{
	GENERATED_BODY()
private:
	float _inputX;
	float _inputY;

public:
	void Clean()
	{
		_inputX = 0;
		_inputY = 0;
	}

	void SetThumbstickLeftX(float input) 
	{
		_inputX = input;
	}
	void SetThumbstickLeftY(float input)
	{
		_inputY = input;
	}

	FVector2D GetThumbstickLeft()
	{
		return FVector2D(_inputX, _inputY);
	}
};

UCLASS()
class MIXAMOARENA_API UPlayerCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	class UPlayerAnimInstance* _anim;
	UPROPERTY()
	FInputInfo _inputInfo;

	UPROPERTY(EditAnywhere)
	float PlayerRegularMaxSpeed;

	void Move();
	void MoveAnimation();

protected:
	void BeginPlay() override;
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void Configure(UPlayerAnimInstance* anim);
	void MoveHorizontal(float input);
	void MoveVertical(float input);
};

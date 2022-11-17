// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class MIXAMOARENA_API UPlayerCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

private:
	class UPlayerAnimInstance* _anim;

public:
	void Configure(UPlayerAnimInstance* anim);
	void MoveHorizontal(float input);
	void MoveVertical(float input);
};

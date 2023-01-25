// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MIXAMOARENA_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _horizontalInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _verticalInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _lastVelocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _velocityScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _maxVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _xVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _yVelocity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	float _zVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	bool _movingInGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Animation Variables")
	bool _rightLegInFront;

	virtual void NativeUpdateAnimation(float DeltaTimeX) override;
};

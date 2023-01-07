// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputInfo.h"
#include "Camera/CameraComponent.h"
#include "PlayerCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class MIXAMOARENA_API UPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
private:
	UPROPERTY()
	FAxisInfo _axisInfo;
	class USpringArmComponent* _springArm;

	void MoveCamera(float DeltaTime); 
	
	UPROPERTY(EditAnywhere)
	float _maxCameraRotationSpeed = 100;

protected:
	UPlayerCameraComponent();
	void BeginPlay() override;
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void Configure(USpringArmComponent* springArm);
	void MoveCameraHorizontal(float input);
	void MoveCameraVertical(float input);
	USpringArmComponent* GetSpringArm();
	
};

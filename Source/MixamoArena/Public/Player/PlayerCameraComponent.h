// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "PlayerCameraComponent.generated.h"

/**
 * 
 */
UCLASS()
class MIXAMOARENA_API UPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
public:
	void MoveCameraHorizontal(float input);
	void MoveCameraVertical(float input);
	
};

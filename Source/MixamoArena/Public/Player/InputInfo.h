// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputInfo.generated.h"

/**
 * 
 */
USTRUCT()
struct MIXAMOARENA_API FAxisInfo
{
	GENERATED_BODY()

private:
	float _axisX;
	float _axisY;

public:
	void Clean()
	{
		_axisX = 0;
		_axisY = 0;
	}

	void SetAxisX(float input)
	{
		_axisX = input;
	}
	void SetAxisY(float input)
	{
		_axisY = input;
	}

	FVector2D GetAxis()
	{
		return FVector2D(_axisX, _axisY);
	}
};

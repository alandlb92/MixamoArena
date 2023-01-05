// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCameraComponent.h"


void UPlayerCameraComponent::MoveCameraHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveCameraHorizontal %f"), input);
}

void UPlayerCameraComponent::MoveCameraVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveCameraVertical %f"), input);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerCharacterMovementComponent.h"
#include "Player/PlayerAnimInstance.h"

void UPlayerCharacterMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	bOrientRotationToMovement = true;
}

void UPlayerCharacterMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move();
	MoveAnimation();

	_axisInfo.Clean();
}

void UPlayerCharacterMovementComponent::Move()
{
	FVector input = FVector(_axisInfo.GetAxis(), 0);
	AddInputVector(input);
}

void UPlayerCharacterMovementComponent::MoveAnimation()
{
	float velocityScale = Velocity.Length() / GetMaxSpeed();
	//UE_LOG(LogTemp, Warning, TEXT("Velocity %f"), Velocity.Length());
	//UE_LOG(LogTemp, Warning, TEXT("MaxSpeed %f"), GetMaxSpeed());
	//UE_LOG(LogTemp, Warning, TEXT("velocityScale %f"), velocityScale);
	_anim->_velocityScale = velocityScale;
}

void UPlayerCharacterMovementComponent::Configure(UPlayerAnimInstance* anim)
{
	_anim = anim;
}

void UPlayerCharacterMovementComponent::MoveHorizontal(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveHorizontal %f"), input);

	_axisInfo.SetAxisY(input);
}


void UPlayerCharacterMovementComponent::MoveVertical(float input)
{
	if (input != 0)
		UE_LOG(LogTemp, Warning, TEXT("MoveVertical %f"), input);

	_axisInfo.SetAxisX(input);
}

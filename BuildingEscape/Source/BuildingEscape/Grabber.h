// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach in CM
	float Reach = 100.0f;

	UPhysicsHandleComponent * PhysicsHandle = nullptr;	
	UInputComponent * InputComponent = nullptr;

	/// Ray-Cast and grab whatever is in reach
	void Grab();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};

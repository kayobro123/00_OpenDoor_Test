// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		// Sets default values for this component's properties
		UOpenDoor();

		// Called when the game starts
		virtual void BeginPlay() override;

		UPROPERTY(BlueprintAssignable)
		FDoorRequest OnOpen;

		UPROPERTY(BlueprintAssignable)
		FDoorRequest OnClose;

	protected:

	private:
		UPROPERTY(EditAnywhere)
		ATriggerVolume * PressurePlate = nullptr;

		// Returns total mass in kgs
		float GetTotalMassOfActorsOnPlate();

		float TriggerMass = 30.0f;

		// The owning door
		AActor * Owner = nullptr;
};

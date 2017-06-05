// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		// Sets default values for this component's properties
		UOpenDoor();

	protected:

		// Called when the game starts
		virtual void BeginPlay() override;

		void OpenDoor();
		void CloseDoor();

	private:
		UPROPERTY(EditAnywhere) 
		float OpenAngle = 90.0f;

		UPROPERTY(EditAnywhere)
		ATriggerVolume * PressurePlate;

		UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 2.0f;

		float LastDoorOpenTime;

		// Returns total mass in kgs
		float GetTotalMassOfActorsOnPlate();

		AActor * Owner; // The owning door
};

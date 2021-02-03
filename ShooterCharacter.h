// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SHIPSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//overriding the virtual method for taking damage 
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser);


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//making a function that is accessable form blueprint for death animation
	UFUNCTION(BlueprintPure) //bluprint pure do more than bleprintcallable
		bool IsDead() const; //const and blueprintPure goes togethe, a pure node is something that doe not have an execution pin, and it effect doesnt not change

	UFUNCTION(BlueprintPure) //bluprint pure do more than bleprintcallable
		float GetHealthPer() const;

	void Shoot();


private:
	void MoveForward(float AxisValue);
	void MoveSide(float AxisValue);
	//setting up independent frame rate controls
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	//void LookUp(float AxisValue);
	//variable to set rotation rates for controls
	UPROPERTY(EditAnyWhere)
		float RotationRate = 25;

	//it will allow to configure actor from the blueprint
	UPROPERTY(EditDefaultsOnly)
		//tsubclass, restrint to take the elemets only from the sub clas of Agun class 
		TSubclassOf<AGun> GunClass;

	UPROPERTY()
		//this is an actual gun
		AGun* Gun;

	//for shooting
	

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health;


};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHIPSHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:
	//loose screen class
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> LoseScreenClass;
	//win screeen class
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> WinScreenClass;
	UPROPERTY(EditAnywhere)
		float RestartDelay = 5.f;
	FTimerHandle RestartTimer;
	
	
	UPROPERTY(EditAnywhere)
	UUserWidget* Hud;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};

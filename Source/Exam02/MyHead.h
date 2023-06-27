// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPart.h"
#include "MyHead.generated.h"

/**
 * 
 */
UCLASS()
class EXAM02_API AMyHead : public AMyPart
{
	GENERATED_BODY()

public:
	AMyHead();

private:
	virtual void BeginPlay() override;

private:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void LeftMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void RightMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void UpMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void DownMove(float _Value);

	UFUNCTION(BlueprintCallable)
		void LeftAction();

	UFUNCTION(BlueprintCallable)
		void RightAction();

	UFUNCTION(BlueprintCallable)
		void UpAction();

	UFUNCTION(BlueprintCallable)
		void DownAction();

};

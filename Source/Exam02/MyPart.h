// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyPart.generated.h"

UCLASS()
class EXAM02_API AMyPart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyPart();
	class AMyGameMode* GetSnakeGameMode();

	AMyPart* GetNext()
	{
		return next;
	}
	
	void SetNext(AMyPart* _Next)
	{
		next = _Next;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	AMyPart* next = nullptr;
};

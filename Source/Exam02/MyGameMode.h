// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class EXAM02_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CreateOutWall(int _Y, int _Z, FVector _TileSize, TSubclassOf<AActor> _WallType);

	FORCEINLINE FVector GetTileSize()
	{
		return TileSize;
	}

	FORCEINLINE FIntVector3 GetCount()
	{
		return TileCount;
	}

	void SetPart(class AActor* _Part);

	void SetPart(int _Y, int _Z, class AActor* _Part);

	bool IsPart(FVector _Pos, FName _Tag);

	bool IsPart(int _Y, int _Z, FName _Tag);

	AActor* GetPart(FVector _Pos, FName _Tag);

	AActor* GetPart(int _Y, int _Z, FName _Tag);

	void CurBodyReset();

	void SpawnHeadBody(class AMyPart* _Part, FVector _PastLoc);

protected:
	void BeginPlay() override;
	void Tick(float _Delta) override;
	
private:
	FVector TileSize;

	FIntVector3 TileCount;

	TArray<TArray<class AActor*>> AllMapActor;

	void AllMapClear();

	AActor* CurBody = nullptr;

	FRandomStream RandomCreate = FRandomStream();

	UPROPERTY(Category = "GameModeValue", EditAnywhere, DisplayName = "Body Object Class")
	TSubclassOf<AActor> BodyType;

	UPROPERTY(Category = "GameModeValue", EditAnywhere, DisplayName = "Body Object Class with Head")
		TSubclassOf<AActor> HeadBodyType;


};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "MyPart.h"

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();
	RandomCreate.GenerateNewSeed();

}

void AMyGameMode::CreateOutWall(int _Y, int _Z, FVector _TileSize, TSubclassOf<AActor> _WallType)
{
	UE_LOG(LogTemp, Log, TEXT("%S(%u)> MapCreate Start"), __FUNCTION__, __LINE__);

	TileCount.Y = _Y;
	TileCount.Z = _Z;

	TileSize = _TileSize;


	AllMapActor.SetNumZeroed(TileCount.Z);
	// Num() => size()
	for (size_t z = 0; z < AllMapActor.Num(); z++)
	{
		AllMapActor[z].SetNum(TileCount.Y);
	}

	for (size_t i = 0; i < TileCount.Y; i++)
	{
		FTransform Trans;
		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(i), 0.0f });
		AActor* SpawnedActor0 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);

		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(i), TileSize.Z * static_cast<float>(TileCount.Z - 1) });
		AActor* SpawnedActor1 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);
	}

	for (size_t i = 1; i < (TileCount.Z-1); i++)
	{
		FTransform Trans;
		Trans.SetLocation({ 0, 0, TileSize.Z * i });
		AActor* SpawnedActor0 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);

		Trans.SetLocation({ 0, TileSize.Y * static_cast<float>(TileCount.Y - 1), TileSize.Z * i });
		AActor* SpawnedActor1 = GetWorld()->SpawnActor<AActor>(_WallType, Trans);
	}
}

void AMyGameMode::SetPart(class AActor* _Part)
{

	FVector Pos = _Part->GetActorLocation();

	int Y = Pos.Y / TileSize.Y;
	int Z = Pos.Z / TileSize.Z;

	SetPart(Y, Z, _Part);

}

void AMyGameMode::SetPart(int _Y, int _Z, class AActor* _Part)
{
	if (0 > _Y)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return;
	}

	if (0 > _Z)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return;
	}

	if (_Y >= TileCount.Y)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (Y >= TileCount.Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return;
	}

	if (_Z >= TileCount.Z)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (Z >= TileCount.Z) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return;
	}

	AllMapActor[_Z][_Y] = _Part;
}

bool AMyGameMode::IsPart(FVector _Pos, FName _Tag)
{
	int Y = _Pos.Y / TileSize.Y;
	int Z = _Pos.Z / TileSize.Z;
	return IsPart(Y, Z, _Tag);
}

bool AMyGameMode::IsPart(int _Y, int _Z, FName _Tag)
{
	if (0 > _Y)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return false;
	}

	if (0 > _Z)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return false;
	}

	if (_Y >= TileCount.Y)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (Y >= TileCount.Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return false;
	}

	if (_Z >= TileCount.Z)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (Z >= TileCount.Z) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return false;
	}

	if (nullptr == AllMapActor[_Z][_Y])
	{
		return false;
	}

	return AllMapActor[_Z][_Y]->ActorHasTag(_Tag);
}

AActor* AMyGameMode::GetPart(FVector _Pos, FName _Tag)
{
	int Y = _Pos.Y / TileSize.Y;
	int Z = _Pos.Z / TileSize.Z;

	return GetPart(Y, Z, _Tag);
}

AActor* AMyGameMode::GetPart(int _Y, int _Z, FName _Tag)
{
	if (0 > _Y)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return nullptr;
	}

	if (0 > _Z)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (0 >= Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return nullptr;
	}

	if (_Y >= TileCount.Y)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (Y >= TileCount.Y) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return nullptr;
	}

	if (_Z >= TileCount.Z)
	{
		UE_LOG(LogTemp, Log, TEXT("%S(%u)> if (Z >= TileCount.Z) [Y : %d][Z : %d]"), __FUNCTION__, __LINE__, _Y, _Z);
		return nullptr;
	}

	if (nullptr == AllMapActor[_Z][_Y])
	{
		return nullptr;
	}

	if (false == AllMapActor[_Z][_Y]->ActorHasTag(_Tag))
	{
		return nullptr;
	}

	return AllMapActor[_Z][_Y];
}

void AMyGameMode::CurBodyReset()
{
	CurBody = nullptr;
}

void AMyGameMode::AllMapClear()
{
	for (size_t z = 0; z < AllMapActor.Num(); z++)
	{
		for (size_t y = 0; y < AllMapActor[z].Num(); y++)
		{
			AllMapActor[z][y] = nullptr;
		}
	}
}

void AMyGameMode::Tick(float _Delta)
{
	Super::Tick(_Delta);

	TArray<AActor*> AllSnakeActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "SnakePart", AllSnakeActor);

	AllMapClear();

	for (size_t i = 0; i < AllSnakeActor.Num(); i++)
	{
		SetPart(AllSnakeActor[i]);
	}
	if (nullptr == BodyType)
	{
		UE_LOG(LogTemp, Error, TEXT("%S(%u)> if (nullptr == BodyType)"), __FUNCTION__, __LINE__);
		return;
	}

	if (nullptr == CurBody && nullptr != BodyType)
	{
		TArray<FIntVector> EmptyPoint;
		for (int z = 0; z < AllMapActor.Num(); z++)
		{
			for (int y = 0; y < AllMapActor[z].Num(); y++)
			{
				if (nullptr != AllMapActor[z][y])
				{
					continue;
				}

				EmptyPoint.Add({ 0, y, z });
			}
		}

		int RandomIndex = RandomCreate.RandRange(0, EmptyPoint.Num() - 1);

		FIntVector PointVector = EmptyPoint[RandomIndex];

		FTransform Trans;

		Trans.SetLocation({ 0.0f, PointVector.Y * TileSize.Y, PointVector.Z * TileSize.Z });


		CurBody = GetWorld()->SpawnActor<AActor>(BodyType, Trans);
	}


}

void AMyGameMode::SpawnHeadBody(AMyPart* _Part, FVector _PastLoc)
{
	if (_Part == nullptr)
	{
		return;
	}

	while (_Part->GetNext() != nullptr)
	{
		_Part = _Part->GetNext();
	}

	FTransform Trans;
	Trans.SetLocation({ 0.0f, _PastLoc.Y, _PastLoc.Z });
	AActor* HeadBody = GetWorld()->SpawnActor<AActor>(HeadBodyType, Trans);
	AMyPart* HeadBody_Cast = Cast<AMyPart>(HeadBody);
	_Part->SetNext(HeadBody_Cast);

}
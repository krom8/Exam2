// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHead.h"
#include "MyGameMode.h"

AMyHead::AMyHead()
{
	// 언리얼에서 프레임마다 Tick을 돌려야 하는 액터는
	// PrimaryActorTick.bCanEverTick = true; 로 만들어줘야 Tick을 돌릴수가 있습니다.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 생성자에서 보통 설정해주는게 일반적인데. 
	// 틱을 돌릴거냐 말거냐
	PrimaryActorTick.bCanEverTick = true;
	// PrimaryActorTick.TickGroup = ETickingGroup::TG_PrePhysics;


}

// Called when the game starts or when spawned
void AMyHead::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyHead::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyHead::LeftMove(float _Value)
{

	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::LeftVector);
}


void AMyHead::RightMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}

	AddActorLocalOffset(FVector::RightVector);
}
void AMyHead::UpMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::UpVector);
}
void AMyHead::DownMove(float _Value)
{
	if (0 == _Value)
	{
		return;
	}
	AddActorLocalOffset(FVector::DownVector);
}

void AMyHead::LeftAction()
{

	FVector MovePos = FVector::LeftVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a wall"));
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "HeadBody"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a body"));
		return;
	}

	AMyPart* Next = GetNext();
	FVector PastLoc = GetActorLocation();
	AddActorLocalOffset(FVector::LeftVector * 100.0f);

	// 여기에 Body가 있는지 확인해야 한다.

	while (Next != nullptr)
	{
		FVector TempLoc = Next->GetActorLocation();
		Next->SetActorLocation(PastLoc);
		PastLoc = TempLoc;
		Next = Next->GetNext();
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
		GetSnakeGameMode()->SpawnHeadBody(this, PastLoc);
	}






}
void AMyHead::RightAction()
{
	FVector MovePos = FVector::RightVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a wall"));
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "HeadBody"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a body"));
		return;
	}

	AMyPart* Next = GetNext();
	FVector PastLoc = GetActorLocation();
	AddActorLocalOffset(FVector::RightVector * 100.0f);

	while (Next != nullptr)
	{
		FVector TempLoc = Next->GetActorLocation();
		Next->SetActorLocation(PastLoc);
		PastLoc = TempLoc;
		Next = Next->GetNext();
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
		GetSnakeGameMode()->SpawnHeadBody(this, PastLoc);
	}

}
void AMyHead::UpAction()
{
	FVector MovePos = FVector::UpVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a wall"));
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "HeadBody"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a body"));
		return;
	}


	AMyPart* Next = GetNext();
	FVector PastLoc = GetActorLocation();
	AddActorLocalOffset(FVector::UpVector * 100.0f);

	while (Next != nullptr)
	{
		FVector TempLoc = Next->GetActorLocation();
		Next->SetActorLocation(PastLoc);
		PastLoc = TempLoc;
		Next = Next->GetNext();
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
		GetSnakeGameMode()->SpawnHeadBody(this, PastLoc);
	}
}
void AMyHead::DownAction()
{
	FVector MovePos = FVector::DownVector * 100.0f;

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "Wall"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a wall"));
		return;
	}

	if (true == GetSnakeGameMode()->IsPart(GetActorLocation() + MovePos, "HeadBody"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Can't Move!"));
		UE_LOG(LogTemp, Error, TEXT("Game Over: There is a body"));
		return;
	}

	// 이동을 하고 나서
	AMyPart* Next = GetNext();
	FVector PastLoc = GetActorLocation();
	AddActorLocalOffset(FVector::DownVector * 100.0f);

	while (Next != nullptr)
	{
		FVector TempLoc = Next->GetActorLocation();
		Next->SetActorLocation(PastLoc);
		PastLoc = TempLoc;
		Next = Next->GetNext();
	}

	// 여기에 Body가 있는지 확인해야 한다.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
		GetSnakeGameMode()->SpawnHeadBody(this, PastLoc);
	}
}
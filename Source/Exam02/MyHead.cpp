// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHead.h"
#include "MyGameMode.h"

AMyHead::AMyHead()
{
	// �𸮾󿡼� �����Ӹ��� Tick�� ������ �ϴ� ���ʹ�
	// PrimaryActorTick.bCanEverTick = true; �� �������� Tick�� �������� �ֽ��ϴ�.

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// �����ڿ��� ���� �������ִ°� �Ϲ����ε�. 
	// ƽ�� �����ų� ���ų�
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.

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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
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

	// �̵��� �ϰ� ����
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

	// ���⿡ Body�� �ִ��� Ȯ���ؾ� �Ѵ�.
	if (true == GetSnakeGameMode()->IsPart(GetActorLocation(), "Body"))
	{
		AActor* Body = GetSnakeGameMode()->GetPart(GetActorLocation(), "Body");
		Body->Destroy();
		GetSnakeGameMode()->CurBodyReset();
		GetSnakeGameMode()->SpawnHeadBody(this, PastLoc);
	}
}
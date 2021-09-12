// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class TUTORIAL_4_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 위치 회전 등의 다른 배치 가능한 컴포넌트의 부모 컴포넌트. 충돌과 같은 물리효과, 렌더링 기능 지원x 가벼워서 계층 구조에서 더미로 활용.
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();

	FVector CurrentVelocity;
	bool bGrowing;

	float InputTime;
};

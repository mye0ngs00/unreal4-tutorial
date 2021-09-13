// Fill out your copyright notice in the Description page of Project Settings.


#include "RevolutionSceneComponent.h"

// Sets default values for this component's properties
URevolutionSceneComponent::URevolutionSceneComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
	UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RevolutionMesh"));
	// 루트가 아닌 누군가의 자식으로 컴포넌트를 추가해야 할 때.
	Mesh->SetupAttachment(this);
	Mesh->SetRelativeLocation(FVector(0.0f, 100.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (MeshAsset.Succeeded())
	{
		Mesh->SetStaticMesh(MeshAsset.Object);
	}
}


// Called when the game starts
void URevolutionSceneComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URevolutionSceneComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FRotator NewRotation = GetComponentRotation();
	NewRotation.Yaw += DeltaTime * 100.0f;
	SetWorldRotation(NewRotation);
}


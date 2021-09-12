// Fill out your copyright notice in the Description page of Project Settings.


#include "CollidingPawnMovementComponent.h"

void UCollidingPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	/*
		PawnOwner: ���� ��Ʈ�� ����
		UpdatedComponent: ����� ������Ʈ
		ShouldSkipUpdate: ������ �Ǵ� ������� Ȯ��
	*/
	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	// ConsumeInputVector: �Էµ� �̵� ����
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		// ��ֹ��� ���� �� �����Ʈ ������Ʈ�� �̵����� �ش�.
		SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		if (Hit.IsValidBlockingHit())
		{
			// �ε��� ��� ������ �ʰ� ǥ���� �ε巴�� �̲�������.
			SlideAlongSurface(DesiredMovementThisFrame, 1.0f - Hit.Time, Hit.Normal, Hit);
		}
	}
}
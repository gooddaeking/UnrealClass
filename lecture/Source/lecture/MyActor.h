// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class LECTURE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// 스태틱 메쉬를 보여주는 부품
	UPROPERTY(VisibleAnywhere)	// 언리얼에서 쓰는 리플렉션
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Hp;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	int32 Mp;

	UPROPERTY(EditAnywhere, Category=BattleStat)
	float RotateSpeed = 30.f;
};

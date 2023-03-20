// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "StaticMeshDescription.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TEXT를 쓰는 이유 : 꼭 같은 환경에서 진행된다는 보장이 없기 때문에 TEXT로 감싸면 빌드 설정으로 해도 문자열 사용 가능
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));

	// 컴포넌트를 추가할 때는 컴포넌트 중에 하나를 RootComponent로 넣어준다. 일반적인 규칙 
	RootComponent = Mesh;

	// 적용할 메쉬 경로 입력(""타입 ''경로), 경로에서 로딩하는 경우 한번만 읽기위해서 static 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if(SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// 시작 // 카테고리, 로깅 수준, 형식, 인자
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);
	AddActorLocalRotation(FRotator(RotateSpeed * DeltaTime, 0.f, 0.f));
}


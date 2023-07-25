// Fill out your copyright notice in the Description page of Project Settings.


#include "EndPosition.h"

// Sets default values
AEndPosition::AEndPosition()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	RootComponent = SceneComponent;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComponent->SetGenerateOverlapEvents(true);
	SphereComponent->SetSphereRadius(0.1);
	SphereComponent->SetupAttachment(SceneComponent);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AEndPosition::OnOverlapEnd);
}

void AEndPosition::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	ABloon* Bloon = Cast<ABloon>(OtherActor);
	if (Bloon) {
		MyGameMode->HP -= Bloon->HP;
		Bloon->Invaded = true; //CALL DESTROY ON BLOON
	}
}

// Called when the game starts or when spawned
void AEndPosition::BeginPlay()
{
	Super::BeginPlay();
	MyGameMode = Cast<ABTDGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

// Called every frame
void AEndPosition::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


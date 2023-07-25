// Fill out your copyright notice in the Description page of Project Settings.


#include "ValidSpawnLocationChecker.h"

// Sets default values
AValidSpawnLocationChecker::AValidSpawnLocationChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComponent->SetupAttachment(SceneComponent);
	SphereComponent->SetGenerateOverlapEvents(true);
	SphereComponent->SetSphereRadius(Radius);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
}

// Called when the game starts or when spawned
void AValidSpawnLocationChecker::BeginPlay()
{
	Super::BeginPlay();
	
}

bool AValidSpawnLocationChecker::isOverlappingDefenderSpawnRadius()
{
	TArray<UPrimitiveComponent*> OverlappedComponents;
	SphereComponent->GetOverlappingComponents(OverlappedComponents);
	for (auto i : OverlappedComponents) {
		USphereComponent* Sphere = Cast<USphereComponent>(i);
		if (Sphere && Sphere->GetName() == FString("Spawn Radius"))
			return true;
	}
	return false;
}

bool AValidSpawnLocationChecker::OnValidTile() {
	TArray<AActor*> OverlappedActors;
	TSubclassOf<AGrass> Filter;
	SphereComponent->GetOverlappingActors(OverlappedActors, Filter);
	for (auto i : OverlappedActors) {
		AGrass* Grass = Cast<AGrass>(i);
		if (Grass)
			return true;
	}
	return false;
}

ADefender* AValidSpawnLocationChecker::GetClickedOnDefender()
{
	TArray<AActor*> OverlappedActors;
	TSubclassOf<ADefender> Filter;
	ADefender* ClosestDefender = nullptr;
	float ShortestDistance = 0;
	SphereComponent->GetOverlappingActors(OverlappedActors, Filter);
	for (auto i : OverlappedActors) {
		ADefender* Defender = Cast<ADefender>(i);
		if (Defender) {
			float Distance = FVector::Distance(GetActorLocation(), Defender->GetActorLocation());
			if (!ClosestDefender) {
				ClosestDefender = Defender;
				ShortestDistance = Distance;
			}
			else if (Distance < ShortestDistance) { //can prob join these if else if into one if
				ClosestDefender = Defender;
				ShortestDistance = Distance;
			}
		}
	}
	return ClosestDefender;
}

// Called every frame
void AValidSpawnLocationChecker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


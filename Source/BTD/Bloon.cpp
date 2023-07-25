// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloon.h"

// Sets default values
ABloon::ABloon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene Component"));
	SetRootComponent(SceneComponent);
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(SceneComponent);
	Box->SetGenerateOverlapEvents(true);
	Box->SetBoxExtent(FVector(0.001, 0.001, 0.08), false);
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh Component"));
	SkeletalMeshComponent->SetupAttachment(SceneComponent);
	SkeletalMeshComponent->SetGenerateOverlapEvents(true);
	SkeletalMeshComponent->SetWorldLocation(FVector(0, 0, 1));
	SkeletalMeshComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SkeletalMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->ProjectileGravityScale = 0;
}

// Called when the game starts or when spawned
void ABloon::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABloon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CheckMove();
	HandleProjectiles();
}

void ABloon::GetDamageTaken(ABloon* Bloon, AWeapon* Weapon) {
	if (Weapon->PhysicalDamage > Bloon->Armor)
		Bloon->HP -= Weapon->PhysicalDamage - Bloon->Armor;
	if (Weapon->MagicDamage > Bloon->MagicResist)
		Bloon->HP -= Weapon->MagicDamage - Bloon->MagicResist;
}

void ABloon::CheckMove() {
	TArray<AActor*> ActorsOverlapped;
	TSubclassOf<ABloonRight> BloonRightOverlapped;
	Box->GetOverlappingActors(ActorsOverlapped, BloonRightOverlapped);
	if (!ActorsOverlapped.IsEmpty())
		ProjectileMovement->SetVelocityInLocalSpace(FVector(Speed, 0, 0));

	TSubclassOf<ABloonLeft> BloonLeftOverlapped;
	Box->GetOverlappingActors(ActorsOverlapped, BloonLeftOverlapped);
	if (!ActorsOverlapped.IsEmpty())
		ProjectileMovement->SetVelocityInLocalSpace(FVector(-Speed, 0, 0));

	TSubclassOf<ABloonBackward> BloonBackwardOverlapped;
	Box->GetOverlappingActors(ActorsOverlapped, BloonBackwardOverlapped);
	if (!ActorsOverlapped.IsEmpty())
		ProjectileMovement->SetVelocityInLocalSpace(FVector(0, -Speed, 0));

	TSubclassOf<ABloonForward> BloonForwardOverlapped;
	Box->GetOverlappingActors(ActorsOverlapped, BloonForwardOverlapped);
	if (!ActorsOverlapped.IsEmpty())
		ProjectileMovement->SetVelocityInLocalSpace(FVector(0, Speed, 0));
}

void ABloon::HandleProjectiles() {
	TArray<AActor*> ActorsOverlapped;
	TSubclassOf<AWeapon> WeaponsOverlapped;
	SkeletalMeshComponent->GetOverlappingActors(ActorsOverlapped, WeaponsOverlapped);
	for (auto i : ActorsOverlapped) {
		AWeapon* Weapon = Cast<AWeapon>(i);
		if (Weapon) {
			GetDamageTaken(this, Weapon);
			AProjectile* Projectile = Cast<AProjectile>(Weapon);
			if (Projectile) {
				--Projectile->Piercing;
				//if (Projectile->Piercing <= 0)//Destroy causes some issues, is it safe to call destroy on another object from another class?
					//Projectile->Destroy();
			}
		}
	}
}

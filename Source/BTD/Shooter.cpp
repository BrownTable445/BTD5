// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter.h"

// Sets default values
AShooter::AShooter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AttackSpeed = 1;
	AttackRange = 7;
	Sphere->SetSphereRadius(AttackRange);
	SpawnRadius->SetSphereRadius(2);
	SkeletalMeshComponent->SetSkeletalMesh(ConstructorHelpers::FObjectFinder<USkeletalMesh>(TEXT("/Script/Engine.SkeletalMesh'/Game/Animations/ShooterAnimation.ShooterAnimation'")).Object);
	SkeletalMeshComponent->SetRelativeLocationAndRotation(FVector(0, 0, 0.5), FRotator(0, 90, 0));
	SkeletalMeshComponent->SetWorldScale3D(FVector(0.005, 0.005, 0.005));
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(SceneComponent);
	Arrow->SetRelativeLocationAndRotation(FVector(-2, 2, 3.5), FRotator(0, 0, 0), false, nullptr, ETeleportType::None);
	Arrow->ArrowSize = 0.1;
	Animation = ConstructorHelpers::FObjectFinder<UAnimationAsset>(TEXT("/Script/Engine.AnimSequence'/Game/Animations/ShooterAnimation_Anim.ShooterAnimation_Anim'")).Object;
	//SkeletalMeshComponent->SetAnimation(ConstructorHelpers::FObjectFinder<UAnimationAsset>(TEXT("/Script/Engine.AnimSequence'/Game/Animations/ShooterAnimation_Anim.ShooterAnimation_Anim'")).Object);
	UUpgradePath* UpgradeAttack = NewObject<UUpgradePath>();

	UpgradeAttack->Upgrades.Add(UpgradeAttack->GetUpgrade(FString(TEXT("Upgrade Attack Level 1")), FString(TEXT("Increases Attack by 1")), 1));
	UpgradeAttack->Upgrades.Add(UpgradeAttack->GetUpgrade(FString(TEXT("Upgrade Attack Level 2")), FString(TEXT("Increases Attack by 2")), 2));
	UpgradeAttack->Upgrades.Add(UpgradeAttack->GetUpgrade(FString(TEXT("Upgrade Attack Level 3")), FString(TEXT("Increases Attack by 4")), 4));

	UpgradePaths.Add(UpgradeAttack);
}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AShooter::ShootProjectile, 1 / AttackSpeed, true);
}

void AShooter::ClearInvalidBloons()
{
	while (!EncounteredBloons.IsEmpty() && !EncounteredBloons[0]) {
		EncounteredBloons.RemoveAt(0);
	}
}

void AShooter::ShootProjectile()
{
	if (!EncounteredBloons.IsEmpty()) {
		

		FActorSpawnParameters SpawnParams;
		FTransform SpawnTransform(Arrow->GetComponentRotation(), Arrow->GetComponentLocation());
		AShooterProjectile* Shot = GetWorld()->SpawnActorDeferred<AShooterProjectile>(AShooterProjectile::StaticClass(), SpawnTransform);
		if (Shot) {
			Shot->ProjectileRange = 100;
			UGameplayStatics::FinishSpawningActor(Shot, SpawnTransform);
		}

	}
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


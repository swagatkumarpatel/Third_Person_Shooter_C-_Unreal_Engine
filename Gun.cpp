
#include "Gun.h"
#include "Components/StaticMeshComponent.h"
//#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "AI.h"
#include "Kismet/GameplayStatics.h"

AGun::AGun()
{
	PrimaryActorTick.bCanEverTick = true;
	GunMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	GunMesh->SetupAttachment(RootComponent);
	
	EffectSocketName = "EffectSocket";
}
void AGun::BeginPlay()
{
	Super::BeginPlay();
	PlayerClass = GetOwner();
	MyCharacter = Cast<ACharacterClass>(PlayerClass);
}

void AGun::Fire()
{
	if (MyCharacter->CombatMode==true && PlayerClass!=nullptr)
	{
		UCameraComponent* CameraRef = PlayerClass->FindComponentByClass<UCameraComponent>();
		FVector StartLocation = CameraRef->GetComponentLocation();
		FRotator Rotation = CameraRef->GetComponentRotation();
		FVector EndLocation = Rotation.Vector() * 2000 + StartLocation;
		FHitResult HitData;
		FCollisionQueryParams QueryParams;
		bool IsHitted=GetWorld()->LineTraceSingleByChannel(HitData, StartLocation, EndLocation, ECC_Visibility, QueryParams);
		if (IsHitted)
		{
			AActor* HitActor = HitData.GetActor();
			UGameplayStatics::ApplyPointDamage(HitActor, 10.0f, Rotation.Vector(), HitData, MyCharacter->GetController(), this, DamageType);
			AAI* HitEnemy = Cast<AAI>(HitActor);
			if (HitEnemy)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect, HitData.ImpactPoint,FRotator::ZeroRotator,FVector(0.5));
				//HitActor->Destroy();
			}
		}
		//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Emerald, false, 2.0f);
		UGameplayStatics::SpawnEmitterAttached(Effect,GunMesh,EffectSocketName);
	}
}

void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


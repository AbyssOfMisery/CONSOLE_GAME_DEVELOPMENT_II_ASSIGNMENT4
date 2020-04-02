// Fill out your copyright notice in the Description page of Project Settings.


#include "TProjectileWeapon.h"
#include "TPSCharacter.h"
#include "Engine/World.h"
#include "Components/SkeletalMeshComponent.h"

void ATProjectileWeapon::Fire()
{
	ATPSCharacter* MyOwner = Cast<ATPSCharacter>(GetOwner());

	if (MyOwner && ammoCount > 0 && MyOwner->GetCurrentWeaponState() == WeaponState::Shooting&&ProjectileClass)
	{
		FVector EyeLoc;
		FRotator EyeRot;
		MyOwner->GetActorEyesViewPoint(EyeLoc, EyeRot);

		FVector Muzzlelocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		//FRotator MuzzleRotation = MeshComp->GetSocketRotation(MuzzleSocketName);

		FActorSpawnParameters SpawnParam;
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(ProjectileClass, Muzzlelocation, EyeRot, SpawnParam);
	
	}

}
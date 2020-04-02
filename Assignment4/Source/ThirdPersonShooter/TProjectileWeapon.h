// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPSWeapon.h"
#include "TProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API ATProjectileWeapon : public ATPSWeapon
{
	GENERATED_BODY()
	
protected:

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire() override;
	UPROPERTY(EditDefaultsOnly,Category = "ProjectileWeapon")
	TSubclassOf<AActor> ProjectileClass;

};

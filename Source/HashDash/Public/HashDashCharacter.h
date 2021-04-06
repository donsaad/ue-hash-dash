
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HashDashCharacter.generated.h"

UCLASS(Blueprintable)
class AHashDashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHashDashCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;
	

	/** Returns HDCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return HDCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	void TakeDamage(float Damage);
protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	/** Player input handlers */
	void MoveRight(float);
	void MoveForward(float);
	void Yaw(float);
	void Attack();
	void HeavyAttack();
	void Dash();

	UPROPERTY(EditDefaultsOnly, Category = "Movement Controls")
	bool bUseMouseRot;
	UPROPERTY(EditDefaultsOnly, Category = "Movement Controls")
	float DashPower;

	// UFUNCTIONSZZZZZZ
	UFUNCTION(BlueprintCallable)
		void OnWeaponBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SetMouseRotationInput();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Health")
	float MaxHealth;


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* HDCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Controls", meta = (AllowPrivateAccess = "true"))
	bool bIsAttacking;

	float DeltaTime;

};


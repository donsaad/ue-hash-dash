
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

protected:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Input handlers for axis */
	void MoveRight(float);
	void MoveForward(float);

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* HDCameraComponent; // HD for HashDash not High Def. :"D

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

};


// Copyright DWC Industries

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	
	AAuraPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	//UPROPERTY() - This is a macro that:
	//Makes the property visible to Unreal's reflection system
	//Allows the property to show up in the editor
	//Enables garbage collection for this property
	//Enables serialization (saving/loading)
	//EditAnywhere - Allows this property to be edited in:
	//The details pane, Blueprint editor, Any property window
	//Category="Input" - Groups this property under an "Input" category in the editor
	UPROPERTY(EditAnywhere,Category="Input");
	//declare a pointer to an Input Mapping Context in Unreal Engine's Enhanced Input System.
	//TObjectPtr<UInputMappingContext>:
	//UInputMappingContext is a class that defines what inputs (keys, buttons, etc.) trigger which Input Actions
	//	TObjectPtr is UE5's smart pointer wrapper (safer than raw pointers)
	//AuraContext - The variable name
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere,Category="Input");
	TObjectPtr<UInputAction> MoveAction;
	//void return type, returns no value
	// Move is the function's name
	// FInputActionValue is an Unreal Engine class that stores input data
	// const means the parameter cannot be modified inside the function
	//& means it's passed by reference (to avoid copying the whole object)
	//InputActionValue - This is just the parameter name
	void Move(const FInputActionValue& InputActionValue);
};

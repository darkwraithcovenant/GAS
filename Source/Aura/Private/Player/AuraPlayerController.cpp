// Copyright DWC Industries


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	// set bReplicates boolean to true. makes it so change replicates to the server in multiplayer. makes sure this is
	//replicated entity 
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//Assert that halts execution if AuraContext is not set.
	check(AuraContext);
	//Set up Subsystem for Input Mode
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem)
	Subsystem-> AddMappingContext(AuraContext, 0);
	//Set up our cursor mode settings. 
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	//As soon as cursor captured into viewport, we will not hide the cursor
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	// to use input mode data we use player controller function set input mode and pass in the input mode data.
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	//Will crash if this cast to InputComponent fails. same as assert. 
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

//AAuraPlayerController - This is a custom PlayerController class
//Move function handles movement input
//const FInputActionValue& InputActionValue - This is the parameter that receives input data from Unreal's Enhanced Input System (the new input system)
//FVector2d InputAxisVector = InputActionValue.Get<FVector2D>() - This line:
//Gets the input value as a 2D vector (x and y coordinates)
//Usually, X represents left/right movement
//Y represents forward/backward movement
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation (0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

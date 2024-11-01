// Copyright DWC Industries

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

//class AURA_API IEnemyInterface:

//AURA_API is a macro for DLL export/import (for your game module)
//I prefix is a naming convention for interfaces in Unreal
//This interface will be used for enemy-related functionality
class AURA_API IEnemyInterface
{
	//GENERATED_BODY():

	//Unreal macro that generates necessary boilerplate code
	//Required for Unreal's reflection sys
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;

};

//Key benefits of using interfaces:
//Decoupling: Code that uses the interface doesn't need to know specific enemy types
//Polymorphism: Different classes can implement the interface differently
//Consistency: Enforces a contract that all enemy classes must follow

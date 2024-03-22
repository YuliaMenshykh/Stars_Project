#include "pch.h"
#include "ecsComponent.h"

static int32_t componentID = 0;

int32_t BaseECSComponent::nextID()
{
	return componentID++;
}

#pragma once

#define Array std::vector


struct BaseECSComponent;
typedef void* EntityHandle;
typedef int32_t(*ECSComponentCreateFunction)(Array<uint8_t>& memory, EntityHandle entity, BaseECSComponent* comp);
typedef void (*ECSComponentFreeFunction)(BaseECSComponent* comp);

struct BaseECSComponent
{
	static int32_t nextID();
	EntityHandle entity = nullptr;
};

template<typename T>
struct ECSComponent : public BaseECSComponent
{
	static const ECSComponentCreateFunction CREATE_FUNCTION;
	static const ECSComponentFreeFunction FREE_FUNCTION;
	static const int32_t ID;
	static const size_t SIZE;
};

template<typename Component>
int32_t ECSComponentCreate(Array<uint8_t>& memory, EntityHandle entity, BaseECSComponent* comp)
{
	int32_t index = memory.size();
	memory.resize(index + Component::SIZE);
	Component* component = new(&memory[index])Component(*(Component*)comp);
	component->entity = entity;
	return index;
} 

template<typename Component>
void ECSComponentFree(BaseECSComponent* comp)
{
	Component* component = (Component*)comp;
	component->~Component();
}

template<typename T>
const int32_t ECSComponent<T>::ID(BaseECSComponent::nextID());

template<typename T>
const size_t ECSComponent<T>::SIZE(sizeof(T));

template<typename T>
const ECSComponentCreateFunction ECSComponent<T>::CREATE_FUNCTION(ECSComponentCreate<T>);

template<typename T>
const ECSComponentFreeFunction ECSComponent<T>::FREE_FUNCTION(ECSComponentFree<T>);

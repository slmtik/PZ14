#pragma once
#include "Item.h"
#include <list>
class ObjectPool
{
	static std::list<Item*> _items;
	ObjectPool() {};
	~ObjectPool();
	ObjectPool(const ObjectPool&) = delete;
	ObjectPool& operator=(ObjectPool&) = delete;
public:
	static ObjectPool& GetInstance();
	static Item* AcquireItem();
	static void ReleaseItem(Item* item);
	static void GetStatus();
};


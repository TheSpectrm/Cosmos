/* ENTITY IMPLEMENTATION */
#pragma once

#include "math/cml.h"
#include "graphics/model.h"

namespace Cosmos
{
	struct CS_API Entity
	{
		Model* BaseModel;
		Cml::Vec3 Position;
		float RotX, RotY, RotZ, Scale;

		Entity() = default;
		Entity(Model* baseModel, Cml::Vec3 position, float rotX, float rotY, float rotZ, float scale)
			: BaseModel(baseModel)
			, Position(position)
			, RotX(rotX)
			, RotY(rotY)
			, RotZ(rotZ)
			, Scale(scale) { }
	};
}
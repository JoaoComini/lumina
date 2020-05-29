#pragma once

#include <ctype.h>

#include "PxPhysicsAPI.h"

namespace lumina {
namespace physics {

    class PhysicsContext
    {
        public:
            PhysicsContext();
            void init();

        private:
            physx::PxDefaultAllocator gAllocator;
            physx::PxDefaultErrorCallback gErrorCallback;
            physx::PxFoundation * gFoundation = NULL;
            physx::PxPhysics * gPhysics	= NULL;
            physx::PxDefaultCpuDispatcher * gDispatcher = NULL;
            physx::PxScene * gScene = NULL;
            physx::PxMaterial * gMaterial = NULL;
            physx::PxPvd * gPvd = NULL;
    };


} // namespace engine
} // namespace lumina

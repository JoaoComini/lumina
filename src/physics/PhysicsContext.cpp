
#include "lumina/physics/PhysicsContext.hpp"

namespace lumina {
namespace physics {

    void PhysicsContext::init()
    {
        gFoundation = PxCreateFoundation(PX_PHYSICS_VERSION, gAllocator, gErrorCallback);

        // gPvd = PxCreatePvd(*gFoundation);
        // physx::PxPvdTransport* transport = physx::PxDefaultPvdSocketTransportCreate("127.0.0.1", 5425, 10);
        // gPvd->connect(*transport, physx::PxPvdInstrumentationFlag::eALL);

        // gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, physx::PxTolerancesScale(), true, gPvd);

        gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, physx::PxTolerancesScale());

        gDispatcher = physx::PxDefaultCpuDispatcherCreate(2);
        physx::PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());

        sceneDesc.gravity = physx::PxVec3(0.0f, -9.81f, 0.0f);
        sceneDesc.cpuDispatcher	= gDispatcher;
        sceneDesc.filterShader	= physx::PxDefaultSimulationFilterShader;

        gScene = gPhysics->createScene(sceneDesc);
    }

} // namespace physics
} // namespace lumina


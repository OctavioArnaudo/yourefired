import unreal
import c_spawner

def spawn_door_controller(name="DoorController", position=(0, 1500, 100)):
    unreal.log("[Controller:Door] Spawning office door component...")
    return c_spawner.spawn_actor(name, "/Script/YoureFired.OfficeDoor", position, scale=(1.5, 0.3, 2.0))

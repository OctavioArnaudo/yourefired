import unreal
import c_spawner

def spawn_player_controller(name="PlayerController", position=(0, -1200, 100)):
    unreal.log("[Controller:Player] Spawning player character component...")
    return c_spawner.spawn_actor(name, "/Script/YoureFired.WorkerCharacter", position)

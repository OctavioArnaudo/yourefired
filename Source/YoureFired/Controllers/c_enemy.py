import unreal
from Builders import c_spawner

def spawn_enemy_controller(name="EnemyController", class_path="/Script/YoureFired.CoworkerEnemy", position=(0, 0, 75)):
    unreal.log("[Controller:Enemy] Spawning enemy component...")
    return c_spawner.spawn_actor(name, class_path, position)

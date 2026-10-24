import unreal
import c_spawner

def spawn_weapon_controller(name="WeaponController", position=(-300, -800, 50)):
    unreal.log("[Controller:Weapon] Spawning weapon component...")
    return c_spawner.spawn_actor(name, "/Script/YoureFired.WeaponBase", position)

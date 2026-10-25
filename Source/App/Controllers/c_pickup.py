import unreal
import c_spawner

def spawn_pickup_controller(name="PickupController", class_path="/Script/YoureFired.CoffeePickup", position=(0, 0, 60)):
    unreal.log("[Controller:Pickup] Spawning pickup component...")
    return c_spawner.spawn_actor(name, class_path, position)

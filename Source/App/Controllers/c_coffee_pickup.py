# ============================================================
# YOU'RE FIRED - Controller : CoffeePickup
# ============================================================
import unreal
import c_actor_spawner

def handle_coffee_pickup_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para CoffeePickup."""
    unreal.log("[Controller:CoffeePickup] Ejecutando lógica de control para CoffeePickup.")
    return c_actor_spawner.spawn_actor("CoffeePickup", "/Script/App.CoffeePickup", location)

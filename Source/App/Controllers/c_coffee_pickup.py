# ============================================================
# YOU'RE FIRED - Controller: Coffee Pickup Logic
# ============================================================
import unreal
import c_actor_spawner

def spawn_coffee_pickup(name="CoffeeItem", position=(300, -800, 60)):
    """Controller: Spawnea el ítem de café interactuable en la oficina."""
    unreal.log("[Controller:CoffeePickup] Spawning coffee pickup item...")
    return c_actor_spawner.spawn_actor(name, "/Script/App.CoffeePickup", position)

def on_coffee_collected(player_actor, coffee_actor):
    """Controller: Lógica ejecutada al recolectar el café (restaura energía / velocidad al jugador)."""
    unreal.log(f"[Controller:CoffeePickup] ¡Café recolectado por {player_actor.get_actor_label() if player_actor else 'Jugador'}! Energía restaurada.")
    if coffee_actor and coffee_actor.is_valid():
        coffee_actor.destroy_actor()
    return True

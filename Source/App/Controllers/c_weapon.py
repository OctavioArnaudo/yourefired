# ============================================================
# YOU'RE FIRED - Controller : Weapon
# ============================================================
import unreal
import c_actor_spawner

def handle_weapon_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para Weapon."""
    unreal.log("[Controller:Weapon] Ejecutando lógica de control para Weapon.")
    return c_actor_spawner.spawn_actor("Weapon", "/Script/App.Weapon", location)

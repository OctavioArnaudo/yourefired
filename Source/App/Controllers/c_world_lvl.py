# ============================================================
# YOU'RE FIRED - Controller : WorldLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_world_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para WorldLvl."""
    unreal.log("[Controller:WorldLvl] Ejecutando lógica de control para WorldLvl.")
    return c_actor_spawner.spawn_actor("WorldLvl", "/Script/App.WorldLvl", location)

# ============================================================
# YOU'RE FIRED - Controller : Placeholder
# ============================================================
import unreal
import c_actor_spawner

def handle_placeholder_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para Placeholder."""
    unreal.log("[Controller:Placeholder] Ejecutando lógica de control para Placeholder.")
    return c_actor_spawner.spawn_actor("Placeholder", "/Script/App.Placeholder", location)

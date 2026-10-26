# ============================================================
# YOU'RE FIRED - Controller : Gm
# ============================================================
import unreal
import c_actor_spawner

def handle_gm_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para Gm."""
    unreal.log("[Controller:Gm] Ejecutando lógica de control para Gm.")
    return c_actor_spawner.spawn_actor("Gm", "/Script/App.Gm", location)

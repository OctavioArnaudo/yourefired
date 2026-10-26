# ============================================================
# YOU'RE FIRED - Controller : UaLoader
# ============================================================
import unreal
import c_actor_spawner

def handle_ua_loader_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para UaLoader."""
    unreal.log("[Controller:UaLoader] Ejecutando lógica de control para UaLoader.")
    return c_actor_spawner.spawn_actor("UaLoader", "/Script/App.UaLoader", location)

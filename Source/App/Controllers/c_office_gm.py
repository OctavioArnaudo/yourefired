# ============================================================
# YOU'RE FIRED - Controller : OfficeGm
# ============================================================
import unreal
import c_actor_spawner

def handle_office_gm_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para OfficeGm."""
    unreal.log("[Controller:OfficeGm] Ejecutando lógica de control para OfficeGm.")
    return c_actor_spawner.spawn_actor("OfficeGm", "/Script/App.OfficeGm", location)

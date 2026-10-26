# ============================================================
# YOU'RE FIRED - Controller : OfficeGs
# ============================================================
import unreal
import c_actor_spawner

def handle_office_gs_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para OfficeGs."""
    unreal.log("[Controller:OfficeGs] Ejecutando lógica de control para OfficeGs.")
    return c_actor_spawner.spawn_actor("OfficeGs", "/Script/App.OfficeGs", location)

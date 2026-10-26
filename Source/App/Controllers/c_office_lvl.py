# ============================================================
# YOU'RE FIRED - Controller : OfficeLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_office_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para OfficeLvl."""
    unreal.log("[Controller:OfficeLvl] Ejecutando lógica de control para OfficeLvl.")
    return c_actor_spawner.spawn_actor("OfficeLvl", "/Script/App.OfficeLvl", location)

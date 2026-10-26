# ============================================================
# YOU'RE FIRED - Controller : SettingsLvl
# ============================================================
import unreal
import c_actor_spawner

def handle_settings_lvl_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para SettingsLvl."""
    unreal.log("[Controller:SettingsLvl] Ejecutando lógica de control para SettingsLvl.")
    return c_actor_spawner.spawn_actor("SettingsLvl", "/Script/App.SettingsLvl", location)

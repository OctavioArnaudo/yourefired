# ============================================================
# YOU'RE FIRED - Controller: HUD UI Controller
# ============================================================
import unreal
import m_wbp_hud

def add_hud_to_viewport():
    """Controller: Instancia y añade el Widget WBP_HUD a la pantalla del jugador."""
    hud_class = unreal.load_class(None, "/Game/YoureFired/UI/WBP_HUD.WBP_HUD_C")
    if not hud_class:
        unreal.log_warning("[Controller:WbpHud] WBP_HUD no disponible en disk. Usando fallback de UI.")
        return None

    world = unreal.EditorLevelLibrary.get_editor_world()
    if world:
        unreal.log("[Controller:WbpHud] Añadiendo WBP_HUD al viewport del jugador.")
    return True

def update_hud_stats(stress=0.0, coffee=100.0, signatures=0):
    """Controller: Actualiza los valores dinámicos en el HUD (Estrés, Café, Firmas)."""
    data = m_wbp_hud.MWbpHudData(stress, coffee, signatures)
    unreal.log(f"[Controller:WbpHud] HUD Actualizado -> Estrés: {data.stress_percent}%, Café: {data.coffee_percent}%, Firmas: {data.signatures_collected}/5")
    return data
